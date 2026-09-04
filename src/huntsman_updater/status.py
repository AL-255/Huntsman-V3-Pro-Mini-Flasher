"""Device presence/status polling for the GUI.

Detects which mode the keyboard is in (application ``1532:02B0`` vs bootloader
``1532:110E`` vs absent) and, when in application mode, aggregates the
channel-0 device-information fields into one :class:`DeviceStatus` snapshot.
"""
from __future__ import annotations

import os
from dataclasses import dataclass, field

from . import constants as C
from . import device

MODE_APP = "app"
MODE_BOOTLOADER = "bootloader"
MODE_NONE = "none"


def detect_mode() -> str:
    """Return ``"app"``, ``"bootloader"``, or ``"none"`` from USB presence.

    Reads ``/sys/bus/usb/devices`` (Linux); on other platforms it falls back to
    trying to open the device through the transport layer.
    """
    sysfs = "/sys/bus/usb/devices"
    if os.path.isdir(sysfs):
        for devdir in os.listdir(sysfs):
            base = os.path.join(sysfs, devdir)
            try:
                with open(os.path.join(base, "idVendor")) as fh:
                    vid = fh.read().strip()
                with open(os.path.join(base, "idProduct")) as fh:
                    pid = fh.read().strip()
            except OSError:
                continue
            if vid != f"{C.RAZER_VID:04x}":
                continue
            if pid == f"{C.BOOTLOADER_PID:04x}":
                return MODE_BOOTLOADER
            if pid == f"{C.APP_PID:04x}":
                return MODE_APP
        return MODE_NONE

    # Non-Linux fallback: attempt to open each mode's interface.
    from . import transport
    try:
        transport.open_by_interface(C.RAZER_VID, C.BOOTLOADER_PID,
                                    C.BOOTLOADER_INTERFACE).close()
        return MODE_BOOTLOADER
    except transport.TransportError:
        pass
    try:
        transport.open_by_interface(C.RAZER_VID, C.APP_PID,
                                    C.APP_CONFIG_INTERFACE).close()
        return MODE_APP
    except transport.TransportError:
        return MODE_NONE


@dataclass
class DeviceStatus:
    """One polled snapshot of the device."""
    mode: str = MODE_NONE
    serial: str = ""
    version: bytes = field(default_factory=bytes)
    extended_version: bytes = field(default_factory=bytes)
    capability: bytes = field(default_factory=bytes)
    build: bytes = field(default_factory=bytes)

    @property
    def version_str(self) -> str:
        """Human-readable ``major.minor`` (e.g. ``2.1``)."""
        if len(self.version) < 2:
            return ""
        return f"{self.version[0]}.{self.version[1]}"

    @property
    def mode_label(self) -> str:
        return {
            MODE_APP: f"Application ({C.APP_PID:04X})",
            MODE_BOOTLOADER: f"Bootloader ({C.BOOTLOADER_PID:04X})",
            MODE_NONE: "Not detected",
        }[self.mode]


def read_device_status() -> DeviceStatus:
    """Poll the current mode and (for app mode) the device info fields."""
    mode = detect_mode()
    status = DeviceStatus(mode=mode)
    if mode != MODE_APP:
        return status

    info = device.query_device_info()
    status.serial = info.serial
    status.version = info.version
    status.extended_version = info.extended_version
    status.capability = info.capability
    status.build = info.build
    return status
