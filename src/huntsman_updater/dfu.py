"""Bootloader-mode DFU packet construction.

The bootloader accepts firmware as a stream of packets with an 8-byte header
followed by a payload.  Each packet is split into 64-byte chunks, sent as
65-byte HID output reports (report id 0 + 64 bytes), and acknowledged by a
65-byte input report whose 64-byte payload echoes the command at offset 0 and
carries a status byte at offset 8 (``'6'`` = per-chunk ACK, ``'4'`` = done).

Packet header (confirmed from disassembly of ``FUN_10006650``):

    [0]     command       '1' START / '2' DATA / '3' END
    [1]     counter       packet sequence byte
    [2..3]  value         uint16 LE (START: counter; END: app_size >> 2)
    [4..5]  length        uint16 LE payload byte count (total = 8 + length)
    [6]     flag          1 on START
    [7]     block_count   block count on START
"""
from __future__ import annotations

import datetime
import struct

from . import constants as C


def _packet(command: int, counter: int, value: int, payload: bytes,
            flag: int = 0, block_count: int = 0) -> bytes:
    header = struct.pack("<BBHHBB", command, counter & 0xFF, value & 0xFFFF,
                         len(payload) & 0xFFFF, flag & 0xFF, block_count & 0xFF)
    return header + payload


def build_start_packet(counter: int, total_size: int, header: bytes,
                       preface: bytes = b"") -> bytes:
    """Build a START packet.

    ``total_size`` is the payload byte count (the application image size) and
    ``header`` is the 32-byte firmware-file header.  ``preface`` is an optional
    fixed blob appended after the header (present in the original stream).
    """
    if len(header) != C.START_HEADER_LEN:
        raise ValueError("START header must be 32 bytes")
    payload = struct.pack("<I", total_size & 0xFFFFFFFF) + header + preface
    return _packet(C.DFU_CMD_START, counter, counter, payload,
                   flag=1, block_count=0x80)


def build_data_packet(counter: int, data: bytes) -> bytes:
    """Build a DATA packet carrying up to 512 firmware bytes."""
    if len(data) > C.DATA_CHUNK_SIZE:
        raise ValueError("DATA packet exceeds 512 bytes")
    return _packet(C.DFU_CMD_DATA, counter, 0, data)


def build_end_packet(counter: int, checksum: int, app_size: int,
                     now: datetime.datetime | None = None) -> bytes:
    """Build an END packet carrying the accumulated checksum and a timestamp."""
    now = now or datetime.datetime.now()
    payload = struct.pack("<I", checksum & 0xFFFFFFFF)
    payload += struct.pack("<BBHBBH",
                           now.day, now.month, now.year,
                           now.second, now.minute, now.hour)
    return _packet(C.DFU_CMD_END, counter, (app_size >> 2) & 0xFFFF, payload)


def accumulate_checksum(checksum: int, data: bytes) -> int:
    """XOR-fold a firmware chunk (32-bit words) into the running checksum."""
    acc = checksum
    for off in range(0, len(data) & ~3, 4):
        acc ^= struct.unpack_from("<I", data, off)[0]
    return acc & 0xFFFFFFFF


def chunk(packet: bytes) -> list[bytes]:
    """Split a packet into 64-byte chunks for the HID output reports."""
    return [packet[i:i + C.DFU_CHUNK_LEN]
            for i in range(0, len(packet), C.DFU_CHUNK_LEN)]


def parse_response(payload: bytes) -> tuple[int, int]:
    """Return (echo_command, status) from a 64-byte input-report payload."""
    if len(payload) < C.DFU_RESP_STATUS + 1:
        raise ValueError("input report payload too short")
    return payload[C.DFU_RESP_ECHO], payload[C.DFU_RESP_STATUS]


def build_getv_command() -> bytes:
    """Build the bootloader "get version" command (``FUN_10004000``).

    A 12-byte frame sent over the 65-byte output-report channel before the DFU
    stream: ``[0x30 00 00 00][04 00 00 00]["getv"]``.  The response echoes
    ``0x30`` and carries the bootloader version words.
    """
    return b"\x30\x00\x00\x00" + struct.pack("<I", 4) + b"getv"


def parse_getv_response(payload: bytes) -> dict:
    """Parse a bootloader "get version" response (64-byte payload).

    Recovered fields: ``[0]`` echo ``'0'`` (0x30), ``[4..5]`` a fixed ``0x10``
    marker, ``[6..7]``/``[8..9]`` two version words.
    """
    if len(payload) < 10 or payload[0] != 0x30:
        raise ValueError("not a getv response")
    return {
        "marker": int.from_bytes(payload[4:6], "little"),
        "version_a": int.from_bytes(payload[6:8], "big"),
        "version_b": int.from_bytes(payload[8:10], "big"),
    }
