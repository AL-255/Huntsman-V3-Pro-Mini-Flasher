"""PyInstaller entry point for the graphical updater."""
from huntsman_updater.gui import main

if __name__ == "__main__":
    import sys
    sys.exit(main())
