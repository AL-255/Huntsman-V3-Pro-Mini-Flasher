"""Unit tests for USB device enumeration (``huntsman_updater.usbdev``)."""
from __future__ import annotations

import os
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))

from huntsman_updater import usbdev  # noqa: E402


def _write(path: Path, content: str) -> None:
    path.write_text(content, encoding="ascii")


def _build_sysfs(root: Path) -> None:
    dev = root / "1-1"
    dev.mkdir()
    _write(dev / "idVendor", "1532")
    _write(dev / "idProduct", "02b0")
    _write(dev / "product", "Razer Huntsman V3 Pro Mini")
    _write(dev / "manufacturer", "Razer")
    _write(dev / "busnum", "1")
    _write(dev / "devnum", "21")

    iface3 = root / "1-1:1.3"
    iface3.mkdir()
    _write(iface3 / "bInterfaceNumber", "03")
    _write(iface3 / "bInterfaceClass", "03")
    _write(iface3 / "bInterfaceSubClass", "00")
    _write(iface3 / "bInterfaceProtocol", "00")

    iface5 = root / "1-1:1.5"
    iface5.mkdir()
    _write(iface5 / "bInterfaceNumber", "05")
    _write(iface5 / "bInterfaceClass", "03")
    _write(iface5 / "bInterfaceSubClass", "00")
    _write(iface5 / "bInterfaceProtocol", "00")


def test_interface_class_name():
    assert usbdev.interface_class_name(0x03) == "HID"
    assert usbdev.interface_class_name(0x08) == "Mass Storage"
    assert "0x99" in usbdev.interface_class_name(0x99)


def test_enumerate_sysfs():
    with tempfile.TemporaryDirectory() as tmp:
        root = Path(tmp)
        _build_sysfs(root)
        devices = usbdev._enumerate_sysfs(str(root))

        assert len(devices) == 1
        dev = devices[0]
        assert dev.vid == 0x1532
        assert dev.pid == 0x02B0
        assert dev.product == "Razer Huntsman V3 Pro Mini"
        assert dev.manufacturer == "Razer"
        assert dev.bus == 1
        assert dev.dev == 21
        assert [i.number for i in dev.interfaces] == [3, 5]
        assert all(i.interface_class == 0x03 for i in dev.interfaces)
        assert "1532:02B0" in dev.label
        assert "HID" in dev.interfaces[0].label


def test_enumerate_sysfs_empty():
    with tempfile.TemporaryDirectory() as tmp:
        # no device directories -> empty list
        assert usbdev._enumerate_sysfs(tmp) == []
