"""Firmware payload parsing.

The original updater embeds the application image as Intel HEX lines
(``DevFWLine`` resources) and a secondary "flash FW" image as raw byte arrays
(``FlashFWSector`` resources) inside ``DeviceUpdater.resources``.  This module
re-derives the two payloads and exposes them as plain bytes.

The primary application image is 128 KiB and is loaded at ``0x20000000``.  The
secondary flash image is 37408 bytes and is carried encrypted when the updater
config sets ``encryption_en=1``; its format is not yet decoded here.
"""
from __future__ import annotations

from . import constants as C


def app_image_from_hex(lines: list[str]) -> bytes:
    """Validate Intel HEX lines and produce the contiguous application image.

    Raises ``ValueError`` on malformed records, bad checksums, or gaps.
    """
    base_address = 0
    chunks: list[tuple[int, bytes]] = []
    for line in lines:
        if not line.startswith(":"):
            raise ValueError(f"invalid Intel HEX line: {line!r}")
        record = bytes.fromhex(line[1:])
        if len(record) < 5 or record[0] + 5 != len(record) or sum(record) & 0xFF:
            raise ValueError(f"invalid Intel HEX record checksum: {line}")
        address = int.from_bytes(record[1:3], "big")
        record_type = record[3]
        payload = record[4:-1]
        if record_type == 0:
            chunks.append((base_address + address, payload))
        elif record_type == 4:  # extended linear address (upper 16 bits)
            if len(payload) != 2:
                raise ValueError("invalid extended-address record")
            base_address = int.from_bytes(payload, "big") << 16
        elif record_type not in (1, 5):  # EOF / start address
            raise ValueError(f"unexpected Intel HEX record type {record_type}")

    if not chunks:
        raise ValueError("empty Intel HEX image")

    start = chunks[0][0]
    image = bytearray()
    expected = start
    for address, payload in chunks:
        if address != expected:
            raise ValueError(
                f"non-contiguous image: expected {expected:#x}, got {address:#x}")
        image.extend(payload)
        expected += len(payload)

    return bytes(image)


def parse_intel_hex(text: str) -> bytes:
    """Convenience wrapper around :func:`app_image_from_hex`."""
    lines = [ln.strip() for ln in text.splitlines() if ln.strip()]
    return app_image_from_hex(lines)


def flash_image_from_sectors(sectors: list[bytes], expected_size: int) -> bytes:
    """Concatenate FlashFWSector byte arrays and check the declared size."""
    image = b"".join(sectors)
    if len(image) != expected_size:
        raise ValueError(
            f"flash image size mismatch: {len(image)} != {expected_size}")
    return image


def xor_fold(data: bytes) -> int:
    """Fold ``data`` into a 32-bit XOR checksum (little-endian 32-bit words).

    This matches the ``Ry_Online_Update_Dll`` whole-file integrity check in
    ``FUN_10006650``: XOR each little-endian u32 word, ignoring a partial tail.
    """
    acc = 0
    for off in range(0, len(data) & ~3, 4):
        acc ^= int.from_bytes(data[off:off + 4], "little")
    return acc & 0xFFFFFFFF
