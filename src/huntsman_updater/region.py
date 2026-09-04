"""Secondary-controller "flash FW" region protocol.

The secondary image (``FlashFWSector`` / ``flashfw.bin``, the "7203" Optical
ASIC firmware) is programmed through the main MCU using a region-addressed
command family on channel ``0x0a`` of the 91-byte feature-report channel.

Recovered from the .NET orchestrator's ``backgroundWorkerSetFlashRegionIDList``
and ``backgroundWorkerSetFlashRegionData`` workers:

* region list  — channel ``0x0a``, opcode ``0x00``, payload
  ``[total, RegionID, type, packetsize]`` (16-bit LE fields); the response
  carries the region list and a big-endian region size at payload bytes 4..7.
* region data  — channel ``0x0a``, opcode ``0x02``, header bytes ``0xff 0xff``,
  payload = one chunk of the image.

The exact erase/program/verify sequencing and the WinUSB checksum read-back
remain open; this module provides the confirmed command encoders.
"""
from __future__ import annotations

import struct

from . import constants as C
from . import frame

CHANNEL_REGION = 0x0A
OPCODE_REGION_GET_INFO = 0x80   # read region info (total/RegionID/type/size)
OPCODE_REGION_SET_ID_LIST = 0x00  # write region ID list
OPCODE_REGION_DATA = 0x02       # write region data (one chunk)

# Channel 0x10 is the secondary "flash FW" DFU channel (confirmed from
# FWUpdaterDLL::DFUErase/DFUProgram/DFUVerify disassembly).  Its payload is
# address/size or region+address+data in big-endian.
CHANNEL_DFU = 0x10
OPCODE_DFU_ERASE = 0x01
OPCODE_DFU_PROGRAM = 0x02
OPCODE_DFU_VERIFY = 0x83
OPCODE_DFU_ABORT = 0x04
OPCODE_DFU_EXIT = 0x05


def build_region_list_payload(total: int, region_id: int, region_type: int,
                              packet_size: int) -> bytes:
    """Encode the region-list request payload (four 16-bit LE fields)."""
    return struct.pack("<HHHH", total & 0xFFFF, region_id & 0xFFFF,
                       region_type & 0xFFFF, packet_size & 0xFFFF)


def build_region_info_report() -> bytes:
    """Build the 91-byte feature report for the region-info query (opcode 0x80).

    The request payload is empty; the response carries the region list.
    """
    f = frame.build_frame(CHANNEL_REGION, OPCODE_REGION_GET_INFO, b"",
                          payload_count=0)
    return frame.to_report(f)


def build_region_set_id_list_report(payload: bytes) -> bytes:
    """Build the 91-byte feature report that writes the region ID list."""
    f = frame.build_frame(CHANNEL_REGION, OPCODE_REGION_SET_ID_LIST, payload,
                          payload_count=len(payload))
    return frame.to_report(f)


def build_region_data_report(chunk: bytes) -> bytes:
    """Build the 91-byte feature report for a region-data write."""
    f = frame.build_frame(CHANNEL_REGION, OPCODE_REGION_DATA, chunk,
                          payload_count=len(chunk), header=b"\xff\xff")
    return frame.to_report(f)


def parse_region_list_response(report: bytes) -> dict:
    """Parse the region-list response payload.

    The response is a 16-bit-element array: ``[0]=total``, ``[1]=region_id``,
    ``[2]=type``, and ``region_size`` assembled from elements 4..7 as
    ``el[4]<<24 | el[5]<<16 | el[6]<<8 | el[7]`` (the .NET worker's
    reconstruction).
    """
    f = frame.parse_frame(report)
    count = f[C.FRAME_PAYLOAD_COUNT]
    payload = f[C.FRAME_PAYLOAD:C.FRAME_PAYLOAD + count]
    if len(payload) < 16:
        raise ValueError("region-list response too short")
    elems = struct.unpack_from("<8H", payload, 0)
    total, region_id, region_type = elems[0], elems[1], elems[2]
    region_size = (elems[4] << 24) | (elems[5] << 16) | (elems[6] << 8) | elems[7]
    return {"total": total, "region_id": region_id, "type": region_type,
            "region_size": region_size}


# --- channel 0x10 secondary-flash DFU --------------------------------------

def build_dfu_report(opcode: int, payload: bytes,
                     payload_count: int | None = None) -> bytes:
    """Build a channel-0x10 DFU feature report.

    ``payload_count`` defaults to ``len(payload)``.  The original
    ``FWUpdaterDLL`` fixes this field per opcode rather than deriving it from
    the payload length (see ``analysis/native/fwupdaterdll/DFU*.c``):

    * erase   — 8  (4-byte address + 4-byte size)
    * program — 8  (fixed; the data length lives at payload byte 0)
    * verify  — 5  (1-byte length + 4-byte address)
    * abort/exit — 0
    """
    f = frame.build_frame(CHANNEL_DFU, opcode, payload,
                          payload_count=payload_count)
    return frame.to_report(f)


def build_dfu_erase_report(address: int, size: int) -> bytes:
    """Erase ``size`` bytes at ``address`` (big-endian address + size)."""
    payload = struct.pack(">II", address & 0xFFFFFFFF, size & 0xFFFFFFFF)
    return build_dfu_report(OPCODE_DFU_ERASE, payload, payload_count=8)


def build_dfu_program_report(data: bytes, address: int) -> bytes:
    """Program ``data`` at ``address`` (1-byte length + BE address + data).

    The length byte is ``len(data)``; the frame's payload-count field is the
    fixed value 8 used by ``FWUpdaterDLL::DFUProgram``.
    """
    payload = bytes([len(data) & 0xFF]) + struct.pack(">I", address) + data
    return build_dfu_report(OPCODE_DFU_PROGRAM, payload, payload_count=8)


def build_dfu_verify_report(length: int, address: int) -> bytes:
    """Verify ``length`` bytes at ``address`` (1-byte length + BE address)."""
    payload = bytes([length & 0xFF]) + struct.pack(">I", address)
    return build_dfu_report(OPCODE_DFU_VERIFY, payload, payload_count=5)


def build_dfu_abort_report() -> bytes:
    return build_dfu_report(OPCODE_DFU_ABORT, b"", payload_count=0)


def build_dfu_exit_report() -> bytes:
    return build_dfu_report(OPCODE_DFU_EXIT, b"", payload_count=0)
