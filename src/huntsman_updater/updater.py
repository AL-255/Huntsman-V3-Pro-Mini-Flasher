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


def wait_for_device(vid: int = C.RAZER_VID, pid: int = C.BOOTLOADER_PID,
                    timeout_s: float = 30.0) -> "transport.HidDevice":
    """Poll until a HID device (``vid:pid``) appears, then open it.

    Used to await the bootloader (``1532:110E``) after entering it and to await
    the application device (``1532:02B0``) after the post-flash reboot.
    """
    deadline = time.monotonic() + timeout_s
    last_error: Exception | None = None
    while time.monotonic() < deadline:
        try:
            return transport.open_by_interface(vid, pid, None)
        except transport.TransportError as exc:  # noqa: PERF203
            last_error = exc
            time.sleep(0.5)
    raise transport.TransportError(
        f"device ({vid:04x}:{pid:04x}) did not appear within "
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
                    preface: bytes = b"",
                    progress=None) -> None:
    """Stream the application image to the bootloader as START/DATA/END.

    The original engine reads a firmware file as ``[32-byte header][payload]``:
    the first 32 bytes (the Cortex-M33 vector table) go into the START packet
    at ``[12..43]``, and the remaining ``file_size - 32`` bytes are streamed as
    DATA packets.  ``preface`` is an optional fixed blob appended to the START
    payload.
    """
    if len(app_image) != C.APP_IMAGE_SIZE:
        raise ValueError(
            f"application image must be {C.APP_IMAGE_SIZE} bytes, got "
            f"{len(app_image)}")

    header = app_image[:C.START_HEADER_LEN]
    body = app_image[C.START_HEADER_LEN:]

    counter = 0
    start = dfu.build_start_packet(counter, len(body), header, preface)
    _send_packet(dev, start)
    counter += 1

    checksum = 0
    for off in range(0, len(body), C.DATA_CHUNK_SIZE):
        data = body[off:off + C.DATA_CHUNK_SIZE]
        checksum = dfu.accumulate_checksum(checksum, data)
        _send_packet(dev, dfu.build_data_packet(counter, data))
        counter += 1
        if progress is not None:
            progress(min(off + len(data), len(body)), len(body))

    _send_packet(dev, dfu.build_end_packet(counter, checksum, len(body)))


def _feature_command(dev, report: bytes, timeout_ms: int = 3000) -> bytes:
    """Send a 91-byte feature report and return the raw response report."""
    from . import frame as _frame
    dev.send_feature_report(report)
    return dev.get_feature_report(0, C.FEATURE_REPORT_LEN)


def flash_secondary(dev, flash_image: bytes, packet_size: int = 0x50,
                    progress=None) -> None:
    """Flash the secondary FlashFW image through the app-mode bridge.

    Best-effort reconstruction of the .NET region workers (see
    ``analysis/PROTOCOL.md`` §7.2 and §8): query the region list, write the
    region ID list, stream the image in ``packet_size`` chunks over channel
    ``0x0a``, then erase/program/verify over channel ``0x10``.
    """
    from . import region

    # 1. Region info query.
    info_report = _feature_command(dev, region.build_region_info_report())
    info = region.parse_region_list_response(info_report)

    # 2. Region ID list write (one region, the FlashFW image).
    id_payload = region.build_region_list_payload(
        1, 1, info["type"], packet_size)
    _feature_command(dev, region.build_region_set_id_list_report(id_payload))

    # 3. Region data write, chunked.
    for off in range(0, len(flash_image), packet_size):
        chunk = flash_image[off:off + packet_size]
        _feature_command(dev, region.build_region_data_report(chunk))
        if progress is not None:
            progress(min(off + len(chunk), len(flash_image)), len(flash_image))

    # 4. Erase/program the region via the channel-0x10 DFU.  The DFU frame
    # carries a 5-byte prefix (length + address), so a program chunk is capped
    # at 75 bytes (the 80-byte payload budget).
    _feature_command(dev, region.build_dfu_erase_report(0, len(flash_image)))
    dfu_chunk = min(packet_size, 75)
    for off in range(0, len(flash_image), dfu_chunk):
        chunk = flash_image[off:off + dfu_chunk]
        _feature_command(dev, region.build_dfu_program_report(chunk, off))


def update(package, enter_boot: bool = True, flash_fw: bool = True,
           progress=None) -> None:
    """Run the full update: enter bootloader, flash the app image, then the
    secondary FlashFW image (best-effort).

    ``flash_fw`` toggles the secondary image flashing; its sequencing is
    reconstructed from the .NET workers and remains to be verified on-device.
    """
    if enter_boot:
        enter_bootloader(C.RAZER_VID, package.pid, C.APP_CONFIG_INTERFACE)
        dev = wait_for_device(C.RAZER_VID, package.bootloader_pid)
    else:
        dev = transport.open_by_interface(C.RAZER_VID, package.bootloader_pid, None)

    try:
        stream_firmware(dev, package.app_image, progress=progress)
    finally:
        dev.close()

    if flash_fw and package.flash_image:
        # The device reboots back into application mode after the app image is
        # flashed; the secondary image is then pushed through its bridge.
        dev = wait_for_device(C.RAZER_VID, package.pid)
        try:
            flash_secondary(dev, package.flash_image, progress=progress)
        finally:
            dev.close()
