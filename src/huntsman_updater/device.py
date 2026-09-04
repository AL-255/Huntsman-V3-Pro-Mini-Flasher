"""Application-mode device information queries.

The keyboard exposes a channel-0 "device" command family over 91-byte HID
feature reports.  The read opcodes poll device information (version, serial
number, capability, mode, build, ...); see ``constants.DEVICE_QUERY_*``.
"""
from __future__ import annotations

from dataclasses import dataclass, field

from . import constants as C
from . import frame, transport


def _query(opcode: int, payload: bytes = b"", retries: int = 8) -> bytes:
    """Send a channel-0 query and return the response payload bytes.

    The firmware processes command frames asynchronously, so the response is
    polled (like the original ``FWUpdaterDLL`` send loop) until it stops
    reporting ``STATUS_BUSY``.
    """
    import time
    dev = transport.open_by_interface(C.RAZER_VID, C.APP_PID,
                                      C.APP_CONFIG_INTERFACE)
    try:
        report = frame.to_report(
            frame.build_frame(C.CHANNEL_DEVICE, opcode, payload))
        dev.send_feature_report(report)
        response = b""
        for _ in range(retries):
            response = dev.get_feature_report(0, C.FEATURE_REPORT_LEN)
            status = response[1 + C.FRAME_STATUS]
            if status != C.STATUS_BUSY:
                break
            time.sleep(0.05)
    finally:
        dev.close()

    f = frame.parse_frame(response)
    status = f[C.FRAME_STATUS]
    if status == C.STATUS_BUSY:
        raise transport.TransportError("device busy (timed out)")
    if status not in (C.STATUS_SUCCESS, C.STATUS_NEW):
        raise transport.TransportError(f"query {opcode:#x} failed (status {status})")
    count = f[C.FRAME_PAYLOAD_COUNT]
    return f[C.FRAME_PAYLOAD:C.FRAME_PAYLOAD + count]


def _ascii(data: bytes) -> str:
    return data.split(b"\x00", 1)[0].decode("ascii", errors="replace")


def query_version() -> bytes:
    """2-byte version (``version0``, ``version1``)."""
    return _query(C.OPCODE_QUERY_VERSION)


def query_serial() -> str:
    """22-byte identifier / serial number, decoded as ASCII."""
    return _ascii(_query(C.OPCODE_READ_CONFIGURATION))


def query_extended_version() -> bytes:
    """8-byte extended firmware version (4 version bytes + 4 extended bytes)."""
    return _query(C.OPCODE_QUERY_EXTENDED_VERSION)


def query_capability() -> bytes:
    return _query(C.OPCODE_QUERY_CAPABILITY)


def query_mode() -> int:
    return _query(C.OPCODE_QUERY_MODE)[0]


def query_build() -> bytes:
    return _query(C.OPCODE_QUERY_BUILD)


def query_profile_timer(profile: int = 0) -> int:
    return _query(C.OPCODE_QUERY_PROFILE_TIMER, bytes([profile & 0xFF]))[1]


@dataclass
class DeviceInfo:
    """Aggregated application-mode device information."""
    serial: str = ""
    version: bytes = field(default_factory=bytes)
    extended_version: bytes = field(default_factory=bytes)
    capability: bytes = field(default_factory=bytes)
    mode: int = 0
    build: bytes = field(default_factory=bytes)


def query_device_info() -> DeviceInfo:
    """Poll every available device-information field in one pass."""
    return DeviceInfo(
        serial=query_serial(),
        version=query_version(),
        extended_version=query_extended_version(),
        capability=query_capability(),
        mode=query_mode(),
        build=query_build(),
    )
