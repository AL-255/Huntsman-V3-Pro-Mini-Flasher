"""Parser for ``DeviceUpdater.resources`` (a .NET .resources file).

The original updater embeds the firmware here as Intel HEX lines
(``DevFWLine0..8195``) and raw byte arrays (``FlashFWSector0..36``), plus
metadata (``VID``/``PID``/``BLVID``/``BLPID``, ``RYFWFileName``, versions, and
report geometry).
"""
from __future__ import annotations

import struct
from dataclasses import dataclass
from pathlib import Path

from .firmware import app_image_from_hex, flash_image_from_sectors


def _read_7bit(data: bytes, offset: int) -> tuple[int, int]:
    result = shift = 0
    while True:
        byte = data[offset]
        offset += 1
        result |= (byte & 0x7F) << shift
        if not byte & 0x80:
            return result, offset
        shift += 7


def _read_value(data: bytes, offset: int) -> tuple[object, int]:
    rtype, offset = _read_7bit(data, offset)
    if rtype == 1:  # String
        length, offset = _read_7bit(data, offset)
        return data[offset:offset + length].decode("utf-8"), offset + length
    if rtype == 2:  # Boolean
        return data[offset] != 0, offset + 1
    if rtype == 8:  # Int32
        return struct.unpack_from("<i", data, offset)[0], offset + 4
    if rtype == 10:  # Int64
        return struct.unpack_from("<q", data, offset)[0], offset + 8
    if rtype == 11:  # UInt64
        return struct.unpack_from("<Q", data, offset)[0], offset + 8
    if rtype == 32:  # ByteArray
        length = struct.unpack_from("<i", data, offset)[0]
        offset += 4
        return data[offset:offset + length], offset + length
    raise ValueError(f"unsupported .resources value type {rtype}")


@dataclass
class FirmwarePackage:
    """Firmware payloads and metadata extracted from the resources file."""
    app_image: bytes
    flash_image: bytes
    metadata: dict

    @property
    def vid(self) -> int:
        return int(self.metadata["VID"], 16)

    @property
    def pid(self) -> int:
        return int(self.metadata["PID"], 16)

    @property
    def bootloader_vid(self) -> int:
        return int(self.metadata["BLVID"], 16)

    @property
    def bootloader_pid(self) -> int:
        return int(self.metadata["BLPID"], 16)


def read_resources(path: str | Path) -> dict[str, object]:
    """Read the string/byte-array/int entries of a .NET .resources file."""
    data = Path(path).read_bytes()
    if len(data) < 12 or struct.unpack_from("<I", data)[0] != 0xBEEFCACE:
        raise ValueError("not a .NET .resources file")

    header_bytes = struct.unpack_from("<I", data, 8)[0]
    offset = 12 + header_bytes
    runtime_version, resource_count, type_count = struct.unpack_from(
        "<III", data, offset)
    if runtime_version != 2:
        raise ValueError("unsupported .resources runtime version")
    offset += 12

    for _ in range(type_count):
        length, offset = _read_7bit(data, offset)
        offset += length

    hash_section = (offset + 7) & ~7
    position_section = hash_section + resource_count * 4
    data_start_offset = position_section + resource_count * 4
    data_start = struct.unpack_from("<I", data, data_start_offset)[0]
    name_section = data_start_offset + 4
    positions = struct.unpack_from(f"<{resource_count}I", data, position_section)

    resources: dict[str, object] = {}
    for rel in positions:
        off = name_section + rel
        length, off = _read_7bit(data, off)
        name = data[off:off + length].decode("utf-16le")
        off += length
        rel_data = struct.unpack_from("<I", data, off)[0]
        value, _ = _read_value(data, data_start + rel_data)
        resources[name] = value
    return resources


def load_firmware_package(path: str | Path) -> FirmwarePackage:
    """Extract the firmware payloads and metadata from the resources file."""
    resources = read_resources(path)

    def numbered(prefix: str):
        selected = sorted(
            (int(name[len(prefix):]), value)
            for name, value in resources.items()
            if name.startswith(prefix)
            and name[len(prefix):].isdigit()
            and isinstance(value, (str, bytes)))
        if [i for i, _ in selected] != list(range(len(selected))):
            raise ValueError(f"{prefix} resources are not consecutively numbered")
        return [value for _, value in selected]

    app_lines = numbered("DevFWLine")
    flash_sectors = numbered("FlashFWSector")
    if not isinstance(flash_sectors[0], bytes):
        raise ValueError("FlashFWSector resources are not byte arrays")

    app_image = app_image_from_hex(app_lines)
    if len(app_image) != 0x20000:
        raise ValueError(
            f"unexpected application image size: {len(app_image)} "
            f"(expected {0x20000})")
    flash_image = flash_image_from_sectors(
        flash_sectors, int(resources["FlashFWFileSize"]))

    metadata = {
        k: v for k, v in resources.items()
        if not k.startswith("DevFWLine") and not k.startswith("FlashFWSector")
        and not isinstance(v, bytes)
    }
    return FirmwarePackage(app_image=app_image, flash_image=flash_image,
                           metadata=metadata)
