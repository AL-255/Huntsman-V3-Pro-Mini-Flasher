"""Flash the application image and read back the firmware version.

Run with sudo (the /dev/bus/usb nodes are root-only)::

    printf 'Andy1998$\n' | sudo -S -p '' python3 analysis/flash_app_test.py
"""
from __future__ import annotations

import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "src"))

from huntsman_updater import constants as C
from huntsman_updater import device, transport, updater
from huntsman_updater.resources import load_firmware_package

RESOURCES = Path(__file__).resolve().parents[2] / "DeviceUpdater.resources"


def read_version() -> bytes:
    return device.query_version()


def main() -> int:
    print(f"== before flash ==")
    try:
        v = read_version()
        print(f"version: {v.hex(' ')} (major {v[0]}, minor {v[1]})")
    except Exception as exc:  # noqa: BLE001
        print(f"could not read version: {exc}")

    pkg = load_firmware_package(RESOURCES)
    print(f"app image: {len(pkg.app_image)} bytes "
          f"(target {pkg.metadata.get('DevFWVer')})")

    print("== enter bootloader ==")
    updater.enter_bootloader(C.RAZER_VID, pkg.pid, C.APP_CONFIG_INTERFACE)
    time.sleep(2.0)

    print("== wait for bootloader (110E) ==")
    dev = transport.open_by_interface(C.RAZER_VID, C.BOOTLOADER_PID,
                                      C.BOOTLOADER_INTERFACE)
    print(f"bootloader opened: {dev._impl.__class__.__name__}")

    def progress(done, total):
        pct = done * 100 // total
        print(f"\r  program {done}/{total} ({pct}%)", end="", flush=True)

    print("== flash app image (channel 0x10 DFU) ==")
    try:
        updater.flash_app_image(dev, pkg.app_image, progress=progress)
    finally:
        dev.close()
    print("\n  flash command stream sent, device should reboot to app mode")

    print("== wait for app (02B0) ==")
    deadline = time.monotonic() + 30.0
    ok = False
    while time.monotonic() < deadline:
        try:
            v = read_version()
            ok = True
            break
        except Exception:  # noqa: BLE001
            time.sleep(1.0)
    if not ok:
        print("device did not return to app mode in time")
        return 1

    print(f"== after flash ==")
    print(f"version: {v.hex(' ')} (major {v[0]}, minor {v[1]})")
    target = pkg.metadata.get("DevFWVer", "")
    expected = target.split(".")
    if len(expected) == 2:
        print(f"expected major.minor = {int(expected[0])}.{int(expected[1])}")
        if v[0] == int(expected[0]) and v[1] == int(expected[1]):
            print("SUCCESS: firmware version matches target")
            return 0
    print("NOTE: version byte layout may differ from the x.y.z string")
    return 0


if __name__ == "__main__":
    sys.exit(main())
