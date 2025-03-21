# DevPulse: ESP32 WebSocket and OLED Display Project

DevPulse is an ESP32-based project that uses WebSocket communication to display messages on an OLED screen. It also includes features like LED blinking and buzzer activation based on received WebSocket messages.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Code Explanation](#code-explanation)
- [License](#license)

## Introduction

DevPulse demonstrates how to use an ESP32 microcontroller to receive WebSocket messages and display them on an OLED screen. The project also includes visual and auditory feedback using an LED and a buzzer.

## Hardware Requirements

- ESP32 Development Board
- OLED Display (e.g., SSD1306)
- Buzzer
- Breadboard and Jumper Wires

## Software Requirements

- [PlatformIO](https://platformio.org/)
- [Visual Studio Code](https://code.visualstudio.com/)

## Circuit Diagram

![Circuit Diagram](assets/diagram.jpg)

Connect the components as follows:

- **OLED Display:**
  - VCC to 3.3V
  - GND to GND
  - SCL to GPIO 22
  - SDA to GPIO 21

- **Buzzer:**
  - Positive to GPIO 25
  - Negative to GND

- **LED:**
  - Built-in LED (GPIO 2)

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/devpulse.git
    cd devpulse
    ```

2. Open the project in Visual Studio Code with the PlatformIO extension installed.

3. Install the required libraries by adding the following to your `platformio.ini` file:
    ```ini
    lib_deps = 
        adafruit/Adafruit GFX Library@^1.11.11
        adafruit/Adafruit SSD1306@^2.5.12
    ```

4. Build and upload the project to your ESP32 board:
    ```sh
    pio run --target upload
    ```

## Usage

1. Connect the ESP32 to your computer via USB.
2. Run the `pre_flash.sh` script to flash the firmware:
    ```sh
    ./scripts/pre_flash.sh
    ```
3. Open the Serial Monitor in PlatformIO with a baud rate of 115200.
4. Send WebSocket messages to the ESP32's IP address on port 81. The messages will be displayed on the OLED screen, and the LED and buzzer will provide feedback.

## Code Explanation

### `src/main.cpp`

The main code file initializes the OLED display, sets up WebSocket communication, and handles LED and buzzer feedback. The `setup` function configures the display, WiFi connection, and WebSocket server. The `loop` function continuously listens for WebSocket messages and updates the OLED display.

#### Key Functions:

- `initDisplay()`: Initializes the OLED display and shows a default message.
- `webSocketEvent()`: Handles incoming WebSocket messages, updates the OLED display, and triggers the LED and buzzer.
- `setup()`: Configures WiFi, initializes the WebSocket server, and sets up the hardware components.
- `loop()`: Handles WebSocket communication.

### Libraries Used

- **Adafruit GFX Library**: For graphics functions on the OLED display.
- **Adafruit SSD1306**: For interfacing with the SSD1306 OLED display.
- **WebSocketsServer**: For handling WebSocket communication.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.