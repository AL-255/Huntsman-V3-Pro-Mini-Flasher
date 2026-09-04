"""Unit tests for the pure protocol logic (no device required)."""
from __future__ import annotations

import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))

from huntsman_updater import constants as C  # noqa: E402
from huntsman_updater import dfu, firmware, frame  # noqa: E402


def test_frame_serial_number_report():
    report = frame.read_serial_number_report()
    assert len(report) == C.FEATURE_REPORT_LEN
    assert report[0] == 0                     # report id
    assert report[1 + C.FRAME_STATUS] == C.STATUS_NEW
    assert report[1 + C.FRAME_PAYLOAD_COUNT] == 0x16
    assert report[1 + C.FRAME_CHANNEL] == C.CHANNEL_DEVICE
    assert report[1 + C.FRAME_OPCODE] == C.OPCODE_READ_CONFIGURATION
    # checksum = XOR of frame bytes 2..87 == report bytes 3..88
    assert report[1 + C.FRAME_CHECKSUM] == 0x16 ^ 0x82


def test_frame_enter_bootloader():
    report = frame.enter_bootloader_report()
    assert report[1 + C.FRAME_OPCODE] == C.OPCODE_ENTER_DEVICE_MODE
    assert report[1 + C.FRAME_PAYLOAD_COUNT] == 2
    assert report[1 + C.FRAME_PAYLOAD] == 0x01
    assert report[1 + C.FRAME_PAYLOAD + 1] == 0x00


def test_start_packet():
    pkt = dfu.build_start_packet(0, 0x20000, b"\x00" * 32, b"")
    assert pkt[0] == C.DFU_CMD_START
    assert pkt[1] == 0
    assert int.from_bytes(pkt[4:6], "little") == 36   # 4 size + 32 header
    assert pkt[8:12] == (0x20000).to_bytes(4, "little")
    assert len(pkt) == 8 + 36


def test_data_packet_and_checksum():
    data = bytes(range(256)) * 2
    pkt = dfu.build_data_packet(7, data)
    assert pkt[0] == C.DFU_CMD_DATA
    assert pkt[1] == 7
    assert int.from_bytes(pkt[4:6], "little") == 512
    acc = dfu.accumulate_checksum(0, data)
    # recompute independently
    import struct
    expect = 0
    for off in range(0, len(data), 4):
        expect ^= struct.unpack_from("<I", data, off)[0]
    assert acc == expect


def test_end_packet():
    import datetime
    now = datetime.datetime(2025, 1, 2, 3, 4, 5)
    pkt = dfu.build_end_packet(9, 0xDEADBEEF, 0x20000, now=now)
    assert pkt[0] == C.DFU_CMD_END
    assert int.from_bytes(pkt[4:6], "little") == 12
    assert pkt[8:12] == (0xDEADBEEF).to_bytes(4, "little")
    assert pkt[12] == 2 and pkt[13] == 1      # day, month
    assert int.from_bytes(pkt[14:16], "little") == 2025
    assert pkt[16] == 5 and pkt[17] == 4      # second, minute
    assert int.from_bytes(pkt[18:20], "little") == 3


def test_intel_hex():
    text = (
        ":020000040001F9\n"
        ":0400000001020304F2\n"
        ":00000001FF\n"
    )
    img = firmware.parse_intel_hex(text)
    assert img == bytes([1, 2, 3, 4])


def test_response_parse():
    payload = b"\x31" + b"\x00" * 7 + b"\x36" + b"\x00" * 55
    echo, status = dfu.parse_response(payload)
    assert echo == ord("1") and status == ord("6")
