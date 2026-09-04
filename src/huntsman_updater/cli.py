"""Command-line interface for the Huntsman V3 Pro Mini updater."""
from __future__ import annotations

import argparse
import sys

from . import __version__, updater
from .resources import load_firmware_package


def _build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="huntsman-updater",
        description=(
            "Flash firmware onto a Razer Huntsman V3 Pro Mini (RZ03-0499).\n\n"
            "The updater talks to the keyboard over USB HID and needs "
            "root/administrator access to open the device (the GUI requests it "
            "automatically; for the CLI, run it under sudo on Linux)."
        ),
        epilog=(
            "examples:\n"
            "  huntsman-updater info DeviceUpdater.resources        "
            "# inspect a firmware bundle\n"
            "  huntsman-updater device-info                        "
            "# read serial/version/build\n"
            "  huntsman-updater flash DeviceUpdater.resources       "
            "# flash the keyboard\n"
            "  huntsman-updater flash FW.resources --no-enter-boot  "
            "# device already in bootloader\n"
            "  huntsman-updater gui                                "
            "# open the graphical updater\n"
        ),
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("--version", action="version",
                        version=f"%(prog)s {__version__}")

    sub = parser.add_subparsers(
        dest="command", required=True, title="commands", metavar="COMMAND",
        help="use \"%(prog)s COMMAND --help\" for details on a command")

    info = sub.add_parser(
        "info",
        help="show the firmware images and metadata in a resources file",
        description="Print the application/flash image sizes and metadata "
                    "stored in a DeviceUpdater.resources file.")
    info.add_argument("resources", metavar="RESOURCES",
                      help="path to a DeviceUpdater.resources file")

    flash = sub.add_parser(
        "flash",
        help="flash firmware onto the connected keyboard",
        description="Flash the application image (and the secondary flash "
                    "image) from a DeviceUpdater.resources file. The keyboard "
                    "is rebooted into its bootloader automatically unless "
                    "--no-enter-boot is given.")
    flash.add_argument("resources", metavar="RESOURCES",
                       help="path to a DeviceUpdater.resources file")
    flash.add_argument(
        "--no-enter-boot", action="store_true",
        help="skip the enter-bootloader step; use this when the keyboard is "
             "already in bootloader mode (e.g. the USB cable was plugged in "
             "while holding Fn)")

    info_dev = sub.add_parser(
        "device-info",
        help="read the connected keyboard's info (serial, version, …)",
        description="Poll the application-mode device for its serial number, "
                    "firmware version, capability, mode, and build number.")
    info_dev.add_argument("--serial", action="store_true",
                          help="print only the serial number")

    sub.add_parser(
        "enter-bootloader",
        help="reboot an application-mode keyboard into its bootloader",
        description="Send the SET_MODE command that makes the keyboard "
                    "re-enumerate as the bootloader (1532:110e).")

    sub.add_parser(
        "gui",
        help="open the graphical updater",
        description="Launch the Tkinter GUI, which re-launches itself with "
                    "root/administrator rights when needed.")

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
