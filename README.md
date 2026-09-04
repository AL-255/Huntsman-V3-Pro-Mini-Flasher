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

**Validated on hardware:** a physical Huntsman V3 Pro Mini was flashed from
firmware `1.04` to `2.01.00` with this implementation, then read back serial
`PM2503F87401979`, version `02 01`, capability `01 34`, mode `0`, and build
`00 00 01 00` (all with matching response checksums). On Linux the USB device
nodes are root-owned, so the CLI and GUI must run as root (the GUI requests
elevation automatically).

## Implemented

| Capability | Module | Status |
| --- | --- | --- |
| Enter bootloader (`SET_MODE 0x04`) | `frame`, `updater` | byte-confirmed |
| Application-image flash (bootloader channel-`0x10` DFU) | `region`, `updater` | verified on-device |
| Device-info polling (version/serial/capability/mode/build/…) | `device` | confirmed |
| Secondary FlashFW region protocol (channel `0x0a`) | `region` | command encoders confirmed |
| Secondary FlashFW DFU (channel `0x10`) | `region` | command encoders confirmed |
| `DeviceUpdater.resources` parsing | `resources` | verified against real firmware |
| HID transport (hidapi + Linux hidraw/usbdevfs) | `transport` | verified |
| GUI (status polling + file-select flashing + elevation) | `gui`, `status`, `elevate` | implemented |

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

# launch the graphical updater
huntsman-updater-gui
```

### GUI

`huntsman-updater-gui` opens a small desktop window that:

- polls the device every 2 seconds and shows its **mode** (application
  `02B0` / bootloader `110E` / absent), **serial number**, **firmware
  version**, extended version, capability, and build;
- lets you pick the application firmware to flash — a `.resources` bundle, an
  Intel HEX file, or a raw 128 KiB application `.bin`;
- flashes the application image with a progress bar and log, plus
  **Enter bootloader** / **Exit bootloader** recovery buttons.  The optional
  secondary (FlashFW) image is hidden behind a **"Flash secondary firmware"**
  checkbox that reveals a second file picker when checked.

The window is compact (minimum 420×340) so it fits small screens.

When it is launched without root/admin rights it re-launches itself elevated:

- **Windows** — the native UAC prompt;
- **macOS** — the native administrator dialog;
- **Linux** — the PolicyKit `pkexec` "Authentication Required" dialog, falling
  back to a small password window piped into `sudo -S`.

Run from a source checkout without installing: `python -m huntsman_updater.gui`
(with `PYTHONPATH=src`), or run it directly as root.

## Known limitations

- The 420/448-byte `START`-packet preface (appended after the 32-byte header)
  is not reproduced; its exact contents were not recovered.  (This belongs to
  the legacy 65-byte `Ry_Online_Update_Dll` stream, which the real
  Huntsman V3 Pro Mini does not use for the application image.)
- The secondary FlashFW erase/program/verify **sequencing** is reconstructed
  from the .NET worker IL and is best-effort; it has not been verified
  on-device (the application-image flash has been).
- The `flashfw.bin` **encryption** (`encryption_en=1`) is not re-implemented —
  no standard crypto is linked into the updater binaries, and the `.enc`
  envelope is absent from the extracted artifacts.
