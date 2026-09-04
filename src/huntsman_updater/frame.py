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
                payload_count: int | None = None,
                header: bytes = b"") -> bytes:
    """Build a 90-byte command frame for a request.

    ``payload_count`` defaults to ``len(payload)``.  The payload must fit in
    the 80-byte field (offsets 8..87).  ``header`` fills frame bytes 2..4 (the
    generic ``FWUpdaterDLL::SendCmd`` b3/b4 bytes), up to 3 bytes.
    """
    if len(payload) > 80:
        raise ValueError("command payload exceeds 80 bytes")
    if len(header) > 3:
        raise ValueError("command header exceeds 3 bytes")
    if payload_count is None:
        payload_count = len(payload)
    frame = bytearray(C.COMMAND_FRAME_LEN)
    frame[C.FRAME_STATUS] = C.STATUS_NEW
    frame[2:2 + len(header)] = header
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

    Channel 0x00, opcode 0x04 (SET_MODE), payload_count 2, payload ``[mode=1,
    0]`` — the exact frame produced by ``FWUpdaterDLL::EnterDeviceMode(handle,
    1)`` (confirmed from its disassembly).  On receipt the firmware raises the
    mode-one reset request, writes the ``0xaaaaaaaa`` persistent reset cookie,
    and performs a system reset into the bootloader.
    """
    frame = build_frame(C.CHANNEL_DEVICE, C.OPCODE_ENTER_DEVICE_MODE,
                        payload=b"\x01\x00", payload_count=2)
    return to_report(frame)


def parse_frame(report: bytes) -> bytes:
    """Extract the 90-byte frame from a 91-byte feature report."""
    if len(report) < C.COMMAND_FRAME_LEN:
        raise ValueError("feature report too short")
    return bytes(report[1:1 + C.COMMAND_FRAME_LEN])


def parse_status(report: bytes) -> int:
    """Return the command status byte of a feature report."""
    return report[1 + C.FRAME_STATUS]
