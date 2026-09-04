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
OPCODE_REGION_LIST = 0x00
OPCODE_REGION_DATA = 0x02


def build_region_list_payload(total: int, region_id: int, region_type: int,
                              packet_size: int) -> bytes:
    """Encode the region-list request payload (four 16-bit LE fields)."""
    return struct.pack("<HHHH", total & 0xFFFF, region_id & 0xFFFF,
                       region_type & 0xFFFF, packet_size & 0xFFFF)


def build_region_list_report(payload: bytes) -> bytes:
    """Build the 91-byte feature report for the region-list query."""
    f = frame.build_frame(CHANNEL_REGION, OPCODE_REGION_LIST, payload,
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
