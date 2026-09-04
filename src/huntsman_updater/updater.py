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
                    interface: int | None = None,
                    timeout_s: float = 30.0) -> "transport.HidDevice":
    """Poll until a HID device (``vid:pid``) appears, then open it.

    Used to await the bootloader (``1532:110E``, interface 0) after entering it
    and to await the application device (``1532:02B0``, interface 3) after the
    post-flash reboot.  The bootloader has no interrupt endpoints, so it is
    matched through the usbdevfs backend which needs the interface number.
    """
    deadline = time.monotonic() + timeout_s
    last_error: Exception | None = None
    while time.monotonic() < deadline:
        try:
            return transport.open_by_interface(vid, pid, interface)
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


def _dfu_send(dev, report: bytes, timeout_s: float = 8.0,
              poll_interval: float = 0.05) -> bytes:
    """Send a bootloader DFU feature report and poll for a settled response.

    The bootloader processes frames asynchronously: a response whose status is
    ``STATUS_NEW``/``STATUS_BUSY`` means the operation is still in flight, so
    we re-read the feature report until it settles (mirrors the
    ``FWUpdaterDLL`` send loop, which polls up to ``param_3`` times).
    """
    dev.send_feature_report(report)
    deadline = time.monotonic() + timeout_s
    response = b""
    while time.monotonic() < deadline:
        response = dev.get_feature_report(0, C.FEATURE_REPORT_LEN)
        if len(response) <= 1 + C.FRAME_STATUS:
            time.sleep(poll_interval)
            continue
        status = response[1 + C.FRAME_STATUS]
        if status not in (C.STATUS_NEW, C.STATUS_BUSY):
            break
        time.sleep(poll_interval)
    return response


def _dfu_status(response: bytes) -> int:
    if len(response) <= 1 + C.FRAME_STATUS:
        return -1
    return response[1 + C.FRAME_STATUS]


def flash_app_image(dev, app_image: bytes, progress=None) -> None:
    """Flash the application image through bootloader channel-0x10 DFU.

    Replicates the original .NET workers:

    1. ``DFUErase(StartAddr, EndAddr)``  — erase the 128 KiB app region;
    2. ``DFUProgram`` in 64-byte chunks  — stream the image;
    3. ``DFUExit``                        — reboot back into application mode.

    The address range is ``[0x20000000, 0x20020000)`` — the RAM-resident
    execution window the image's Intel HEX records target (confirmed against
    ``Talia_T1_60%_7203_App_FW_v2.1.0_E888780F.hex``).
    """
    from . import region

    if len(app_image) != C.APP_IMAGE_SIZE:
        raise ValueError(
            f"application image must be {C.APP_IMAGE_SIZE} bytes, got "
            f"{len(app_image)}")

    start = C.APP_RAM_LOAD_ADDRESS
    end = start + len(app_image)

    # 1. Erase the application region.
    resp = _dfu_send(dev, region.build_dfu_erase_report(start, end),
                     timeout_s=15.0)
    if _dfu_status(resp) != C.STATUS_SUCCESS:
        raise transport.TransportError(
            f"DFU erase failed (status {_dfu_status(resp)})")

    # 2. Program the image in 64-byte chunks.
    total = len(app_image)
    for off in range(0, total, C.APP_DFU_PACKLEN):
        chunk = app_image[off:off + C.APP_DFU_PACKLEN]
        resp = _dfu_send(dev, region.build_dfu_program_report(chunk, start + off))
        if _dfu_status(resp) != C.STATUS_SUCCESS:
            raise transport.TransportError(
                f"DFU program @ {start + off:#010x} failed "
                f"(status {_dfu_status(resp)})")
        if progress is not None:
            progress(min(off + len(chunk), total), total)

    # 3. Reboot into application mode.  The device resets while handling the
    # exit command, so the feature-report read may fail — that is expected.
    try:
        dev.send_feature_report(region.build_dfu_exit_report())
    except Exception:  # noqa: BLE001 - device reboots mid-transfer
        pass


def update(package, enter_boot: bool = True, flash_fw: bool = True,
           progress=None, config=None) -> None:
    """Flash the application image over the bootloader channel-0x10 DFU.

    Flow: enter the bootloader, open its single 90-byte feature-report
    interface, erase/program/exit, then wait for the device to re-enumerate in
    application mode.  ``flash_fw`` currently toggles the secondary FlashFW
    image path, whose sequencing is still best-effort.

    ``config`` is an optional :class:`~huntsman_updater.settings.DeviceConfig`
    overriding the target VID/PID/interface; when omitted the package metadata
    and defaults are used.
    """
    from .settings import DeviceConfig
    if config is None:
        config = DeviceConfig(
            vid=C.RAZER_VID,
            app_pid=package.pid,
            bootloader_pid=package.bootloader_pid,
            app_interface=C.APP_CONFIG_INTERFACE,
            bootloader_interface=C.BOOTLOADER_INTERFACE,
        )
    vid = config.vid
    app_pid = config.app_pid
    app_interface = config.app_interface
    bootloader_pid = config.bootloader_pid
    bootloader_interface = config.bootloader_interface

    if enter_boot:
        # If the device is already in the bootloader (e.g. entered via Fn+USB
        # or left over from an interrupted flash), skip the SET_MODE handshake
        # that would otherwise fail for want of the application device.
        from . import status as _status
        if _status.detect_mode(config) != _status.MODE_BOOTLOADER:
            enter_bootloader(vid, app_pid, app_interface)
        dev = wait_for_device(vid, bootloader_pid,
                              interface=bootloader_interface)
    else:
        dev = transport.open_by_interface(vid, bootloader_pid,
                                          bootloader_interface)

    try:
        flash_app_image(dev, package.app_image, progress=progress)
    finally:
        dev.close()

    # DFUExit reboots the device back into application mode.
    wait_for_device(vid, app_pid, interface=app_interface).close()

    if flash_fw and package.flash_image:
        dev = wait_for_device(vid, app_pid, interface=app_interface)
        try:
            flash_secondary(dev, package.flash_image, progress=progress)
        finally:
            dev.close()
