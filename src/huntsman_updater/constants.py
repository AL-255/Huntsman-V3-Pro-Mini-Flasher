"""Device and protocol constants for the Huntsman V3 Pro Mini updater.

All values were recovered from the original updater toolchain and are
documented in ``analysis/PROTOCOL.md``.
"""
from __future__ import annotations

# --- USB identity -----------------------------------------------------------
RAZER_VID = 0x1532

# Application mode: the keyboard enumerates as a composite device.  Interface 3
# carries the 90-byte HID *feature* report used for device-information queries;
# interface 5 ("mi_05" in the bootdev_info string) carries the 64-byte
# input/output reports used by the DFU stream.
APP_PID = 0x02B0
APP_CONFIG_INTERFACE = 3   # 90-byte feature-report config interface
APP_DFU_INTERFACE = 5      # 64-byte I/O ("mi_05") interface

# Bootloader mode: after the "enter bootloader" command the LPC5528 reboots
# and re-enumerates with this PID (device descriptor bcdDevice == 0x02B0).
# The bootloader exposes a single interface (0) carrying the 90-byte HID
# feature report; it has no interrupt endpoints, so it is reached through the
# raw usbdevfs backend (SET_REPORT/GET_REPORT).
BOOTLOADER_PID = 0x110E
BOOTLOADER_BCD_DEVICE = 0x02B0
BOOTLOADER_INTERFACE = 0

# --- Application-mode command frame ----------------------------------------
# The keyboard exposes a 91-byte HID *feature* report: one report-id byte (0)
# followed by a 90-byte Razer command frame.
FEATURE_REPORT_LEN = 91          # 0x5b, matches FeatureReportLen resource
COMMAND_FRAME_LEN = 90

# Frame field offsets (confirmed against the firmware reconstruction's
# RZ0499_layout.h).  Frame byte i lives at report byte i + 1.
FRAME_STATUS = 0
FRAME_PAYLOAD_COUNT = 5
FRAME_CHANNEL = 6
FRAME_OPCODE = 7
FRAME_PAYLOAD = 8                 # payload bytes 8..87
FRAME_CHECKSUM = 88               # XOR of frame bytes 2..87
FRAME_EXTENSION = 89

# Command status values.
STATUS_NEW = 0
STATUS_BUSY = 1
STATUS_SUCCESS = 2
STATUS_FAILURE = 3

# Channel selectors.
CHANNEL_DEVICE = 0x00

# Channel-0 opcodes (the "device" command family), from the firmware's
# device.c.  Read opcodes poll device information; write opcodes configure it.
OPCODE_WRITE_IDENTIFIER = 0x02
OPCODE_ENTER_DEVICE_MODE = 0x04    # SET_MODE: mode-select / enter-bootloader
OPCODE_WRITE_PAIR = 0x06
OPCODE_DEVICE_RESTORE = 0x0B
OPCODE_WRITE_PROFILE_TIMER = 0x40

OPCODE_QUERY_VERSION = 0x81          # 2-byte version
OPCODE_READ_CONFIGURATION = 0x82     # 22-byte identifier / serial number
OPCODE_QUERY_CAPABILITY = 0x83       # 2-byte capability
OPCODE_QUERY_MODE = 0x84             # 1-byte mode
OPCODE_QUERY_PAIR = 0x86             # 2-byte pair
OPCODE_QUERY_EXTENDED_VERSION = 0x87  # 8-byte full firmware version
OPCODE_QUERY_BUILD = 0x9F            # 4-byte build
OPCODE_QUERY_PROFILE_TIMER = 0xC0    # 2-byte profile timer

# Response payload sizes (bytes) for the channel-0 read queries (verified
# against a physical Huntsman V3 Pro Mini).
DEVICE_QUERY_RESPONSE_SIZES = {
    OPCODE_QUERY_VERSION: 2,
    OPCODE_READ_CONFIGURATION: 22,
    OPCODE_QUERY_CAPABILITY: 2,
    OPCODE_QUERY_MODE: 1,
    OPCODE_QUERY_PAIR: 2,
    OPCODE_QUERY_EXTENDED_VERSION: 4,
    OPCODE_QUERY_BUILD: 4,
    OPCODE_QUERY_PROFILE_TIMER: 2,
}

# --- Bootloader-mode DFU ---------------------------------------------------
# The bootloader exposes 65-byte HID *input/output* reports: report id 0 plus
# a 64-byte payload.  Firmware is streamed as START/DATA/END packets split
# into 64-byte chunks.
DFU_REPORT_LEN = 65
DFU_PAYLOAD_LEN = 64
DFU_CHUNK_LEN = 64

# Packet command bytes.
DFU_CMD_START = ord("1")          # 0x31
DFU_CMD_DATA = ord("2")           # 0x32
DFU_CMD_END = ord("3")            # 0x33

# Packet header field offsets (confirmed from disassembly).
DFU_HDR_COMMAND = 0
DFU_HDR_COUNTER = 1
DFU_HDR_VALUE = 2                 # uint16 LE: app_size >> 2 (END) / counter (START)
DFU_HDR_LENGTH = 4                # uint16 LE: payload length (total = 8 + length)
DFU_HDR_FLAG = 6                  # 1 on START
DFU_HDR_BLOCK_COUNT = 7           # block count on START
DFU_HDR_BYTES = 8

# START packet payload layout.
DFU_START_SIZE = 8                # uint32 LE total payload size (image bytes)
DFU_START_HEADER = 12             # 32-byte firmware file header

# END packet payload layout (12-byte payload).
DFU_END_CHECKSUM = 8              # uint32 LE accumulated XOR checksum
DFU_END_DAY = 12
DFU_END_MONTH = 13
DFU_END_YEAR = 14                 # uint16 LE
DFU_END_SECOND = 16
DFU_END_MINUTE = 17
DFU_END_HOUR = 18                 # uint16 LE

# Response (64-byte input report payload) fields.
DFU_RESP_ECHO = 0
DFU_RESP_STATUS = 8
DFU_RESP_ACK = ord("6")           # 0x36 per-chunk acknowledgement
DFU_RESP_DONE = ord("4")          # 0x34 final completion

# Firmware geometry.
APP_IMAGE_SIZE = 0x20000          # 128 KiB application image
APP_RAM_LOAD_ADDRESS = 0x20000000  # RAM-resident execution address
DATA_CHUNK_SIZE = 0x200           # 512-byte DFU data chunks
START_HEADER_LEN = 0x20           # 32-byte header carried in the START packet

# Bootloader channel-0x10 DFU (the real application-flash path, confirmed from
# FWUpdaterDLL::DFUErase/DFUProgram/DFUVerify).  The .NET orchestrator erases
# the whole ``[APP_RAM_LOAD_ADDRESS, APP_RAM_LOAD_ADDRESS + APP_IMAGE_SIZE)``
# region and streams the image in ``Common.PACKLEN`` = 64-byte program chunks.
APP_DFU_PACKLEN = 64
