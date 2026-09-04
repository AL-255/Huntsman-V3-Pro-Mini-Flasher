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
  (`SET_MODE`, mode-select / enter-device-mode), observed from the host
  disassembly. The .NET layer calls it via `EnterBLMode()` with mode `1`.

The precise report byte positions for the `FWUpdaterDLL` frame differ from the
90-byte config frame above (that DLL is a generic updater shared across Razer
devices); the exact mapping to the 90-byte frame is still being reconciled.

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

### 4.2 Packet header (observed)

8-byte header, little-endian fields:

| Offset | Field | Notes |
| --- | --- | --- |
| 0 | command | `'1'`, `'2'`, `'3'` |
| 1 | counter | packet sequence byte |
| 2..3 | value | `app_size >> 2` (START/END) |
| 4..5 | length | data byte count (host reads `*(u16*)(pkt+4)`; total = length + 8) |
| 6..7 | flags | block count / mode |

START additionally carries a 32-byte file-header field and the FlashFW preface;
DATA carries up to 512 bytes; END carries a 32-bit checksum and a
date/time stamp.

### 4.3 Response / ACK

After each chunk the host reads a 65-byte report. Response byte 0 echoes the
command; a status byte (offset ~8) is `'6'` (`0x36`) for per-chunk ACK and
`'4'` (`0x34`) for the final completion ACK.

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

- Exact report-byte mapping of `FWUpdaterDLL` frame vs the 90-byte config frame.
- Exact byte-level layout of the DFU START/DATA/END packet header (offsets
  above are from host disassembly and may need one field reordered).
- FlashFW (`FlashFWSector`) encryption scheme.
- The bootloader's flash region/address map (where the app image is written).
