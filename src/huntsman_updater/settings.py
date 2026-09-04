"""Runtime device-selection settings.

The updater targets the Huntsman V3 Pro Mini (``1532:02B0`` application /
``1532:110E`` bootloader) by default, but the GUI's advanced settings page lets
the user point it at a different VID/PID pair (for example a firmware build
that enumerates with non-default IDs).  :class:`DeviceConfig` carries those
values through the status polling and flashing layers.
"""
from __future__ import annotations

from dataclasses import dataclass

from . import constants as C


def _parse_hex(value: str, name: str) -> int:
    try:
        return int(value.strip(), 16)
    except ValueError as exc:
        raise ValueError(f"{name} must be a hexadecimal number") from exc


def _parse_int(value: str, name: str) -> int:
    try:
        return int(value.strip(), 10)
    except ValueError as exc:
        raise ValueError(f"{name} must be a decimal number") from exc


@dataclass
class DeviceConfig:
    """Which USB device and interfaces the updater should talk to."""

    vid: int = C.RAZER_VID
    app_pid: int = C.APP_PID
    bootloader_pid: int = C.BOOTLOADER_PID
    app_interface: int = C.APP_CONFIG_INTERFACE
    bootloader_interface: int = C.BOOTLOADER_INTERFACE

    @classmethod
    def defaults(cls) -> "DeviceConfig":
        """The stock Huntsman V3 Pro Mini configuration."""
        return cls()

    @classmethod
    def from_strings(cls, vid: str, app_pid: str, bootloader_pid: str,
                     app_interface: str, bootloader_interface: str) -> "DeviceConfig":
        """Parse the GUI advanced-settings fields (VID/PID hex, interfaces
        decimal) into a :class:`DeviceConfig`."""
        return cls(
            vid=_parse_hex(vid, "VID"),
            app_pid=_parse_hex(app_pid, "Application PID"),
            bootloader_pid=_parse_hex(bootloader_pid, "Bootloader PID"),
            app_interface=_parse_int(app_interface, "Application interface"),
            bootloader_interface=_parse_int(bootloader_interface,
                                            "Bootloader interface"),
        )
