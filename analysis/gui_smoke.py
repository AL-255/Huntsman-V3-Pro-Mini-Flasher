import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "src"))

import tkinter as tk
from huntsman_updater import gui

root = tk.Tk()
app = gui.HuntsmanUpdaterApp(root)


def check():
    for k in ("mode", "serial", "version", "ext", "capability", "build"):
        print(f"{k:11s}: {app._status_labels[k].cget('text')}")
    root.destroy()


root.after(5000, check)
root.mainloop()
print("root poller smoke test done")
