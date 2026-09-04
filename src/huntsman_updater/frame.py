"""The 90-byte Razer command frame carried inside the 91-byte feature report.

Layout (confirmed against the firmware reconstruction's ``RZ0499_layout.h``):

    frame[0]      status         0 = new request, 1 = busy, 2 = success
    frame[2..4]   header         (covered by the checksum)
    frame[5]      payload_count  payload length / item count
    frame[6]      channel        command channel selector
    frame[7]      opcode         operation code
    frame[8..87]  payload        80-byte payload
    frame[88]     checksum       XOR of frame bytes 2..87
    frame[89]     extension

The 91-byte HID feature report is ``report[0] = 0`` (report id) followed by
``frame`` at ``report[1..90]``, so ``frame[i] == report[i + 1]``.
"""
from __future__ import annotations

from . import constants as C


def checksum(frame: bytes) -> int:
    """Compute the command-frame checksum: XOR of frame bytes 2..87."""
    acc = 0
    for b in frame[2:C.FRAME_CHECKSUM]:
        acc ^= b
    return acc & 0xFF


def build_frame(channel: int, opcode: int, payload: bytes = b"",
                payload_count: int | None = None) -> bytes:
    """Build a 90-byte command frame for a request.

    ``payload_count`` defaults to ``len(payload)``.  The payload must fit in
    the 80-byte field (offsets 8..87).
    """
    if len(payload) > 80:
        raise ValueError("command payload exceeds 80 bytes")
    if payload_count is None:
        payload_count = len(payload)
    frame = bytearray(C.COMMAND_FRAME_LEN)
    frame[C.FRAME_STATUS] = C.STATUS_NEW
    frame[C.FRAME_PAYLOAD_COUNT] = payload_count & 0xFF
    frame[C.FRAME_CHANNEL] = channel & 0xFF
    frame[C.FRAME_OPCODE] = opcode & 0xFF
    frame[C.FRAME_PAYLOAD:C.FRAME_PAYLOAD + len(payload)] = payload
    frame[C.FRAME_CHECKSUM] = checksum(frame)
    return bytes(frame)


def to_report(frame: bytes) -> bytes:
    """Wrap a 90-byte frame into a 91-byte feature report (report id 0)."""
    if len(frame) != C.COMMAND_FRAME_LEN:
        raise ValueError("frame must be 90 bytes")
    return b"\x00" + frame


def read_serial_number_report() -> bytes:
    """Build the 91-byte feature report that queries the serial number.

    Channel 0x00, opcode 0x82 (READ_CONFIGURATION), 22-byte payload.
    """
    frame = build_frame(C.CHANNEL_DEVICE, C.OPCODE_READ_CONFIGURATION,
                        payload_count=0x16)
    return to_report(frame)


def enter_bootloader_report() -> bytes:
    """Build the 91-byte feature report that requests bootloader entry.

    Channel 0x00, opcode 0x04 (mode-select / enter-device-mode).  The original
    ``EnterDeviceMode(handle, 1)`` passes mode 1.
    """
    frame = build_frame(C.CHANNEL_DEVICE, C.OPCODE_ENTER_DEVICE_MODE,
                        payload=b"\x01", payload_count=1)
    return to_report(frame)


def parse_frame(report: bytes) -> bytes:
    """Extract the 90-byte frame from a 91-byte feature report."""
    if len(report) < C.COMMAND_FRAME_LEN:
        raise ValueError("feature report too short")
    return bytes(report[1:1 + C.COMMAND_FRAME_LEN])


def parse_status(report: bytes) -> int:
    """Return the command status byte of a feature report."""
    return report[1 + C.FRAME_STATUS]
