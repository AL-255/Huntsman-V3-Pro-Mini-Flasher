"""USB device enumeration for the advanced-settings device picker.

Reads the Linux sysfs USB tree (``/sys/bus/usb/devices``) and falls back to a
HID-only enumeration through ``hidapi`` on platforms without sysfs.  Each
device carries its interfaces (number + class/subclass/protocol) so the GUI
can present a foldable tree of devices and their capabilities.
"""
from __future__ import annotations

import os
from dataclasses import dataclass, field


def interface_class_name(cls: int) -> str:
    """Human-readable name for a USB interface class code."""
    return {
        0x00: "Per-interface",
        0x01: "Audio",
        0x02: "Communications",
        0x03: "HID",
        0x05: "Physical",
        0x06: "Image",
        0x07: "Printer",
        0x08: "Mass Storage",
        0x09: "Hub",
        0x0A: "CDC Data",
        0x0B: "Smart Card",
        0x0D: "Content Security",
        0x0E: "Video",
        0x0F: "Personal Healthcare",
        0x10: "Audio/Video",
        0xDC: "Diagnostic",
        0xE0: "Wireless",
        0xEF: "Miscellaneous",
        0xFE: "Application Specific",
        0xFF: "Vendor Specific",
    }.get(cls, f"Class {cls:#04x}")


@dataclass
class UsbInterface:
    """One USB interface of a device."""
    number: int
    interface_class: int
    subclass: int
    protocol: int

    @property
    def label(self) -> str:
        name = interface_class_name(self.interface_class)
        return (f"Interface {self.number} — {name} "
                f"({self.interface_class:02X}/{self.subclass:02X}/"
                f"{self.protocol:02X})")


@dataclass
class UsbDevice:
    """One visible USB device and its interfaces."""
    vid: int
    pid: int
    product: str
    manufacturer: str
    bus: int
    dev: int
    interfaces: list[UsbInterface] = field(default_factory=list)

    @property
    def label(self) -> str:
        name = self.product or "Unknown device"
        return f"{self.vid:04X}:{self.pid:04X}  {name}"


def enumerate_usb_devices() -> list[UsbDevice]:
    """Return the visible USB devices (sysfs on Linux, hidapi elsewhere)."""
    sysfs = "/sys/bus/usb/devices"
    if os.path.isdir(sysfs):
        return _enumerate_sysfs(sysfs)
    return _enumerate_hidapi()


# --------------------------------------------------------------------------
# Linux sysfs
# --------------------------------------------------------------------------
def _read(path: str) -> str:
    with open(path, "r", encoding="utf-8", errors="replace") as fh:
        return fh.read().strip()


def _read_optional(path: str) -> str:
    try:
        return _read(path)
    except OSError:
        return ""


def _read_int(path: str, base: int) -> int | None:
    try:
        return int(_read(path), base)
    except (OSError, ValueError):
        return None


def _interfaces(sysfs: str, devname: str) -> list[UsbInterface]:
    interfaces: list[UsbInterface] = []
    prefix = devname + ":"
    for name in sorted(os.listdir(sysfs)):
        if not name.startswith(prefix):
            continue
        base = os.path.join(sysfs, name)
        number = _read_int(os.path.join(base, "bInterfaceNumber"), 16)
        cls = _read_int(os.path.join(base, "bInterfaceClass"), 16)
        sub = _read_int(os.path.join(base, "bInterfaceSubClass"), 16)
        proto = _read_int(os.path.join(base, "bInterfaceProtocol"), 16)
        if number is None or cls is None:
            continue
        interfaces.append(UsbInterface(number, cls, sub or 0, proto or 0))
    return interfaces


def _enumerate_sysfs(sysfs: str) -> list[UsbDevice]:
    devices: list[UsbDevice] = []
    try:
        entries = sorted(os.listdir(sysfs))
    except OSError:
        return devices

    for name in entries:
        base = os.path.join(sysfs, name)
        vid_path = os.path.join(base, "idVendor")
        if not os.path.exists(vid_path):
            continue  # an interface entry (name:config.iface), not a device
        vid = _read_int(vid_path, 16)
        pid = _read_int(os.path.join(base, "idProduct"), 16)
        if vid is None or pid is None:
            continue
        devices.append(UsbDevice(
            vid=vid,
            pid=pid,
            product=_read_optional(os.path.join(base, "product")),
            manufacturer=_read_optional(os.path.join(base, "manufacturer")),
            bus=_read_int(os.path.join(base, "busnum"), 10) or 0,
            dev=_read_int(os.path.join(base, "devnum"), 10) or 0,
            interfaces=_interfaces(sysfs, name),
        ))
    devices.sort(key=lambda d: (d.bus, d.dev, d.vid, d.pid))
    return devices


# --------------------------------------------------------------------------
# hidapi fallback (Windows/macOS; HID devices only)
# --------------------------------------------------------------------------
def _enumerate_hidapi() -> list[UsbDevice]:
    try:
        import hid  # type: ignore
    except ImportError:
        return []

    grouped: dict[tuple[int, int], UsbDevice] = {}
    for info in hid.enumerate(0, 0):
        vid = int(info.get("vendor_id", 0))
        pid = int(info.get("product_id", 0))
        key = (vid, pid)
        if key not in grouped:
            grouped[key] = UsbDevice(
                vid=vid, pid=pid,
                product=info.get("product_string", "") or "",
                manufacturer=info.get("manufacturer_string", "") or "",
                bus=0, dev=0)
        iface = info.get("interface_number")
        if isinstance(iface, int) and iface >= 0:
            grouped[key].interfaces.append(UsbInterface(iface, 0x03, 0, 0))
    return sorted(grouped.values(), key=lambda d: (d.vid, d.pid))
