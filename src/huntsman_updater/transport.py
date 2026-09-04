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
    impl = _open_usbdevfs(vid, pid, interface)
    if impl is not None:
        return HidDevice(impl)
    raise TransportError(
        f"no HID device found for VID:PID {vid:04x}:{pid:04x} "
        f"interface {interface}")


def _open_usbdevfs(vid: int, pid: int, interface: int | None):
    """Linux usbdevfs backend for driver-less HID interfaces (e.g. the 90-byte
    feature-report config interface, which usbhid refuses to claim).

    It performs HID SET_REPORT/GET_REPORT control transfers directly, and
    treats feature reports as ``report id byte + payload`` exactly like the
    hidapi/hidraw backends.
    """
    if interface is None or not os.path.isdir("/sys/bus/usb/devices"):
        return None

    import ctypes
    import fcntl
    import struct as _struct

    class _CtrlTransfer(ctypes.Structure):
        _fields_ = [
            ("bRequestType", ctypes.c_uint8),
            ("bRequest", ctypes.c_uint8),
            ("wValue", ctypes.c_uint16),
            ("wIndex", ctypes.c_uint16),
            ("wLength", ctypes.c_uint16),
            ("timeout", ctypes.c_uint32),
            ("data", ctypes.c_void_p),
        ]

    _USBDEVFS_CONTROL = ((3 << 30) | (ctypes.sizeof(_CtrlTransfer) << 16)
                         | (ord("U") << 8) | 0)

    # Locate /dev/bus/usb/<bus>/<dev> for the requested VID/PID.
    for devdir in os.listdir("/sys/bus/usb/devices"):
        base = os.path.join("/sys/bus/usb/devices", devdir)
        try:
            v = open(os.path.join(base, "idVendor")).read().strip()
            p = open(os.path.join(base, "idProduct")).read().strip()
        except OSError:
            continue
        if v != f"{vid:04x}" or p != f"{pid:04x}":
            continue
        busnum = int(open(os.path.join(base, "busnum")).read().strip())
        devnum = int(open(os.path.join(base, "devnum")).read().strip())
        node = f"/dev/bus/usb/{busnum:03d}/{devnum:03d}"
        if not os.path.exists(node):
            continue

        class _Usbdevfs:
            def __init__(self, fd):
                self._fd = fd

            def _ctrl(self, reqtype, req, value, index, data):
                buf = ctypes.create_string_buffer(bytes(data), max(len(data), 1))
                t = _CtrlTransfer(reqtype, req, value, index, len(data),
                                  3000, ctypes.cast(buf, ctypes.c_void_p))
                fcntl.ioctl(self._fd, _USBDEVFS_CONTROL, t)
                return buf.raw[:len(data)]

            def get_feature_report(self, report_id, length):
                # strip the report-id byte; the on-wire report is length-1 bytes
                raw = self._ctrl(0xA1, 0x01, 0x0300 | report_id, interface,
                                 b"\x00" * (length - 1))
                return bytes([report_id]) + raw

            def send_feature_report(self, data):
                # data = [report_id][payload]; send payload via SET_REPORT
                return self._ctrl(0x21, 0x09, 0x0300 | data[0], interface, data[1:])

            def write(self, data):
                return 0

            def read(self, length, timeout_ms=3000):
                return b""

            def close(self):
                os.close(self._fd)

        try:
            fd = os.open(node, os.O_RDWR)
        except OSError:
            continue
        return _Usbdevfs(fd)
    return None


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
        hid_id = props.get("HID_ID", "")
        try:
            _, v, p = hid_id.split(":")
            v, p = int(v, 16), int(p, 16)
        except (ValueError, IndexError):
            continue
        if v != vid or p != pid:
            continue
        if interface is not None:
            try:
                with open(os.path.join(hidraw_root, hidraw, "device",
                                       "..", "bInterfaceNumber")) as fh:
                    if int(fh.read().strip()) != interface:
                        continue
            except (OSError, ValueError):
                # interface number unavailable; fall back to VID/PID match
                pass
        dev_path = os.path.join("/dev", hidraw)
        try:
            fd = os.open(dev_path, os.O_RDWR)
        except OSError:
            continue
        return _Hidraw(fd)
    return None
