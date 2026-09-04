"""Command-line interface for the Huntsman V3 Pro Mini updater."""
from __future__ import annotations

import argparse
import sys

from . import updater
from .resources import load_firmware_package


def _build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="huntsman-updater",
        description="Flash firmware onto a Razer Huntsman V3 Pro Mini.")
    sub = parser.add_subparsers(dest="command", required=True)

    info = sub.add_parser("info", help="show package metadata")
    info.add_argument("resources", help="path to DeviceUpdater.resources")

    flash = sub.add_parser("flash", help="flash firmware from a resources file")
    flash.add_argument("resources", help="path to DeviceUpdater.resources")
    flash.add_argument("--no-enter-boot", action="store_true",
                       help="assume the device is already in the bootloader "
                            "(e.g. plugged in while holding Fn)")

    info_dev = sub.add_parser("device-info", help="poll device information")
    info_dev.add_argument("--serial", action="store_true", help="serial number only")

    sub.add_parser("enter-bootloader", help="request bootloader entry")

    sub.add_parser("gui", help="launch the graphical updater")

    return parser


def main(argv=None) -> int:
    args = _build_parser().parse_args(argv)

    if args.command == "info":
        pkg = load_firmware_package(args.resources)
        m = pkg.metadata
        print(f"Product:      {m.get('ProductName')}")
        print(f"Firmware:     {m.get('RYFWFileName')}")
        print(f"App image:    {len(pkg.app_image)} bytes")
        print(f"Flash image:  {len(pkg.flash_image)} bytes")
        print(f"App VID:PID:  {m.get('VID')}:{m.get('PID')}")
        print(f"Boot VID:PID: {m.get('BLVID')}:{m.get('BLPID')}")
        print(f"DevFWVer:     {m.get('DevFWVer')}")
        return 0

    if args.command == "flash":
        pkg = load_firmware_package(args.resources)

        def progress(done, total):
            pct = done * 100 // total
            print(f"\rFlashing: {done}/{total} bytes ({pct}%)", end="",
                  flush=True)

        print(f"Flashing {pkg.metadata.get('ProductName')} "
              f"({len(pkg.app_image)} bytes app image)")
        updater.update(pkg, enter_boot=not args.no_enter_boot,
                       progress=progress)
        print("\nFlash complete.")
        return 0

    if args.command == "device-info":
        from . import device
        if args.serial:
            print(device.query_serial())
            return 0
        info = device.query_device_info()
        print(f"Serial:            {info.serial}")
        print(f"Version:           {info.version.hex()}")
        print(f"Extended version:  {info.extended_version.hex()}")
        print(f"Capability:        {info.capability.hex()}")
        print(f"Mode:              {info.mode}")
        print(f"Build:             {info.build.hex()}")
        return 0

    if args.command == "enter-bootloader":
        updater.enter_bootloader()
        print("Bootloader entry requested.")
        return 0

    if args.command == "gui":
        from . import gui
        return gui.main()

    return 1


if __name__ == "__main__":
    sys.exit(main())
