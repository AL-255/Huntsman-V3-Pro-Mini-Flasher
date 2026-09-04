"""Device presence/status polling for the GUI.

Detects which mode the keyboard is in (application vs bootloader vs absent)
and, when in application mode, aggregates the channel-0 device-information
fields into one :class:`DeviceStatus` snapshot.  The target VID/PID pair is
configurable through :class:`~huntsman_updater.settings.DeviceConfig`.
"""
from __future__ import annotations

import os
from dataclasses import dataclass, field

from . import constants as C
from . import device
from .settings import DeviceConfig

MODE_APP = "app"
MODE_BOOTLOADER = "bootloader"
MODE_NONE = "none"


def detect_mode(config: DeviceConfig | None = None) -> str:
    """Return ``"app"``, ``"bootloader"``, or ``"none"`` from USB presence.

    Reads ``/sys/bus/usb/devices`` (Linux); on other platforms it falls back to
    trying to open the device through the transport layer.
    """
    cfg = config or DeviceConfig.defaults()
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
            if vid != f"{cfg.vid:04x}":
                continue
            if pid == f"{cfg.bootloader_pid:04x}":
                return MODE_BOOTLOADER
            if pid == f"{cfg.app_pid:04x}":
                return MODE_APP
        return MODE_NONE

    # Non-Linux fallback: attempt to open each mode's interface.
    from . import transport
    try:
        transport.open_by_interface(cfg.vid, cfg.bootloader_pid,
                                    cfg.bootloader_interface).close()
        return MODE_BOOTLOADER
    except transport.TransportError:
        pass
    try:
        transport.open_by_interface(cfg.vid, cfg.app_pid,
                                    cfg.app_interface).close()
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
    app_pid: int = C.APP_PID
    bootloader_pid: int = C.BOOTLOADER_PID

    @property
    def version_str(self) -> str:
        """Human-readable ``major.minor`` (e.g. ``2.1``)."""
        if len(self.version) < 2:
            return ""
        return f"{self.version[0]}.{self.version[1]}"

    @property
    def mode_label(self) -> str:
        return {
            MODE_APP: f"Application ({self.app_pid:04X})",
            MODE_BOOTLOADER: f"Bootloader ({self.bootloader_pid:04X})",
            MODE_NONE: "Not detected",
        }[self.mode]


def read_device_status(config: DeviceConfig | None = None) -> DeviceStatus:
    """Poll the current mode and (for app mode) the device info fields."""
    cfg = config or DeviceConfig.defaults()
    mode = detect_mode(cfg)
    status = DeviceStatus(mode=mode, app_pid=cfg.app_pid,
                          bootloader_pid=cfg.bootloader_pid)
    if mode != MODE_APP:
        return status

    info = device.query_device_info(cfg.vid, cfg.app_pid, cfg.app_interface)
    status.serial = info.serial
    status.version = info.version
    status.extended_version = info.extended_version
    status.capability = info.capability
    status.build = info.build
    return status
