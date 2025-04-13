#!/bin/bash

# Script to set up CLion for QMK firmware development
# Specifically for keyboards/boardsource/unicorne/keymaps/MartyJRE/keymap.c

# Ensure we're in the QMK firmware root directory
if [ ! -f "Makefile" ] || [ ! -d "keyboards" ]; then
    echo "Error: This script must be run from the QMK firmware root directory."
    exit 1
fi

# Check if QMK CLI is installed
if ! command -v qmk &> /dev/null; then
    echo "Error: QMK CLI is not installed or not in PATH."
    echo "Please install it following the instructions at https://docs.qmk.fm/#/newbs_getting_started"
    exit 1
fi

echo "Building keyboard.h file for boardsource/unicorne..."
qmk generate-keyboard-h -kb boardsource/unicorne -o keyboards/boardsource/unicorne/keyboard.h

echo "Generating compilation database for boardsource/unicorne:MartyJRE..."
qmk generate-compilation-database -kb boardsource/unicorne -km MartyJRE

if [ -f "compile_commands.json" ]; then
    echo "Compilation database generated successfully!"
    echo ""
    echo "Now open your QMK firmware directory in CLion and configure it to use the compilation database:"
    echo "1. Go to CLion preferences/settings (File > Settings on Windows/Linux or CLion > Preferences on macOS)"
    echo "2. Navigate to 'Build, Execution, Deployment' > 'Compilation Database'"
    echo "3. Select 'File' radio button (not 'Project directory')"
    echo "4. Click the folder icon and browse to the compile_commands.json file in your QMK firmware repository root"
    echo "5. Make sure 'Compiler: Auto-detect' is selected"
    echo "6. Click 'Apply' and 'OK'"
    echo "7. If prompted to reload the project, click 'Yes'"
    echo "8. Wait for CLion to finish indexing the project"
    echo ""
    echo "CLion should now be able to properly analyze your keymap.c files."
    echo ""
    echo "If CLion still shows 'No Compilation database detected' after these steps:"
    echo "1. Close CLion completely"
    echo "2. Delete the .idea directory in your QMK firmware repository (rm -rf .idea)"
    echo "3. Reopen the project in CLion"
    echo "4. Follow the steps above again to configure the compilation database"
else
    echo "Error: Failed to generate compilation database."
    echo "Please check the output above for errors."
    exit 1
fi
