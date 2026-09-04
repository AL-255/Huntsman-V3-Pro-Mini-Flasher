# -*- mode: python ; coding: utf-8 -*-
"""PyInstaller spec: build onefile executables for the GUI and CLI.

Run from anywhere:

    pyinstaller packaging/huntsman_updater.spec

This produces ``dist/huntsman-updater-gui`` and ``dist/huntsman-updater``
(plus the platform suffix, e.g. ``.exe`` on Windows).
"""
import os

from PyInstaller.utils.hooks import collect_all  # noqa: E402

_spec_root = os.path.abspath(SPECPATH)                       # noqa: F821
_project_root = os.path.abspath(os.path.join(_spec_root, os.pardir))

datas = []
binaries = []
hiddenimports = ["tkinter"]

# hidapi is the transport backend on Windows/macOS (and optional on Linux).
# Bundle it when it is importable so the frozen binary can open the device.
try:
    h_datas, h_binaries, h_hidden = collect_all("hid")
    datas += h_datas
    binaries += h_binaries
    hiddenimports += h_hidden
except Exception:  # noqa: BLE001 - hidapi is optional on Linux
    pass


def _build(script, name, console):
    a = Analysis(
        [os.path.join(_spec_root, script)],
        pathex=[os.path.join(_project_root, "src")],
        binaries=binaries,
        datas=datas,
        hiddenimports=hiddenimports,
        hookspath=[],
        runtime_hooks=[],
        excludes=[],
        noarchive=False,
    )
    pyz = PYZ(a.pure)
    return EXE(
        pyz,
        a.scripts,
        a.binaries,
        a.datas,
        [],
        name=name,
        debug=False,
        bootloader_ignore_signals=False,
        strip=False,
        upx=False,
        upx_exclude=[],
        runtime_tmpdir=None,
        console=console,
        disable_windowed_traceback=False,
        argv_emulation=False,
        target_arch=None,
        codesign_identity=None,
        entitlements_file=None,
    )


gui = _build("gui_launcher.py", "huntsman-updater-gui", console=False)
cli = _build("cli_launcher.py", "huntsman-updater", console=True)
