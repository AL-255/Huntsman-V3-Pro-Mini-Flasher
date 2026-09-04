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
    r = region.build_region_set_id_list_report(p)
    f = frame.parse_frame(r)
    assert f[C.FRAME_CHANNEL] == region.CHANNEL_REGION
    assert f[C.FRAME_OPCODE] == region.OPCODE_REGION_SET_ID_LIST
    # region info query uses opcode 0x80
    f = frame.parse_frame(region.build_region_info_report())
    assert f[C.FRAME_OPCODE] == region.OPCODE_REGION_GET_INFO
    # response parsing: region_size from elements 4..7
    payload = struct.pack("<8H", 1, 1, 2, 0, 0, 0, 0x92, 0x20)
    resp = frame.to_report(frame.build_frame(
        region.CHANNEL_REGION, region.OPCODE_REGION_GET_INFO, payload,
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


class _FakeBootloader:
    """Emulates the bootloader's 65-byte report ACK behaviour.

    It reassembles the incoming 64-byte chunks into DFU packets and returns
    ``ACK`` for every chunk except the one that completes a packet, which gets
    ``DONE`` — matching ``FUN_100064d0``'s host-side expectations.
    """

    def __init__(self):
        self.writes = []
        self._buf = b""
        self._total = None

    def write(self, data):
        self.writes.append(bytes(data))
        payload = bytes(data[1:])           # drop the report id
        if self._total is None:             # first chunk: parse the header
            length = int.from_bytes(payload[4:6], "little")
            self._total = length + 8
        self._buf += payload
        return len(data)

    def read(self, length, timeout_ms=0):
        cmd = self._buf[0]
        done = len(self._buf) >= self._total
        payload = bytearray(64)
        payload[0] = cmd
        payload[8] = C.DFU_RESP_DONE if done else C.DFU_RESP_ACK
        if done:
            self._buf = b""
            self._total = None
        return b"\x00" + bytes(payload)

    def close(self):
        pass


def test_stream_firmware_sequence():
    from huntsman_updater import updater

    app = bytes(C.APP_IMAGE_SIZE)
    dev = _FakeBootloader()
    updater.stream_firmware(dev, app, progress=None)

    commands = [w[1] for w in dev.writes if len(w) > 1]
    # first packet is START ('1'), then DATA ('2') chunks, then END ('3')
    assert commands[0] == C.DFU_CMD_START
    assert C.DFU_CMD_END in commands
    body = C.APP_IMAGE_SIZE - C.START_HEADER_LEN
    expected_data = (body + C.DATA_CHUNK_SIZE - 1) // C.DATA_CHUNK_SIZE
    assert commands.count(C.DFU_CMD_DATA) == expected_data
    # every write is a 65-byte output report (report id 0 + 64 payload)
    assert all(len(w) == C.DFU_REPORT_LEN for w in dev.writes)

    # the START packet header carries the first 32 image bytes (vector table)
    first = dev.writes[0]
    off = 1 + C.DFU_START_HEADER   # report id + 12-byte START header prefix
    hdr = first[off:off + C.START_HEADER_LEN]
    assert hdr == app[:C.START_HEADER_LEN]


def test_full_update_orchestration():
    """Exercise updater.update() end-to-end with fake transport devices."""
    import struct as _struct
    from unittest import mock as _mock
    from huntsman_updater import resources as _resources
    from huntsman_updater import status as _status
    from huntsman_updater import updater as _updater
    from huntsman_updater import transport as _transport

    class _FakeApp:
        """Fake application-mode device (91-byte feature reports)."""
        def __init__(self):
            self.sent = []
        def send_feature_report(self, d):
            self.sent.append(bytes(d))
            return len(d)
        def get_feature_report(self, rid, length):
            payload = _struct.pack("<8H", 1, 1, 2, 0x50, 0, 0, 0x92, 0x20)
            return frame.to_report(frame.build_frame(
                0x0a, 0x80, payload, payload_count=len(payload)))
        def write(self, d):
            return len(d)
        def read(self, l, timeout_ms=0):
            return b""
        def close(self):
            pass

    class _FakeBootDFU:
        """Fake bootloader-mode device (90-byte feature-report channel)."""
        def __init__(self):
            self.sent = []
        def send_feature_report(self, d):
            self.sent.append(bytes(d))
            return len(d)
        def get_feature_report(self, rid, length):
            f = bytearray(C.COMMAND_FRAME_LEN)
            f[C.FRAME_STATUS] = C.STATUS_SUCCESS
            f[C.FRAME_CHANNEL] = region.CHANNEL_DFU
            return b"\x00" + bytes(f)
        def write(self, d):
            return len(d)
        def read(self, l, timeout_ms=0):
            return b""
        def close(self):
            pass

    boot = _FakeBootDFU()
    app = _FakeApp()
    opened = []

    def fake_open(vid, pid, interface=None):
        opened.append((vid, pid, interface))
        return boot if pid == C.BOOTLOADER_PID else app

    orig_open = _transport.open_by_interface
    _transport.open_by_interface = fake_open
    try:
        pkg = _resources.FirmwarePackage(
            app_image=bytes(C.APP_IMAGE_SIZE),
            flash_image=bytes(0x9220),
            metadata={"VID": "1532", "PID": "02B0",
                      "BLVID": "1532", "BLPID": "110E"},
        )
        # Simulate an application-mode device so update() performs the
        # SET_MODE handshake (detect_mode reads sysfs otherwise).
        with _mock.patch.object(_status, "detect_mode",
                                return_value=_status.MODE_APP):
            _updater.update(pkg, enter_boot=True, flash_fw=True)
    finally:
        _transport.open_by_interface = orig_open

    pids = [p for _, p, _ in opened]
    assert pids[0] == C.APP_PID          # enter-bootloader SET_MODE
    assert C.BOOTLOADER_PID in pids       # app-image DFU
    assert pids[-1] == C.APP_PID          # FlashFW phase
    # bootloader got the channel-0x10 DFU: erase, program chunks, exit
    assert boot.sent
    bframes = [frame.parse_frame(r) for r in boot.sent]
    assert bframes[0][C.FRAME_OPCODE] == region.OPCODE_DFU_ERASE
    assert bframes[1][C.FRAME_OPCODE] == region.OPCODE_DFU_PROGRAM
    assert bframes[-1][C.FRAME_OPCODE] == region.OPCODE_DFU_EXIT
    # the erase frame carries [start, end) as two big-endian u32
    assert bframes[0][8:12] == _struct.pack(">I", C.APP_RAM_LOAD_ADDRESS)
    assert bframes[0][12:16] == _struct.pack(
        ">I", C.APP_RAM_LOAD_ADDRESS + C.APP_IMAGE_SIZE)
    # app got SET_MODE then FlashFW commands
    assert app.sent
    assert frame.parse_frame(app.sent[0])[7] == C.OPCODE_ENTER_DEVICE_MODE
    # after SET_MODE, the app device serves FlashFW: region info (0x80) then list
    assert frame.parse_frame(app.sent[1])[7] == 0x80
    assert frame.parse_frame(app.sent[2])[7] == 0x00


def test_update_skips_enter_bootloader_when_already_in_bootloader():
    """A device already in bootloader mode must not require the SET_MODE step."""
    from unittest import mock as _mock
    from huntsman_updater import resources as _resources
    from huntsman_updater import status as _status
    from huntsman_updater import updater as _updater

    pkg = _resources.FirmwarePackage(
        app_image=bytes(C.APP_IMAGE_SIZE), flash_image=b"",
        metadata={"VID": "1532", "PID": "02B0",
                  "BLVID": "1532", "BLPID": "110E"})

    class _Dev:
        def close(self):
            pass

    with _mock.patch.object(_status, "detect_mode",
                            return_value=_status.MODE_BOOTLOADER), \
         _mock.patch.object(_updater, "enter_bootloader") as enter_mock, \
         _mock.patch.object(_updater, "wait_for_device",
                            return_value=_Dev()) as wait_mock, \
         _mock.patch.object(_updater, "flash_app_image") as flash_mock:
        _updater.update(pkg, enter_boot=True, flash_fw=False)
        enter_mock.assert_not_called()
        flash_mock.assert_called_once()
        # bootloader then app-mode waits both used wait_for_device
        assert wait_mock.call_count == 2
