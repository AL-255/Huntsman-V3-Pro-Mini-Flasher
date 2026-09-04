"""Independent firmware updater for the Razer Huntsman V3 Pro Mini."""

from . import (constants, config, device, dfu, elevate, firmware, frame,
               region, resources, settings, status, transport, updater, usbdev)
from .constants import (
    RAZER_VID,
    APP_PID,
    BOOTLOADER_PID,
    APP_CONFIG_INTERFACE,
)
from .resources import FirmwarePackage, load_firmware_package
from .settings import DeviceConfig

__all__ = [
    "constants",
    "config",
    "device",
    "dfu",
    "elevate",
    "firmware",
    "frame",
    "region",
    "resources",
    "settings",
    "status",
    "transport",
    "updater",
    "usbdev",
    "RAZER_VID",
    "APP_PID",
    "BOOTLOADER_PID",
    "APP_CONFIG_INTERFACE",
    "FirmwarePackage",
    "load_firmware_package",
    "DeviceConfig",
]

__version__ = "0.0.1"
