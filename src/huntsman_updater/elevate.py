"""Privilege elevation for the GUI.

The keyboard's HID device nodes (``/dev/bus/usb/*`` on Linux, the HID stack on
Windows) are only writable by the superuser/administrator, so the updater has
to re-launch itself elevated before it can talk to the hardware.

* **Windows** — UAC prompt via ``ShellExecuteW(..., "runas", ...)``.
* **macOS**  — the native administrator dialog via ``osascript ... with
  administrator privileges``.
* **Linux**  — ``pkexec`` (the PolicyKit graphical "Authentication Required"
  dialog) when available, falling back to a Tk password dialog piped to
  ``sudo -S``.
"""
from __future__ import annotations

import os
import shlex
import shutil
import subprocess
import sys

_GUI_MODULE = "huntsman_updater.gui"


class ElevationError(RuntimeError):
    """Raised when re-launching with elevated privileges fails/cancels."""


def is_elevated() -> bool:
    """True when the current process can already access the device nodes."""
    if os.name == "nt":
        try:
            import ctypes
            return bool(ctypes.windll.shell32.IsUserAnAdmin())
        except Exception:  # noqa: BLE001 - non-Windows ctypes shim
            return False
    return hasattr(os, "geteuid") and os.geteuid() == 0


def elevate() -> None:
    """Re-launch this GUI elevated.

    On success the *current* process exits and the elevated child takes over
    (so this function does not return in that case).  It raises
    :class:`ElevationError` when elevation fails or the user cancels.

    The child is re-launched as ``python -m huntsman_updater.gui`` (to keep the
    package import context), except inside a PyInstaller-frozen executable,
    where it just re-runs the binary itself with any extra CLI arguments.
    """
    if getattr(sys, "frozen", False):
        argv = [sys.executable, *sys.argv[1:]]
    else:
        argv = [sys.executable, "-m", _GUI_MODULE, *sys.argv[1:]]

    if os.name == "nt":
        _elevate_windows(argv)
    elif sys.platform == "darwin":
        _elevate_macos(argv)
    else:
        _elevate_linux(argv)


def _elevate_windows(argv: list[str]) -> None:
    import ctypes
    params = subprocess.list2cmdline([sys.executable, *argv[1:]])
    ret = ctypes.windll.shell32.ShellExecuteW(
        None, "runas", sys.executable, params, None, 1)
    if ret <= 32:  # ShellExecute returns the instance handle on success
        raise ElevationError(f"UAC elevation failed (ShellExecuteW -> {ret})")
    sys.exit(0)


def _elevate_macos(argv: list[str]) -> None:
    inner = subprocess.list2cmdline([sys.executable, *argv[1:]])
    script = (f'do shell script {shlex.quote(inner)} '
              "with administrator privileges")
    proc = subprocess.run(["osascript", "-e", script])
    if proc.returncode != 0:
        raise ElevationError("administrator authorization failed/cancelled")
    sys.exit(0)


def _elevate_linux(argv: list[str]) -> None:
    # Preferred: pkexec shows the native PolicyKit authentication dialog.
    if shutil.which("pkexec"):
        cmd = ["pkexec"]
        # pkexec runs a sanitized environment; hand the GUI display variables
        # through explicitly so the elevated Tk window can open.
        for var in ("DISPLAY", "XAUTHORITY", "WAYLAND_DISPLAY",
                    "XDG_RUNTIME_DIR", "DBUS_SESSION_BUS_ADDRESS"):
            if os.environ.get(var):
                cmd += ["env", f"{var}={os.environ[var]}"]
        cmd += [sys.executable, *argv[1:]]
        try:
            os.execvpe("pkexec", cmd, os.environ)
        except OSError as exc:
            raise ElevationError(f"pkexec failed to start: {exc}") from exc
        # execvpe replaces the process on success; it never returns.

    # Fallback: a Tk password dialog piped into sudo -S.
    password = _ask_password_tk()
    if password is None:
        raise ElevationError("root password prompt cancelled")

    proc = subprocess.Popen(
        ["sudo", "-S", "-p", "", sys.executable, *argv[1:]],
        stdin=subprocess.PIPE)
    try:
        proc.communicate((password + "\n").encode("utf-8"))
    finally:
        proc.stdin.close()
    if proc.returncode != 0:
        raise ElevationError("sudo elevation failed (wrong password?)")
    sys.exit(0)


def _ask_password_tk() -> str | None:
    """Show a minimal password prompt and return the entered password."""
    import tkinter as tk
    from tkinter import simpledialog

    root = tk.Tk()
    root.withdraw()
    root.title("Root access required")
    try:
        return simpledialog.askstring(
            "Root access required",
            "This updater needs root access to talk to the keyboard.\n"
            "Enter your password:",
            show="*", parent=root)
    finally:
        root.destroy()
