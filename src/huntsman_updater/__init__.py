"""Independent firmware updater for the Razer Huntsman V3 Pro Mini."""

from . import constants, config, device, dfu, firmware, frame, region, resources, transport, updater
from .constants import (
    RAZER_VID,
    APP_PID,
    BOOTLOADER_PID,
    APP_CONFIG_INTERFACE,
)
from .resources import FirmwarePackage, load_firmware_package

__all__ = [
    "constants",
    "config",
    "device",
    "dfu",
    "firmware",
    "frame",
    "region",
    "resources",
    "transport",
    "updater",
    "RAZER_VID",
    "APP_PID",
    "BOOTLOADER_PID",
    "APP_CONFIG_INTERFACE",
    "FirmwarePackage",
    "load_firmware_package",
]

__version__ = "0.1.0"
