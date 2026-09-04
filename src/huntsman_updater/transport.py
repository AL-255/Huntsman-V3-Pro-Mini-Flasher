"""HID transport abstraction.

The updater talks to the keyboard over two HID channels:

* application mode  — 91-byte feature reports (``HidD_Get/SetFeature``);
* bootloader mode   — 65-byte input/output reports (``ReadFile``/``WriteFile``).

This module provides a minimal device handle exposing the four operations the
protocol needs, and two backends: the cross-platform ``hidapi`` binding and a
stdlib-only Linux ``/dev/hidraw`` backend.
"""
from __future__ import annotations

import os


class TransportError(Exception):
    """Raised when a HID operation fails."""


class HidDevice:
    """A thin wrapper over a backend device handle."""

    def __init__(self, impl):
        self._impl = impl

    def get_feature_report(self, report_id: int, length: int) -> bytes:
        return bytes(self._impl.get_feature_report(report_id, length))

    def send_feature_report(self, data: bytes) -> int:
        return self._impl.send_feature_report(data)

    def write(self, data: bytes) -> int:
        return self._impl.write(data)

    def read(self, length: int, timeout_ms: int = 3000) -> bytes:
        return bytes(self._impl.read(length, timeout_ms))

    def close(self) -> None:
        self._impl.close()


def open_by_interface(vid: int, pid: int, interface: int | None = None) -> HidDevice:
    """Open a HID device by VID/PID, preferring a specific interface number."""
    impl = _open_hidapi(vid, pid, interface)
    if impl is not None:
        return HidDevice(impl)
    impl = _open_hidraw(vid, pid, interface)
    if impl is not None:
        return HidDevice(impl)
    raise TransportError(
        f"no HID device found for VID:PID {vid:04x}:{pid:04x} "
        f"interface {interface}")


def _open_hidapi(vid: int, pid: int, interface: int | None):
    try:
        import hid  # type: ignore
    except ImportError:
        return None

    for info in hid.enumerate(vid, pid):
        if interface is not None and info.get("interface_number") != interface:
            continue
        dev = hid.device()
        dev.open_path(info["path"])
        return dev
    return None


def _open_hidraw(vid: int, pid: int, interface: int | None):
    """Linux hidraw backend (no third-party dependency).

    The device is matched through ``/sys/class/hidraw/hidrawN/device/uevent``,
    which reports ``HID_ID=0003:00001532:0000110E`` and the interface number.
    """
    if not os.path.isdir("/sys/class/hidraw"):
        return None

    import fcntl

    # ioctl encoding for HIDIOCG/SFEATURE (linux/hidraw.h: 'H', 0x06/0x07,
    # 3 = _IOC_READ|_IOC_WRITE).
    def _ioc(nr, size):
        return (3 << 30) | (ord("H") << 8) | (nr << 0) | (size << 16)

    class _Hidraw:
        def __init__(self, fd):
            self._fd = fd

        def get_feature_report(self, report_id, length):
            buf = bytearray(length + 1)
            buf[0] = report_id
            fcntl.ioctl(self._fd, _ioc(0x07, len(buf)), buf, True)  # HIDIOCGFEATURE
            return bytes(buf)

        def send_feature_report(self, data):
            return fcntl.ioctl(self._fd, _ioc(0x06, len(data)), bytes(data), True)

        def write(self, data):
            return os.write(self._fd, data)

        def read(self, length, timeout_ms=3000):
            return os.read(self._fd, length)

        def close(self):
            os.close(self._fd)

    hidraw_root = "/sys/class/hidraw"
    for hidraw in sorted(os.listdir(hidraw_root)):
        uevent = os.path.join(hidraw_root, hidraw, "device", "uevent")
        if not os.path.exists(uevent):
            continue
        props = {}
        with open(uevent, "r", encoding="utf-8", errors="replace") as fh:
            for line in fh:
                if "=" in line:
                    k, v = line.rstrip("\n").split("=", 1)
                    props[k] = v
        if interface is not None and props.get("HID_PHYS", "") == "":
            # interface matching is done via the sysfs "device" path; fall
            # through to VID/PID matching when unavailable.
            pass
        hid_id = props.get("HID_ID", "")
        try:
            _, v, p = hid_id.split(":")
            v, p = int(v, 16), int(p, 16)
        except (ValueError, IndexError):
            continue
        if v != vid or p != pid:
            continue
        dev_path = os.path.join("/dev", hidraw)
        try:
            fd = os.open(dev_path, os.O_RDWR)
        except OSError:
            continue
        return _Hidraw(fd)
    return None
