"""Flash the app image from the current (bootloader) state and verify."""
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "src"))

from huntsman_updater import constants as C, device, status, updater
from huntsman_updater.resources import load_firmware_package

RESOURCES = Path(__file__).resolve().parents[2] / "DeviceUpdater.resources"


def main():
    print("mode before:", status.detect_mode())
    pkg = load_firmware_package(RESOURCES)

    def progress(done, total):
        pct = done * 100 // total
        print(f"\r  program {done}/{total} ({pct}%)", end="", flush=True)

    print("flashing app image (enter_boot=True)...")
    updater.update(pkg, enter_boot=True, flash_fw=False, progress=progress)
    print("\nflash returned; waiting for app mode...")

    deadline = time.monotonic() + 40
    v = b""
    while time.monotonic() < deadline:
        try:
            v = device.query_version()
            break
        except Exception:
            time.sleep(1.0)
    print("mode after:", status.detect_mode())
    print("version:", v.hex(" ") if v else "(empty)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
