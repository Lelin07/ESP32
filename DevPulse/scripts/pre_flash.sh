#!/bin/bash

# Navigate to the script's directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

# Run the keyboard listener script
python3 "$PROJECT_ROOT/scripts/keyboard_listener.py"

# Flash the firmware using PlatformIO
cd "$PROJECT_ROOT" || exit
platformio run --target upload