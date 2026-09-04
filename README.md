# Huntsman V3 Pro Mini — independent firmware updater

A from-scratch reimplementation of the firmware update/flashing capability of
the Razer Huntsman V3 Pro Mini (RZ03-0499) firmware updater.

> **Scope:** this project targets **only the Razer Huntsman V3 Pro Mini**
> (`1532:02B0`). The shared Razer updater DLLs also cover many other devices
> (PS4/PS5 controllers, wireless mice, Blade laptops, etc.); none of those are
> supported here.

The original updater (`HuntsmanV3ProMini_02B0_FirmwareUpdater_v2.01.00_r1.exe`)
is a .NET shell that drives two native DLLs (`Ry_Online_Update_Dll`,
`FWUpdaterDLL`) over HID and WinUSB. This project re-derives that protocol and
re-implements it as a standalone, scriptable updater.

## Layout

- `analysis/PROTOCOL.md` — the recovered flashing protocol specification.
- `analysis/native/` — Ghidra decompilation of the two native DLLs (evidence).
- `tools/` — analysis tooling used to produce the evidence above:
  - `dump_dotnet.py` — .NET metadata / P/Invoke / IL dumper.
  - `ghidra_scripts/DecompileNamed.java` — targeted Ghidra headless decompiler.
- `src/huntsman_updater/` — the updater package.
- `tests/` — unit tests for the pure protocol logic.

## Device facts

- Application mode: USB `1532:02B0` (6 interfaces; the 90-byte feature-report
  config interface is **interface 3**, the 64-byte DFU interface is
  **interface 5** = `mi_05`).
- Bootloader mode: USB `1532:110E` (bcdDevice `0x02B0`).
  - Entered by the host `SET_MODE` command, **or manually by plugging the USB
    cable in while holding `Fn`.**
- Application firmware: 128 KiB image, RAM-resident at `0x20000000`.
- Secondary flash firmware: 37408 bytes (the "7203" Optical-ASIC controller).

**Validated on hardware:** `huntsman-updater device-info` was run against a
physical Huntsman V3 Pro Mini and read back serial `PM2503F87401979`, firmware
version `1.04`, capability `01 34`, mode `0`, and build `00 00 01 00` (all with
matching response checksums). The feature-report interface has no kernel
driver, so on Linux the `usbdevfs` transport requires root.

## Implemented

| Capability | Module | Status |
| --- | --- | --- |
| Enter bootloader (`SET_MODE 0x04`) | `frame`, `updater` | byte-confirmed |
| Application-image DFU (`START/DATA/END` over 65-byte reports) | `dfu`, `updater` | byte-confirmed |
| Bootloader `getv` version query | `dfu` | confirmed |
| Device-info polling (version/serial/capability/mode/build/…) | `device` | confirmed |
| Secondary FlashFW region protocol (channel `0x0a`) | `region` | command encoders confirmed |
| Secondary FlashFW DFU (channel `0x10`) | `region` | command encoders confirmed |
| `DeviceUpdater.resources` parsing | `resources` | verified against real firmware |
| HID transport (hidapi + Linux hidraw) | `transport` | — |

## Usage

```sh
# install (optionally with the hidapi backend)
pip install -e .[hid]

# show what's in a DeviceUpdater.resources
huntsman-updater info DeviceUpdater.resources

# poll device information
huntsman-updater device-info

# flash both images (enters the bootloader automatically)
huntsman-updater flash DeviceUpdater.resources

# flash, assuming the device is already in the bootloader (Fn + USB)
huntsman-updater flash DeviceUpdater.resources --no-enter-boot
```

## Known limitations

- The 420/448-byte `START`-packet preface (appended after the 32-byte header)
  is not reproduced; its exact contents were not recovered.
- The secondary FlashFW erase/program/verify **sequencing** is reconstructed
  from the .NET worker IL and is best-effort; it has not been verified
  on-device.
- The `flashfw.bin` **encryption** (`encryption_en=1`) is not re-implemented —
  no standard crypto is linked into the updater binaries, and the `.enc`
  envelope is absent from the extracted artifacts.
- Nothing has been exercised against a physical keyboard (no device available
  in this environment).
