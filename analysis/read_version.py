import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "src"))
from huntsman_updater import device
try:
    print("serial:", device.query_serial())
    v = device.query_version()
    print("version:", v.hex(" "), "-> major", v[0], "minor", v[1])
except Exception as e:
    import traceback
    traceback.print_exc()
