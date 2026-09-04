"""Unit tests for the pure protocol logic (no device required)."""
from __future__ import annotations

import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))

from huntsman_updater import constants as C  # noqa: E402
from huntsman_updater import dfu, firmware, frame, region  # noqa: E402


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


def test_region_list_payload():
    import struct
    p = region.build_region_list_payload(1, 1, 2, 0x50)
    assert p == struct.pack("<HHHH", 1, 1, 2, 0x50)
    r = region.build_region_list_report(p)
    f = frame.parse_frame(r)
    assert f[C.FRAME_CHANNEL] == region.CHANNEL_REGION
    assert f[C.FRAME_OPCODE] == region.OPCODE_REGION_LIST
    # response parsing: region_size from elements 4..7
    payload = struct.pack("<8H", 1, 1, 2, 0, 0, 0, 0x92, 0x20)
    resp = frame.to_report(frame.build_frame(
        region.CHANNEL_REGION, region.OPCODE_REGION_LIST, payload,
        payload_count=len(payload)))
    info = region.parse_region_list_response(resp)
    assert info["region_size"] == 0x9220


def test_dfu_reports():
    import struct
    f = frame.parse_frame(region.build_dfu_erase_report(0x1234, 0x9220))
    assert f[C.FRAME_CHANNEL] == region.CHANNEL_DFU
    assert f[C.FRAME_OPCODE] == region.OPCODE_DFU_ERASE
    assert f[8:12] == struct.pack(">I", 0x1234)
    assert f[12:16] == struct.pack(">I", 0x9220)

    f = frame.parse_frame(region.build_dfu_program_report(bytes(64), 0x1000))
    assert f[C.FRAME_OPCODE] == region.OPCODE_DFU_PROGRAM
    assert f[8] == 64
    assert f[9:13] == struct.pack(">I", 0x1000)

    f = frame.parse_frame(region.build_dfu_verify_report(64, 0x1000))
    assert f[C.FRAME_OPCODE] == region.OPCODE_DFU_VERIFY
    assert f[8] == 64
