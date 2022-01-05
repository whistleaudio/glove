# Glove

## Development environment

The simple traditional option is to install the Arduino 1.0 IDE (`brew install arduino`) or the new [2.0 RC IDE](https://www.arduino.cc/en/software#experimental-software). However, the IDE is no longer required and development can be done entirely with VS Code and the Arduino CLI:

### Install

1. Install the Arduino CLI with [Homebrew](https://brew.sh) `brew install arduino-cli`
2. Install Arduino Core with the CLI for the right board, e.g. `arduino-cli core install arduino:mbed_nano` for the Nano 33 BLE
3. Install the [Visual Studio Code extension for Arduino](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino) (and [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) if necessary).
4. You'll need to configure a few settings in the extension (if you don't have the Arduino IDE installed). "Use Arduino CLI" should be `checked`, "Arduino Command Path" should be `arduino-cli`, and you'll also have to set "Arduino Path", e.g. `/usr/local/bin/` but that may be different on your system (though you can check the location with `which arduino-cli`.) Then restart VS Code.

### Configure

1. Open the project folder
2. Run the command "Arduino: Initialize" (to create local `.vscode/arduino.json` and `.vscode/c_cpp_properties.json` files)
3. Select the board, Arduino Nano 33 BLE, in VS Code (bottom-right)
4. Select the port it is connected to, e.g. `/dev/cu.usbmodem14301`

### Usage

- Verify/compile: Use the "Verify" button in the upper-right of VS Code or use the CLI: `arduino-cli compile --fqbn arduino:mbed_nano:nano33ble`
- Upload to board: Use the "Upload" button or use the CLI (substituting the appropriate port): `arduino-cli upload -p /dev/cu.usbmodem14301 --fqbn arduino:mbed_nano:nano33ble glove`

## Libraries

- `arduino-cli lib install BLE-MIDI` depends on:
    - `arduino-cli lib install "MIDI Library"`
    - `arduino-cli lib install ArduinoBLE`
- `arduino-cli lib install Arduino_APDS9960` proximity/gesture sensor
