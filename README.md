# Huntsman V3 Pro Mini — independent firmware updater

A from-scratch reimplementation of the firmware update/flashing capability of
the Razer Huntsman V3 Pro Mini (RZ03-0499) firmware updater.

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
- `src/` — the new updater implementation (work in progress).

## Status

Reverse engineering is substantially complete and documented in
`analysis/PROTOCOL.md`. The implementation is under construction.

## Device facts

- Application mode: USB `1532:02B0` (HID config interface `mi_05`).
- Bootloader mode: USB `1532:110E` (bcdDevice `0x02B0`).
- Application firmware: 128 KiB image, RAM-resident at `0x20000000`.
- Secondary flash firmware: 37408 bytes (optionally encrypted).
