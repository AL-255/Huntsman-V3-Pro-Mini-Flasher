"""High-level update orchestration.

Reconstructs the two-phase flow of the original ``Ry_Online_Update_Dll``:

1. application mode — query the serial number, then request bootloader entry;
2. bootloader mode — stream the application image (and secondary flash image)
   as START/DATA/END packets over 65-byte HID input/output reports.
"""
from __future__ import annotations

import time

from . import constants as C
from . import dfu, frame, transport


# --------------------------------------------------------------------------
# Application mode
# --------------------------------------------------------------------------
def query_serial(vid: int = C.RAZER_VID, pid: int = C.APP_PID,
                 interface: int = C.APP_CONFIG_INTERFACE) -> bytes:
    """Query the device serial number via channel 0, opcode 0x82."""
    dev = transport.open_by_interface(vid, pid, interface)
    try:
        report = frame.read_serial_number_report()
        dev.send_feature_report(report)
        response = dev.get_feature_report(0, C.FEATURE_REPORT_LEN)
    finally:
        dev.close()
    return response


def enter_bootloader(vid: int = C.RAZER_VID, pid: int = C.APP_PID,
                     interface: int = C.APP_CONFIG_INTERFACE) -> None:
    """Request bootloader entry via channel 0, opcode 0x04 (mode select)."""
    dev = transport.open_by_interface(vid, pid, interface)
    try:
        dev.send_feature_report(frame.enter_bootloader_report())
    finally:
        dev.close()


def wait_for_bootloader(vid: int = C.RAZER_VID, pid: int = C.BOOTLOADER_PID,
                        timeout_s: float = 30.0) -> "transport.HidDevice":
    """Poll until the bootloader HID device appears, then open it."""
    deadline = time.monotonic() + timeout_s
    last_error: Exception | None = None
    while time.monotonic() < deadline:
        try:
            return transport.open_by_interface(vid, pid, None)
        except transport.TransportError as exc:  # noqa: PERF203
            last_error = exc
            time.sleep(0.5)
    raise transport.TransportError(
        f"bootloader ({vid:04x}:{pid:04x}) did not appear within "
        f"{timeout_s}s") from last_error


# --------------------------------------------------------------------------
# Bootloader mode
# --------------------------------------------------------------------------
def _write_report(dev, chunk: bytes) -> None:
    """Write one 64-byte chunk as a 65-byte output report (report id 0)."""
    payload = chunk + b"\x00" * (C.DFU_CHUNK_LEN - len(chunk))
    dev.write(b"\x00" + payload)


def _read_response(dev) -> tuple[int, int]:
    """Read a 65-byte input report and return (echo, status)."""
    report = dev.read(C.DFU_REPORT_LEN, timeout_ms=3000)
    if len(report) < C.DFU_REPORT_LEN:
        raise transport.TransportError("short input report")
    return dfu.parse_response(report[1:1 + C.DFU_PAYLOAD_LEN])


def _send_packet(dev, packet: bytes) -> None:
    """Send a packet in 64-byte chunks, ACKing each chunk and the final frame."""
    chunks = dfu.chunk(packet)
    command = packet[C.DFU_HDR_COMMAND]
    for i, chunk in enumerate(chunks):
        _write_report(dev, chunk)
        echo, status = _read_response(dev)
        if echo != command:
            raise transport.TransportError(
                f"unexpected echo {echo:#x} (want {command:#x})")
        if i == len(chunks) - 1:
            if status != C.DFU_RESP_DONE:
                raise transport.TransportError(
                    f"final ACK missing (status {status:#x})")
        elif status != C.DFU_RESP_ACK:
            raise transport.TransportError(
                f"chunk {i} not acknowledged (status {status:#x})")


def stream_firmware(dev, app_image: bytes,
                    header: bytes | None = None,
                    preface: bytes = b"",
                    progress=None) -> None:
    """Stream the application image to the bootloader as START/DATA/END.

    The START packet carries the payload size (``len(app_image)``) and the
    32-byte firmware-file header.  The secondary FlashFW image is a separate
    concern and is *not* part of this stream.
    """
    if len(app_image) != C.APP_IMAGE_SIZE:
        raise ValueError(
            f"application image must be {C.APP_IMAGE_SIZE} bytes, got "
            f"{len(app_image)}")

    if header is None:
        header = b"\x00" * C.START_HEADER_LEN
    if len(header) != C.START_HEADER_LEN:
        raise ValueError("START header must be 32 bytes")

    counter = 0
    start = dfu.build_start_packet(counter, len(app_image), header, preface)
    _send_packet(dev, start)
    counter += 1

    checksum = 0
    for off in range(0, len(app_image), C.DATA_CHUNK_SIZE):
        data = app_image[off:off + C.DATA_CHUNK_SIZE]
        checksum = dfu.accumulate_checksum(checksum, data)
        _send_packet(dev, dfu.build_data_packet(counter, data))
        counter += 1
        if progress is not None:
            progress(min(off + len(data), len(app_image)), len(app_image))

    _send_packet(dev, dfu.build_end_packet(counter, checksum, len(app_image)))


def update(package, enter_boot: bool = True, progress=None) -> None:
    """Run the full update: enter bootloader, stream the app image, verify.

    The secondary FlashFW image (``package.flash_image``) is extracted and
    validated by :mod:`resources` but its flashing route is not yet
    re-implemented (see ``analysis/PROTOCOL.md`` §9).
    """
    if enter_boot:
        enter_bootloader(C.RAZER_VID, package.pid, C.APP_CONFIG_INTERFACE)
        dev = wait_for_bootloader(C.RAZER_VID, package.bootloader_pid)
    else:
        dev = transport.open_by_interface(C.RAZER_VID, package.bootloader_pid, None)

    try:
        stream_firmware(dev, package.app_image, progress=progress)
    finally:
        dev.close()
