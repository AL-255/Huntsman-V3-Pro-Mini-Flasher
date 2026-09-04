"""PyInstaller entry point for the command-line updater."""
from huntsman_updater.cli import main

if __name__ == "__main__":
    import sys
    sys.exit(main())
