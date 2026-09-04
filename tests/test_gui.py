"""Unit tests for the GUI support modules (no display or device required)."""
from __future__ import annotations

import os
import sys
import tempfile
from pathlib import Path
from unittest import mock

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))

from huntsman_updater import constants as C  # noqa: E402
from huntsman_updater import firmware, status  # noqa: E402
from huntsman_updater import gui  # noqa: E402
from huntsman_updater import elevate  # noqa: E402


class _FakeFile:
    def __init__(self, content):
        self._content = content

    def read(self):
        return self._content

    def __enter__(self):
        return self

    def __exit__(self, *args):
        return False


def _patch_sysfs(devices: dict[str, tuple[str, str]]):
    """Patch ``status.detect_mode``'s sysfs reads.

    ``devices`` maps a device directory name to ``(idVendor, idProduct)``.
    """
    def isdir(path):
        return path == "/sys/bus/usb/devices"

    def listdir(path):
        return list(devices)

    def open_(path, *args, **kwargs):
        parts = str(path).rstrip("/").split("/")
        field, dname = parts[-1], parts[-2]
        if dname in devices:
            value = {"idVendor": devices[dname][0],
                     "idProduct": devices[dname][1]}.get(field)
            if value is not None:
                return _FakeFile(value)
        raise OSError(f"no such entry: {path}")

    return (mock.patch.object(status.os.path, "isdir", isdir),
            mock.patch.object(status.os, "listdir", listdir),
            mock.patch("builtins.open", open_))


def test_validate_app_image():
    assert firmware.validate_app_image(bytes(C.APP_IMAGE_SIZE)) == \
        bytes(C.APP_IMAGE_SIZE)
    try:
        firmware.validate_app_image(b"short")
    except ValueError:
        pass
    else:
        raise AssertionError("expected ValueError for short app image")


def test_validate_flash_image():
    assert firmware.validate_flash_image(bytes(C.FLASH_IMAGE_SIZE)) == \
        bytes(C.FLASH_IMAGE_SIZE)
    try:
        firmware.validate_flash_image(b"short")
    except ValueError:
        pass
    else:
        raise AssertionError("expected ValueError for short flash image")


def test_device_status_formatting():
    s = status.DeviceStatus(mode=status.MODE_APP, version=b"\x02\x01")
    assert s.version_str == "2.1"
    assert "02B0" in s.mode_label

    b = status.DeviceStatus(mode=status.MODE_BOOTLOADER)
    assert "110E" in b.mode_label
    assert b.version_str == ""

    n = status.DeviceStatus(mode=status.MODE_NONE)
    assert n.mode_label == "Not detected"


def test_detect_mode():
    # bootloader takes precedence over app when both are present
    patchers = _patch_sysfs({"1-1": ("1532", "110e"), "1-2": ("1532", "02b0")})
    with patchers[0], patchers[1], patchers[2]:
        assert status.detect_mode() == status.MODE_BOOTLOADER

    patchers = _patch_sysfs({"1-1": ("1532", "02b0"), "1-2": ("046d", "c548")})
    with patchers[0], patchers[1], patchers[2]:
        assert status.detect_mode() == status.MODE_APP

    patchers = _patch_sysfs({"1-1": ("046d", "c548")})
    with patchers[0], patchers[1], patchers[2]:
        assert status.detect_mode() == status.MODE_NONE


def test_is_elevated_returns_bool():
    assert elevate.is_elevated() in (True, False)
    if hasattr(os, "geteuid"):
        assert elevate.is_elevated() == (os.geteuid() == 0)


def test_load_firmware_selection_raw_bin():
    with tempfile.TemporaryDirectory() as tmp:
        app = Path(tmp) / "app.bin"
        app.write_bytes(bytes(C.APP_IMAGE_SIZE))
        pkg = gui.load_firmware_selection(str(app))
        assert len(pkg.app_image) == C.APP_IMAGE_SIZE
        assert pkg.flash_image == b""
        assert int(pkg.metadata["VID"], 16) == C.RAZER_VID

        # an optional secondary flash image overrides the (empty) bundle one
        flash = Path(tmp) / "flash.bin"
        flash.write_bytes(bytes(C.FLASH_IMAGE_SIZE))
        pkg = gui.load_firmware_selection(str(app), str(flash))
        assert len(pkg.flash_image) == C.FLASH_IMAGE_SIZE


def test_load_firmware_selection_hex():
    # Build a 128 KiB image out of 16-byte data records, with extended-linear
    # address records every 64 KiB (the Intel HEX 16-bit address field wraps).
    lines = []
    for block in range(C.APP_IMAGE_SIZE // 0x10000):
        rec = bytes([2, 0, 0, 4, (block >> 8) & 0xFF, block & 0xFF])
        rec += bytes([(-sum(rec)) & 0xFF])
        lines.append(":" + rec.hex().upper())
        for off in range(0, 0x10000, 16):
            data = bytes((i & 0xFF) for i in range(off, off + 16))
            record = bytes([16, (off >> 8) & 0xFF, off & 0xFF, 0]) + data
            record += bytes([(-sum(record)) & 0xFF])
            lines.append(":" + record.hex().upper())
    lines.append(":00000001FF")

    with tempfile.TemporaryDirectory() as tmp:
        hexf = Path(tmp) / "app.hex"
        hexf.write_text("\n".join(lines) + "\n")
        pkg = gui.load_firmware_selection(str(hexf))
        assert len(pkg.app_image) == C.APP_IMAGE_SIZE


def test_load_firmware_selection_rejects_bad_size():
    with tempfile.TemporaryDirectory() as tmp:
        app = Path(tmp) / "app.bin"
        app.write_bytes(b"nope")
        try:
            gui.load_firmware_selection(str(app))
        except ValueError:
            pass
        else:
            raise AssertionError("expected ValueError for wrong-size app image")
