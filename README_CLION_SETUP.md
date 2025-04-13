# Setting up CLion for QMK Firmware Development

This guide explains how to set up CLion to properly analyze QMK firmware files, specifically keymap.c files like `keyboards/boardsource/unicorne/keymaps/MartyJRE/keymap.c`.

## Prerequisites

- QMK firmware repository cloned
- QMK CLI installed and configured
- CLion installed

## Steps to Set Up CLion

### 1. Generate a Compilation Database

QMK provides a command to generate a compilation database (`compile_commands.json`) that CLion can use to understand the project structure, include paths, and macros.

Run the following command from the root of your QMK firmware repository:

```bash
qmk generate-compilation-database -kb boardsource/unicorne -km MartyJRE
```

This will create a `compile_commands.json` file in the root of your QMK firmware repository.

### 2. Open the Project in CLion

1. Open CLion
2. Select "Open" and navigate to your QMK firmware repository
3. Select the root directory of the repository and click "Open"

### 3. Configure CLion to Use the Compilation Database

1. Go to CLion preferences/settings (File > Settings on Windows/Linux or CLion > Preferences on macOS)
2. Navigate to "Build, Execution, Deployment" > "Compilation Database"
3. Select "File" radio button (not "Project directory")
4. Click the folder icon and browse to the `compile_commands.json` file in your QMK firmware repository root
5. Make sure "Compiler: Auto-detect" is selected
6. Click "Apply" and "OK"
7. If prompted to reload the project, click "Yes"
8. Wait for CLion to finish indexing the project

CLion will now index the project using the compilation database, which should allow it to properly analyze keymap.c files and understand QMK-specific includes like `QMK_KEYBOARD_H`.

**Note**: If CLion still shows "No Compilation database detected" after these steps:
1. Close CLion completely
2. Delete the `.idea` directory in your QMK firmware repository
3. Reopen the project in CLion
4. Follow the steps above again to configure the compilation database

### 4. Regenerate the Compilation Database When Needed

If you make significant changes to your keymap or the QMK firmware is updated, you may need to regenerate the compilation database:

```bash
qmk generate-compilation-database -kb boardsource/unicorne -km MartyJRE
```

## Troubleshooting

If CLion still doesn't recognize certain symbols or includes:

1. Make sure the compilation database was generated successfully
2. Try restarting CLion after generating the compilation database
3. Check if there are any errors in the CLion event log
4. Ensure your QMK environment is properly set up and you can compile the firmware

### Layout Macros Not Recognized

If CLion doesn't recognize layout macros like `LAYOUT_split_3x6_3`:

1. These macros are generated during the build process from the keyboard's JSON files
2. The setup script now generates the keyboard.h file before creating the compilation database
3. If you still have issues, try running the following commands manually:
   ```bash
   qmk generate-keyboard-h -kb boardsource/unicorne -o keyboards/boardsource/unicorne/keyboard.h
   qmk generate-compilation-database -kb boardsource/unicorne -km MartyJRE
   ```
4. Restart CLion and reload the compilation database

## Additional Resources

- [QMK CLI Commands Documentation](https://docs.qmk.fm/#/cli_commands?id=qmk-generate-compilation-database)
- [CLion Compilation Database Documentation](https://www.jetbrains.com/help/clion/compilation-database.html)
