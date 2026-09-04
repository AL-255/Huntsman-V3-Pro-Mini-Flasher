"""Tkinter GUI for the Razer Huntsman V3 Pro Mini updater.

Run with ``huntsman-updater-gui`` (installed) or ``python -m
huntsman_updater.gui``.  The entry point re-launches itself elevated when it
was started without root/administrator rights, so the device nodes can be
opened.
"""
from __future__ import annotations

import queue
import threading
import tkinter as tk
from pathlib import Path
from tkinter import filedialog, messagebox, ttk

from . import constants as C
from . import status, transport, updater
from .firmware import (parse_intel_hex, validate_app_image,
                       validate_flash_image)
from .resources import FirmwarePackage, load_firmware_package
from .settings import DeviceConfig
from .usbdev import UsbDevice, UsbInterface, enumerate_usb_devices

POLL_INTERVAL_MS = 2000


# --------------------------------------------------------------------------
# Firmware file selection
# --------------------------------------------------------------------------
def load_firmware_selection(app_path: str,
                            flash_path: str = "") -> FirmwarePackage:
    """Build a :class:`FirmwarePackage` from the selected file paths.

    The application image may be a ``.resources`` bundle, an Intel HEX file, or
    a raw 128 KiB binary.  The optional secondary flash image is a raw 37408
    byte binary (or comes from the ``.resources`` bundle).
    """
    app_path = Path(app_path)
    flash_path = Path(flash_path) if flash_path else None

    data = app_path.read_bytes()
    if data[:4] == b"\xce\xca\xef\xbe":  # .NET .resources magic 0xBEEFCACE
        pkg = load_firmware_package(app_path)
        app_image = pkg.app_image
        flash_image = pkg.flash_image
        metadata = pkg.metadata
    elif data[:1] == b":":  # Intel HEX
        app_image = validate_app_image(
            parse_intel_hex(data.decode("ascii", "replace")))
        flash_image = b""
        metadata = {"VID": "1532", "PID": "02B0",
                    "BLVID": "1532", "BLPID": "110E"}
    else:  # raw application binary
        app_image = validate_app_image(data)
        flash_image = b""
        metadata = {"VID": "1532", "PID": "02B0",
                    "BLVID": "1532", "BLPID": "110E"}

    if flash_path:
        flash_image = validate_flash_image(flash_path.read_bytes())

    return FirmwarePackage(app_image=app_image, flash_image=flash_image,
                           metadata=metadata)


# --------------------------------------------------------------------------
# The application window
# --------------------------------------------------------------------------
class HuntsmanUpdaterApp:
    """Tkinter window that polls device status and drives firmware flashing."""

    def __init__(self, root: tk.Tk) -> None:
        self.root = root
        self.root.title("Huntsman V3 Pro Mini Updater")
        self.root.minsize(420, 340)

        self._status_q: queue.Queue = queue.Queue()
        self._work_q: queue.Queue = queue.Queue()
        self._flashing = threading.Event()
        self._stop = threading.Event()
        self._device_config = DeviceConfig.defaults()
        self._custom_device = False

        self._build_widgets()
        self._start_poller()
        self.root.protocol("WM_DELETE_WINDOW", self._on_close)
        self.root.after(100, self._drain)

    # -- widget construction -------------------------------------------------
    def _build_widgets(self) -> None:
        pad = {"padx": 4, "pady": 2}

        status_frame = ttk.LabelFrame(self.root, text="Device status")
        status_frame.pack(fill="x", padx=6, pady=4)
        status_frame.columnconfigure(1, weight=1)
        status_frame.columnconfigure(3, weight=1)

        # Six fields laid out in two side-by-side columns so the frame stays
        # short enough for small screens.
        self._status_labels: dict[str, ttk.Label] = {}
        for row, (key, caption) in enumerate([
                ("mode", "Mode"), ("serial", "Serial"), ("version", "Version")]):
            ttk.Label(status_frame, text=caption).grid(
                row=row, column=0, sticky="w", **pad)
            lbl = ttk.Label(status_frame, text="—")
            lbl.grid(row=row, column=1, sticky="w", **pad)
            self._status_labels[key] = lbl
        for row, (key, caption) in enumerate([
                ("ext", "Ext. version"), ("capability", "Capability"),
                ("build", "Build")]):
            ttk.Label(status_frame, text=caption).grid(
                row=row, column=2, sticky="w", **pad)
            lbl = ttk.Label(status_frame, text="—")
            lbl.grid(row=row, column=3, sticky="w", **pad)
            self._status_labels[key] = lbl

        ttk.Button(status_frame, text="Refresh", command=self._refresh_now
                   ).grid(row=3, column=0, sticky="w", **pad)
        ttk.Button(status_frame, text="Advanced…", command=self._open_advanced
                   ).grid(row=3, column=1, sticky="w", **pad)

        files_frame = ttk.LabelFrame(self.root, text="Firmware file")
        files_frame.pack(fill="x", padx=6, pady=4)
        files_frame.columnconfigure(1, weight=1)

        ttk.Label(files_frame, text="Application image:").grid(
            row=0, column=0, sticky="w", **pad)
        self._app_path = tk.StringVar()
        ttk.Entry(files_frame, textvariable=self._app_path).grid(
            row=0, column=1, sticky="ew", **pad)
        ttk.Button(files_frame, text="Browse…",
                   command=self._browse_app).grid(row=0, column=2, **pad)

        # Secondary firmware flashing is collapsed behind this checkbox.
        self._flash_secondary = tk.BooleanVar(value=False)
        ttk.Checkbutton(
            files_frame, text="Flash secondary firmware",
            variable=self._flash_secondary,
            command=self._toggle_secondary).grid(
                row=1, column=0, columnspan=3, sticky="w", **pad)

        self._secondary_row = ttk.Frame(files_frame)
        self._secondary_row.grid(row=2, column=0, columnspan=3,
                                 sticky="ew", **pad)
        self._secondary_row.columnconfigure(1, weight=1)
        ttk.Label(self._secondary_row, text="Secondary image:").grid(
            row=0, column=0, sticky="w", **pad)
        self._flash_path = tk.StringVar()
        ttk.Entry(self._secondary_row, textvariable=self._flash_path).grid(
            row=0, column=1, sticky="ew", **pad)
        ttk.Button(self._secondary_row, text="Browse…",
                   command=self._browse_flash).grid(row=0, column=2, **pad)
        self._secondary_row.grid_remove()  # hidden until the box is checked

        actions = ttk.Frame(self.root)
        actions.pack(fill="x", padx=6, pady=4)
        self._flash_btn = ttk.Button(actions, text="Flash firmware",
                                     command=self._start_flash)
        self._flash_btn.pack(side="left", padx=3)
        ttk.Button(actions, text="Enter bootloader",
                   command=lambda: self._run_action("enter-bootloader")
                   ).pack(side="left", padx=3)
        ttk.Button(actions, text="Exit bootloader",
                   command=lambda: self._run_action("exit-bootloader")
                   ).pack(side="left", padx=3)

        self._progress = ttk.Progressbar(self.root, maximum=100)
        self._progress.pack(fill="x", padx=6, pady=4)

        log_frame = ttk.LabelFrame(self.root, text="Log")
        log_frame.pack(fill="both", expand=True, padx=6, pady=(0, 6))
        self._log = tk.Text(log_frame, height=5, state="disabled", wrap="word")
        self._log.pack(fill="both", expand=True, padx=3, pady=3)

    def _log_line(self, text: str) -> None:
        self._log.configure(state="normal")
        self._log.insert("end", text + "\n")
        self._log.see("end")
        self._log.configure(state="disabled")

    # -- file browsing -------------------------------------------------------
    def _browse_app(self) -> None:
        path = filedialog.askopenfilename(
            title="Select application firmware",
            filetypes=[("Firmware files", "*.resources *.bin *.hex"),
                       ("Razer resources", "*.resources"),
                       ("Binary image", "*.bin"),
                       ("Intel HEX", "*.hex"),
                       ("All files", "*.*")])
        if path:
            self._app_path.set(path)

    def _browse_flash(self) -> None:
        path = filedialog.askopenfilename(
            title="Select secondary flash firmware",
            filetypes=[("Binary image", "*.bin"), ("All files", "*.*")])
        if path:
            self._flash_path.set(path)

    def _toggle_secondary(self) -> None:
        """Show the secondary-file row only while its checkbox is checked."""
        if self._flash_secondary.get():
            self._secondary_row.grid()
        else:
            self._secondary_row.grid_remove()

    # -- advanced device selection ------------------------------------------
    def _open_advanced(self) -> None:
        """Open the advanced-settings dialog for a custom VID/PID/interface.

        The dialog shows a foldable tree of every visible USB device and its
        interfaces; selecting one fills the VID/PID/interface fields.
        """
        win = tk.Toplevel(self.root)
        win.title("Advanced settings")
        win.transient(self.root)
        win.geometry("520x560")
        win.minsize(420, 440)
        pad = {"padx": 6, "pady": 3}

        custom = tk.BooleanVar(value=self._custom_device)
        cfg = self._device_config

        fields: dict[str, tuple[tk.StringVar, ttk.Entry]] = {}

        def _set_fields() -> None:
            state = "normal" if custom.get() else "disabled"
            for _, entry in fields.values():
                entry.configure(state=state)

        ttk.Checkbutton(
            win, text="Use custom device VID/PID/interface",
            variable=custom, command=_set_fields).grid(
                row=0, column=0, columnspan=2, sticky="w", **pad)

        spec = [
            ("vid", "VID (hex)", f"{cfg.vid:04X}"),
            ("app_pid", "Application PID (hex)", f"{cfg.app_pid:04X}"),
            ("bootloader_pid", "Bootloader PID (hex)",
             f"{cfg.bootloader_pid:04X}"),
            ("app_interface", "Application interface", str(cfg.app_interface)),
            ("bootloader_interface", "Bootloader interface",
             str(cfg.bootloader_interface)),
        ]
        for i, (key, label, initial) in enumerate(spec, start=1):
            ttk.Label(win, text=label).grid(row=i, column=0, sticky="w", **pad)
            var = tk.StringVar(value=initial)
            entry = ttk.Entry(win, textvariable=var, width=14)
            entry.grid(row=i, column=1, sticky="w", **pad)
            fields[key] = (var, entry)
        _set_fields()

        # --- foldable USB device tree --------------------------------------
        ttk.Label(win, text="USB devices:").grid(
            row=6, column=0, sticky="w", **pad)
        ttk.Button(win, text="Refresh", command=self._populate_usb_tree
                   ).grid(row=6, column=1, sticky="e", **pad)

        tree_frame = ttk.Frame(win)
        tree_frame.grid(row=7, column=0, columnspan=2, sticky="nsew", **pad)
        tree_frame.rowconfigure(0, weight=1)
        tree_frame.columnconfigure(0, weight=1)

        tree = ttk.Treeview(tree_frame, show="tree", selectmode="browse",
                            height=8)
        tree.grid(row=0, column=0, sticky="nsew")
        scrollbar = ttk.Scrollbar(tree_frame, orient="vertical",
                                  command=tree.yview)
        scrollbar.grid(row=0, column=1, sticky="ns")
        tree.configure(yscrollcommand=scrollbar.set)

        self._usb_tree = tree
        self._usb_tree_data: dict[str, tuple[UsbDevice, UsbInterface | None]] \
            = {}

        def _on_select(_event) -> None:
            selection = tree.selection()
            if not selection:
                return
            item = self._usb_tree_data.get(selection[0])
            if item is None:
                return
            device, iface = item
            custom.set(True)
            _set_fields()
            fields["vid"][0].set(f"{device.vid:04X}")
            fields["app_pid"][0].set(f"{device.pid:04X}")
            if iface is not None:
                fields["app_interface"][0].set(str(iface.number))

        tree.bind("<<TreeviewSelect>>", _on_select)
        self._populate_usb_tree()

        def _ok() -> None:
            if not custom.get():
                self._custom_device = False
                self._device_config = DeviceConfig.defaults()
                self._log_line("Device selection: automatic (defaults).")
                win.destroy()
                return
            try:
                self._device_config = DeviceConfig.from_strings(
                    fields["vid"][0].get(),
                    fields["app_pid"][0].get(),
                    fields["bootloader_pid"][0].get(),
                    fields["app_interface"][0].get(),
                    fields["bootloader_interface"][0].get(),
                )
            except ValueError as exc:
                messagebox.showerror("Invalid device settings", str(exc),
                                     parent=win)
                return
            self._custom_device = True
            self._log_line(
                f"Device selection: custom "
                f"{self._device_config.vid:04X}:"
                f"{self._device_config.app_pid:04X} / bootloader "
                f"{self._device_config.bootloader_pid:04X}.")
            win.destroy()

        buttons = ttk.Frame(win)
        buttons.grid(row=8, column=0, columnspan=2, sticky="e", **pad)
        ttk.Button(buttons, text="OK", command=_ok).pack(side="left", padx=4)
        ttk.Button(buttons, text="Cancel", command=win.destroy).pack(
            side="left", padx=4)

        win.rowconfigure(7, weight=1)
        win.columnconfigure(1, weight=1)

    def _populate_usb_tree(self) -> None:
        """(Re)fill the advanced dialog's USB device tree."""
        tree = getattr(self, "_usb_tree", None)
        if tree is None:
            return
        tree.delete(*tree.get_children())
        self._usb_tree_data.clear()
        for i, dev in enumerate(enumerate_usb_devices()):
            dev_id = f"dev{i}"
            tree.insert("", "end", iid=dev_id, text=dev.label, open=False)
            self._usb_tree_data[dev_id] = (dev, None)
            for j, iface in enumerate(dev.interfaces):
                iface_id = f"dev{i}_if{j}"
                tree.insert(dev_id, "end", iid=iface_id, text=iface.label)
                self._usb_tree_data[iface_id] = (dev, iface)

    # -- status polling ------------------------------------------------------
    def _start_poller(self) -> None:
        threading.Thread(target=self._poll_loop, daemon=True).start()

    def _poll_loop(self) -> None:
        while not self._stop.is_set():
            if not self._flashing.is_set():
                try:
                    snap = status.read_device_status(self._device_config)
                except Exception as exc:  # noqa: BLE001
                    snap = exc
            else:
                snap = None
            self._status_q.put(snap)
            self._stop.wait(POLL_INTERVAL_MS / 1000.0)

    def _refresh_now(self) -> None:
        self._status_q.put("__refresh__")

    def _apply_status(self, snap) -> None:
        if snap == "__refresh__":
            return
        if snap is None:  # paused during a flash
            return
        if isinstance(snap, Exception):
            self._status_labels["mode"].configure(text="Error")
            self._status_labels["serial"].configure(text=str(snap))
            return

        def set_(key, text):
            self._status_labels[key].configure(text=text)

        set_("mode", snap.mode_label)
        if snap.mode == status.MODE_APP:
            set_("serial", snap.serial or "—")
            set_("version", f"{snap.version_str}"
                            f"  ({snap.version.hex(' ').upper()})")
            set_("ext", snap.extended_version.hex(" ").upper() or "—")
            set_("capability", snap.capability.hex(" ").upper() or "—")
            set_("build", snap.build.hex(" ").upper() or "—")
        else:
            for key in ("serial", "version", "ext", "capability", "build"):
                set_(key, "—")

    # -- flash / actions -----------------------------------------------------
    def _run_action(self, action: str) -> None:
        def work():
            try:
                if action == "enter-bootloader":
                    updater.enter_bootloader(
                        self._device_config.vid, self._device_config.app_pid,
                        self._device_config.app_interface)
                    self._work_q.put(("log", "Bootloader entry requested."))
                elif action == "exit-bootloader":
                    dev = transport.open_by_interface(
                        self._device_config.vid,
                        self._device_config.bootloader_pid,
                        self._device_config.bootloader_interface)
                    try:
                        from . import region
                        dev.send_feature_report(region.build_dfu_exit_report())
                        self._work_q.put(("log", "Exit-bootloader sent."))
                    finally:
                        dev.close()
            except Exception as exc:  # noqa: BLE001
                self._work_q.put(("log", f"ERROR: {exc}"))

        threading.Thread(target=work, daemon=True).start()

    def _start_flash(self) -> None:
        if self._flashing.is_set():
            return
        app_path = self._app_path.get().strip()
        if not app_path:
            messagebox.showerror("No firmware selected",
                                 "Select an application firmware file first.")
            return

        do_secondary = self._flash_secondary.get()
        flash_path = self._flash_path.get().strip() if do_secondary else ""
        if do_secondary and not flash_path:
            messagebox.showerror(
                "No secondary firmware selected",
                "The \"Flash secondary firmware\" box is checked, but no "
                "secondary image file was selected. Select one or uncheck "
                "the box.")
            return

        try:
            pkg = load_firmware_selection(app_path, flash_path)
        except Exception as exc:  # noqa: BLE001
            messagebox.showerror("Bad firmware file", str(exc))
            return

        if do_secondary:
            summary = (f"App image {len(pkg.app_image)} bytes + secondary "
                       f"{len(pkg.flash_image)} bytes.")
        else:
            summary = f"App image {len(pkg.app_image)} bytes."
        if not messagebox.askyesno(
                "Flash firmware",
                f"{summary}\n\nThis will erase and reprogram the keyboard's "
                "application firmware. Continue?"):
            return

        self._flash_btn.configure(state="disabled")
        self._progress.configure(value=0)
        self._flashing.set()
        self._log_line(f"Flashing {app_path} …")

        threading.Thread(target=self._flash_worker,
                         args=(pkg, do_secondary), daemon=True).start()

    def _flash_worker(self, pkg: FirmwarePackage, do_secondary: bool) -> None:
        try:
            def progress(done, total):
                pct = int(done * 100 / total) if total else 100
                self._work_q.put(("progress", pct))

            updater.update(pkg, enter_boot=True, flash_fw=do_secondary,
                           progress=progress, config=self._device_config)
            self._work_q.put(("log", "Flash complete."))
            self._work_q.put(("done", True))
        except Exception as exc:  # noqa: BLE001
            self._work_q.put(("log", f"ERROR: {exc}"))
            self._work_q.put(("done", False))

    # -- main-thread queue draining -----------------------------------------
    def _drain(self) -> None:
        try:
            while True:
                item = self._status_q.get_nowait()
                self._apply_status(item)
        except queue.Empty:
            pass

        try:
            while True:
                item = self._work_q.get_nowait()
                self._apply_work(item)
        except queue.Empty:
            pass

        self.root.after(100, self._drain)

    def _apply_work(self, item) -> None:
        kind = item[0]
        if kind == "log":
            self._log_line(item[1])
        elif kind == "progress":
            self._progress.configure(value=item[1])
        elif kind == "done":
            self._flashing.clear()
            self._flash_btn.configure(state="normal")
            if item[1]:
                self._progress.configure(value=100)
                self._log_line("The device has rebooted into application mode.")
            else:
                self._log_line("Flashing failed — see the log above.")

    def _on_close(self) -> None:
        if self._flashing.is_set():
            if not messagebox.askyesno(
                    "Flashing in progress",
                    "A flash is in progress. Closing now could leave the "
                    "keyboard in an incomplete state. Close anyway?"):
                return
        self._stop.set()
        self.root.destroy()


def main(argv: list[str] | None = None) -> int:
    """GUI entry point; re-launches elevated when necessary."""
    from . import elevate
    if not elevate.is_elevated():
        try:
            elevate.elevate()
        except elevate.ElevationError as exc:
            # No Tk window may be available if elevation itself failed;
            # print to stderr and exit non-zero.
            print(f"elevation failed: {exc}", file=__import__("sys").stderr)
            return 1
        return 0

    root = tk.Tk()
    HuntsmanUpdaterApp(root)
    root.mainloop()
    return 0


if __name__ == "__main__":
    import sys
    sys.exit(main())
