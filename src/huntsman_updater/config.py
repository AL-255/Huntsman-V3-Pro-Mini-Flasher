"""``update_config.ini`` handling.

The original updater configures its native engine through an INI file with the
sections and keys recovered here.  Only the subset relevant to flashing is
represented.
"""
from __future__ import annotations

from dataclasses import dataclass, field


@dataclass
class UpdateConfig:
    """Recovered ``update_config.ini`` content."""
    bootdev_info: str = "vid_1532&pid_02b0&mi_05"
    checksn: bool = False
    sn: str = ""
    upgrade_file: str = "firmware.bin"
    encryption_en: bool = False
    add_time: int = 1000
    time_out: int = 30
    app_start: int = 0

    @classmethod
    def defaults(cls) -> "UpdateConfig":
        return cls()

    def to_ini(self) -> str:
        """Serialize back to INI text (matches the recovered key names)."""
        checksn = "true" if self.checksn else "false"
        encryption = "1" if self.encryption_en else "0"
        return (
            "[BOOTDEVICE_INFO]\n"
            f"bootdev_info={self.bootdev_info}\n"
            f"checksn={checksn}\n"
            f"SN={self.sn}\n"
            "\n"
            "[BIN_FILE]\n"
            f"upgrade_file={self.upgrade_file}\n"
            "\n"
            "[ENCRY_EN]\n"
            f"encryption_en={encryption}\n"
            "\n"
            "[UPDATE_ADD_WAIT]\n"
            f"add_time={self.add_time}\n"
            "\n"
            "[WAIT_TIME_OUT]\n"
            f"time_out={self.time_out}\n"
            "\n"
            "[APP_START_ADDR]\n"
            f"app_start=0x{self.app_start:x}\n"
        )


def parse_bootdev_info(value: str) -> tuple[int, int, int]:
    """Parse ``vid_1532&pid_02b0&mi_05`` into (vid, pid, interface)."""
    vid = pid = mi = None
    for token in value.lower().split("&"):
        if token.startswith("vid_"):
            vid = int(token[4:], 16)
        elif token.startswith("pid_"):
            pid = int(token[4:], 16)
        elif token.startswith("mi_"):
            mi = int(token[3:])
    if vid is None or pid is None or mi is None:
        raise ValueError(f"cannot parse bootdev_info: {value!r}")
    return vid, pid, mi
