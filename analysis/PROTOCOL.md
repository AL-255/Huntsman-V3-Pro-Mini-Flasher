# Huntsman V3 Pro Mini firmware update protocol

This document records the host-side flashing protocol recovered from the
original updater toolchain (`CustomerFWU2Point5.exe`,
`Ry_Online_Update_Dll_ouput_v1.0.1.dll`, `FWUpdaterDLL.dll`) and cross-checked
against the clean-room firmware reconstruction in `../extracted_firmware`.

Recovered artifacts are labelled **confirmed** (backed by byte-level evidence
from the device side or unambiguous host code), **observed** (read directly
from host disassembly), or **inferred** (engineering interpretation pending
further confirmation).

## 1. Device identity

| Role | VID | PID | bcdDevice | Notes |
| --- | --- | --- | --- | --- |
| Application (keyboard) | `0x1532` | `0x02B0` | — | composite device; HID config interface = `mi_05` |
| Bootloader | `0x1532` | `0x110E` | `0x02B0` | entered by host command, then flashed |

These come from the `.resources` metadata (`VID`, `PID`, `BLVID`, `BLPID`,
`BCDPID_BL`) and from `update_config.ini` (`bootdev_info=vid_1532&pid_02B0&mi_05`).

### 1.1 Entering bootloader mode

There are two ways to put the keyboard into its bootloader (`1532:110E`):

1. **Host command** (what the updater uses): send the channel-0 `SET_MODE`
   opcode `0x04` with mode `1` (see §3.3). The firmware raises its mode-one
   reset request, writes the persistent reset cookie `0xaaaaaaaa` and performs
   a system reset into the bootloader.

2. **Manual** (hardware-level, e.g. for a bricked or unresponsive device):
   **connect the USB cable while holding the `Fn` key down.** This forces the
   keyboard to power on directly into the bootloader, where it enumerates as
   `1532:110E` and is ready to accept the DFU stream without any application
   mode handshake.

## 2. Two HID transports

The update uses two distinct HID report protocols:

1. **Application mode** (`1532:02B0`, interface 5): 91-byte **feature reports**
   carrying the keyboard's 90-byte Razer command frame. Used to query the
   serial number and to request entry into the bootloader.

2. **Bootloader mode** (`1532:110E`): 65-byte **input/output reports**
   (report id + 64-byte payload) carrying the DFU packet stream.

A third, auxiliary transport is **WinUSB** (vendor control transfers, request
`0x83`) used for a checksum read-back after flash verification.

## 3. Application-mode command frame (91-byte feature report)

`FeatureReportLen` is `91` (0x5b). The report is:

```
byte 0        : report id = 0
bytes 1..90   : the 90-byte Razer command frame
```

The 90-byte command frame layout is **confirmed** from the firmware
reconstruction (`RZ0499_layout.h`):

| Offset | Name | Meaning |
| --- | --- | --- |
| 0 | status | request `0`; response `1`=busy, `2`=success, `3`=failure |
| 2..4 | — | (covered by the checksum) |
| 5 | payload_count | payload length / item count |
| 6 | channel | command channel selector |
| 7 | opcode | operation code |
| 8..87 | payload | 80-byte payload |
| 88 | checksum | XOR of frame bytes 2..87 |
| 89 | — | extension byte (present in the 91-byte transfer) |

So in the HID report, `channel` = report byte 7 and `opcode` = report byte 8.

### 3.1 Channel-0 device command family

The channel-0 handler is the "device" command family. It exposes both write
opcodes (configuration) and read opcodes (device-information polling), with
the response payload sizes listed below (**confirmed** from the firmware's
`device.c`):

| Opcode | Name | Response |
| --- | --- | --- |
| `0x81` | QUERY_VERSION | 2 bytes (version0, version1) |
| `0x82` | QUERY_IDENTIFIER | 22 bytes (serial number / config blob) |
| `0x83` | QUERY_CAPABILITY | 2 bytes |
| `0x84` | QUERY_MODE | 1 byte |
| `0x86` | QUERY_PAIR | 2 bytes |
| `0x87` | QUERY_EXTENDED_VERSION | 8 bytes (4 version + 4 extended) |
| `0x9f` | QUERY_BUILD | 4 bytes |
| `0xc0` | QUERY_PROFILE_TIMER | 2 bytes |

Write opcodes: `0x02` WRITE_IDENTIFIER, `0x04` SET_MODE (enter device mode /
bootloader), `0x06` WRITE_PAIR, `0x0b` RESTORE, `0x40` WRITE_PROFILE_TIMER.

### 3.2 Serial number query

- channel `0x00`, opcode `0x82` (`QUERY_IDENTIFIER`), payload_count `0x16`
  (22). Returns the 22-byte device payload (serial number / config blob).

Observed on the host (`Ry_Online_Update_Dll` `FUN_10002d30`): it builds a
report with report[6]=0x16, report[7]=0x00, report[8]=0x82, folds a checksum
over the report, sends `HidD_SetFeature(91)` and reads `HidD_GetFeature(91)`;
the response echoes report[6..8] and carries status in report[1].

### 3.3 Enter bootloader / device mode

- `FWUpdaterDLL.dll::EnterDeviceMode(handle, mode)` sends opcode `0x04`
  (`SET_MODE`), **confirmed** from its disassembly. The .NET layer calls it via
  `EnterBLMode()` with mode `1`.

The exact 91-byte feature report (**confirmed** byte-for-byte from
`EnterDeviceMode`'s disassembly, mapped onto the 90-byte frame as
`frame[i] == report[i+1]`):

| Report offset | Frame field | Value |
| --- | --- | --- |
| 0 | report id | `0` (or `7`/`8` for other Razer device families) |
| 1 | status | `0` |
| 2..5 | header | `0` |
| 6 | payload_count | `2` |
| 7 | channel | `0x00` |
| 8 | opcode | `0x04` (SET_MODE) |
| 9 | payload[0] | mode = `1` |
| 10 | payload[1] | `0` |
| 89 | checksum | `0` (the generic `FWUpdaterDLL` path does not compute it; the firmware does not validate it) |

On receipt, the firmware sets `MODE_ONE_RESET_REQUEST`, writes the persistent
reset cookie `0xaaaaaaaa` to `0x2002FFFC`, and performs `NVIC_SystemReset`,
after which the ROM/on-flash bootloader takes over and re-enumerates as
`1532:110E`.

## 4. Bootloader-mode DFU (65-byte input/output reports)

The DFU engine (`Ry_Online_Update_Dll` `FUN_10006650`) opens the bootloader
device and streams the firmware as a sequence of packets, each sent in 64-byte
chunks via `WriteFile` (65 bytes = report id `0` + 64 payload) and acknowledged
by `ReadFile`.

### 4.1 Packet types

| Command byte | Name | Payload |
| --- | --- | --- |
| `0x31` (`'1'`) | START | app address/size, version, block count, 32-byte header + flash-FW preface |
| `0x32` (`'2'`) | DATA | one 512-byte firmware chunk |
| `0x33` (`'3'`) | END | accumulated checksum + timestamp |

### 4.2 Packet header (confirmed from `FUN_10006650` disassembly)

8-byte header, little-endian fields:

| Offset | Field | Notes |
| --- | --- | --- |
| 0 | command | `'1'`, `'2'`, `'3'` |
| 1 | counter | packet sequence byte |
| 2..3 | value | START: counter (16-bit); END: `app_size >> 2` |
| 4..5 | length | payload byte count (total = length + 8) |
| 6 | flag | `1` on START |
| 7 | block_count | block count on START |

Payloads:

- **START**: `[8..11]` = total payload size (uint32 LE, = application image
  size); `[12..43]` = 32-byte firmware-file header; `[44..]` = fixed preface
  (420 or 448 bytes in the original stream).
- **DATA**: `[8..519]` = up to 512 firmware bytes.
- **END** (length 12): `[8..11]` = accumulated XOR checksum (uint32 LE);
  `[12]`=day, `[13]`=month, `[14..15]`=year, `[16]`=second, `[17]`=minute,
  `[18..19]`=hour.

### 4.3 Response / ACK

After each chunk the host reads a 65-byte report. Response byte 0 echoes the
command; a status byte (offset ~8) is `'6'` (`0x36`) for per-chunk ACK and
`'4'` (`0x34`) for the final completion ACK.

### 4.4 Bootloader version query ("getv")

Before streaming, `FUN_10004000` sends a 12-byte **get version** command over
the same 65-byte output-report channel:

```
30 00 00 00 | 04 00 00 00 | "getv"
```

The response echoes `0x30` and carries a `0x10` marker at `[4..5]` and two
version words at `[6..7]` / `[8..9]` (big-endian), which the host reads as the
bootloader firmware version.

## 5. WinUSB checksum control

`FWUpdaterDLL.dll::ControlIn/ControlOut` wrap `WinUsb_ControlTransfer`:

- OUT: bmRequestType `0x40` (vendor, host→device), bRequest = arg, wValue, wIndex, wLength.
- IN:  bmRequestType `0xC0` (vendor, device→host), same fields.

The .NET `callWinusbChecksumControl(handle, bRequest, ref checksum)` sends a
control OUT with `0x83` and reads back a 16-bit checksum
(`(buf[0]<<8)|buf[1]`) via control IN.

## 6. Configuration file (`update_config.ini`)

The updater writes/reads an INI file. Recovered keys:

```ini
[BOOTDEVICE_INFO]
bootdev_info=vid_1532&pid_02B0&mi_05
checksn=false
SN=<serial when checksn=true>

[BIN_FILE]
upgrade_file=Talia_T1_60%_7203_App_FW_v2.1.0_E888780F.enc

[ENCRY_EN]
encryption_en=1

[UPDATE_ADD_WAIT]
add_time=1000

[WAIT_TIME_OUT]
time_out=30

[APP_START_ADDR]
app_start=0x20000000
```

## 7. Firmware payloads

| Resource / file | Size | Role |
| --- | --- | --- |
| `DevFWLine*` (Intel HEX) | 131072 B | primary application image, loads at `0x20000000` |
| `FlashFWSector*` (byte arrays) | 37408 B | secondary "flash FW" image (encrypted when `encryption_en=1`) |

### 7.1 Firmware file envelope (`upgrade_file`)

The `Ry_Online_Update_Dll` engine streams a single firmware file. Its
structure is **confirmed** from `FUN_10006650`:

- The file is `[32-byte header][payload]` where the payload is the application
  image (128 KiB). The 32-byte header is what the START packet carries at
  `[12..43]`; the payload is streamed as 512-byte DATA packets.
- Integrity: the whole file is XOR-folded into a 32-bit checksum and compared
  against the `%08x` value embedded in the filename (e.g. `E888780F` from
  `..._v2.1.0_E888780F.enc`).
- The secondary FlashFW image is a **separate** payload (`flashfw.bin` /
  `FlashFWSector*`) flashed by a distinct route, not part of this stream.

### 7.2 Secondary "flash FW" route (region protocol)

The secondary image (`FlashFWSector*`, 37408 bytes) is the firmware for the
secondary controller (the "7203" Optical-ASIC part referenced by the app
firmware's Flexcomm3 SPI bridge). The .NET layer flashes it through the main
MCU using a distinct, region-based protocol rather than the DFU stream:

1. `UpdateENCCFG("flashfw.bin", …)` rewrites `update_config.ini` with
   `[BIN_FILE] upgrade_file=flashfw.bin` and
   `[BOOTDEVICE_INFO] bootdev_info=vid_{VID}&pid_{PID}&mi_05`, then the image
   is written to `\update\flashfw.bin`.
2. The region workers drive a `SendCmd`-based command exchange over the
   91-byte feature-report channel on **channel `0x0a`** (**confirmed** from the
   .NET worker IL):

   | Command | Opcode | Report bytes | Payload |
   | --- | --- | --- | --- |
   | region list | `0x00` | channel `0x0a`, payload_count = payload len | `[total, RegionID, type, packetsize]` (16-bit LE each) |
   | region data | `0x02` | channel `0x0a`, `frame[2..3] = 0xff 0xff`, payload_count = chunk len | one chunk of `flashfw.bin` |

   The region-list **response** is a 16-bit-element array:
   `[0]=total`, `[1]=RegionID`, `[2]=type`, and `region_size` assembled from
   elements 4..7 as `el[4]<<24 | el[5]<<16 | el[6]<<8 | el[7]` (equals the
   FlashFW size, 37408 bytes).
3. The actual region programming uses a second command family on **channel
   `0x10`** (the secondary DFU channel, **confirmed** from
   `FWUpdaterDLL::DFUErase/DFUProgram/DFUVerify` disassembly):

   | Opcode | Command | Payload |
   | --- | --- | --- |
   | `0x01` | erase | `address` (BE u32) + `size` (BE u32) |
   | `0x02` | program | 1-byte length + `address` (BE u32) + data |
   | `0x83` | verify | 1-byte length + `address` (BE u32) |
   | `0x04` | abort | — |
   | `0x05` | exit | — |
4. Verification uses the WinUSB control-transfer channel (`0x83`,
   `callWinusbChecksumControl`) to read back a 16-bit checksum.

The region-list/region-data and channel-`0x10` DFU command encoders are
implemented in `src/huntsman_updater/region.py`; the exact erase/program/verify
sequencing and device mode (application vs bootloader) remain open items.

The firmware filename embeds a version (`%04x`) and a checksum (`%08x`), e.g.
`..._v2.1.0_E888780F.enc`. The host parses the `0x30`-offset `"getv"` magic in
the firmware file header to validate it before streaming.

## 8. Orchestration

`CustomerFWU2Point5.exe` (per the `backgroundWorker_RyCoreUpdate` worker):

1. Extract firmware from `DeviceUpdater.resources`, write `update_config.ini`
   and the firmware file.
2. `UserSetCfgFilePath(dir, file)`.
3. `chipGoToBootFirmware(callback)` — find device, verify serial, prepare.
4. `appUpdateFirmware(callback)` — stream the firmware via the DFU engine.

Progress/state callbacks use the `UPDATE_STATE` values
`STATE_DEV_ENT_BOOT_MODE`, `STATE_CHECK_HID_DEVICE`, `STATE_SEND_START_PACKET`,
`STATE_SEND_DATA_PACKET`, `STATE_SEND_END_PACKET`, `STATE_EXIT_UPGRADE`.

## 9. Open items

- The exact 32-byte firmware-file header content and the 420/448-byte START
  packet preface.
- The FlashFW region-protocol command bytes (the `SendCmd` region metadata
  encoding) and the `flashfw.bin` encryption scheme.
- The bootloader's flash region/address map (where the app image is written).

## 10. Scope

This protocol document and the accompanying `src/huntsman_updater/`
implementation target **only the Razer Huntsman V3 Pro Mini** (RZ03-0499,
`1532:02B0`). The other VID/PID pairs and device families that appear in the
shared `FWUpdaterDLL.dll` / `CustomerFWU2Point5.exe` binaries (PS4/PS5
controllers, wireless mice, other Blade laptops, etc.) are explicitly out of
scope.
