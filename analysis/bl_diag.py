"""Diagnose bootloader communication and DFU behavior."""
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "src"))

from huntsman_updater import constants as C, frame, region, transport


def dump(report, label):
    f = frame.parse_frame(report)
    print(f"  [{label}] status={f[0]} payload_count={f[5]} "
          f"channel={f[6]:#04x} opcode={f[7]:#04x} "
          f"payload={f[8:8 + f[5]].hex(' ') if f[5] else '(empty)'}")


def main():
    print("opening bootloader 1532:110e interface 0 ...")
    dev = transport.open_by_interface(C.RAZER_VID, C.BOOTLOADER_PID,
                                      C.BOOTLOADER_INTERFACE)
    print("backend:", dev._impl.__class__.__name__)

    # 1. channel-0 version query (opcode 0x81)
    print("\n== channel-0 version query (0x81) ==")
    report = frame.to_report(frame.build_frame(C.CHANNEL_DEVICE, 0x81, b""))
    dev.send_feature_report(report)
    for i in range(8):
        try:
            resp = dev.get_feature_report(0, C.FEATURE_REPORT_LEN)
        except Exception as exc:
            print(f"  get_feature_report failed: {exc}")
            break
        st = resp[1 + C.FRAME_STATUS] if len(resp) > 1 else -1
        if st != C.STATUS_BUSY:
            break
        time.sleep(0.05)
    dump(resp, "version response")

    # 2. DFU erase
    print("\n== DFU erase (0x20000000..0x20020000) ==")
    try:
        dev.send_feature_report(
            region.build_dfu_erase_report(0x20000000, 0x20020000))
        for i in range(20):
            resp = dev.get_feature_report(0, C.FEATURE_REPORT_LEN)
            st = resp[1 + C.FRAME_STATUS] if len(resp) > 1 else -1
            if st not in (C.STATUS_NEW, C.STATUS_BUSY):
                break
            time.sleep(0.05)
        dump(resp, "erase response")
    except Exception as exc:
        print(f"  erase failed: {exc!r}")

    # 3. DFU program (one 64-byte chunk)
    print("\n== DFU program (64 bytes @ 0x20000000) ==")
    try:
        chunk = bytes(64)
        dev.send_feature_report(
            region.build_dfu_program_report(chunk, 0x20000000))
        for i in range(20):
            resp = dev.get_feature_report(0, C.FEATURE_REPORT_LEN)
            st = resp[1 + C.FRAME_STATUS] if len(resp) > 1 else -1
            if st not in (C.STATUS_NEW, C.STATUS_BUSY):
                break
            time.sleep(0.05)
        dump(resp, "program response")
    except Exception as exc:
        print(f"  program failed: {exc!r}")

    dev.close()
    print("\ndone")


if __name__ == "__main__":
    main()
