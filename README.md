# ESP32 Projects

Welcome to the ESP32 Projects repository! This repository contains various projects developed using the ESP32 microcontroller. The ESP32 is a powerful, low-cost microcontroller with integrated Wi-Fi and Bluetooth capabilities, making it ideal for a wide range of applications, including IoT, home automation, and wearable electronics.

## Table of Contents

- [Introduction](#introduction)
- [ESP32 Overview](#esp32-overview)
- [Projects](#projects)
- [Basic Hardware Requirements](#basic-hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Introduction

This repository showcases various projects that demonstrate the capabilities of the ESP32 microcontroller. Each project is designed to highlight different features and functionalities of the ESP32, providing a comprehensive learning experience for developers.

## ESP32 Overview

The ESP32 is a series of low-cost, low-power system-on-chip microcontrollers with integrated Wi-Fi and dual-mode Bluetooth. It is designed and manufactured by Espressif Systems. The ESP32 is highly versatile and can be used in a wide range of applications, including:

- IoT (Internet of Things) devices
- Home automation systems
- Wearable electronics
- Industrial automation
- Smart agriculture

Key features of the ESP32 include:

- Dual-core or single-core Tensilica Xtensa LX6 microprocessor
- Integrated Wi-Fi (802.11 b/g/n)
- Integrated dual-mode Bluetooth (classic and BLE)
- Multiple GPIO pins with various functions (PWM, ADC, DAC, I2C, SPI, UART, etc.)
- Low-power sleep modes
- Rich set of peripherals (timers, watchdogs, RTC, etc.)

## Projects

This repository contains the following projects:

| Project Name       | Description                                                                 |
|--------------------|-----------------------------------------------------------------------------|
| Distance Sensing   | Uses an ultrasonic sensor to measure distance and display it on an OLED screen. Includes LED blinking based on distance threshold. |

## Basic Hardware Requirement

- Espressif ESP32 DevKit
- Jumper Wires
- Breadboard

## Software Requirements

- [PlatformIO](https://platformio.org/)
- [Visual Studio Code](https://code.visualstudio.com/)

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/Lelin07/ESP32.git
    cd ESP32
    ```

2. Open the project in Visual Studio Code with PlatformIO extension installed.

3. Install the required libraries by adding the following to your `platformio.ini` file

4. Build and upload the project to your ESP32 board:
    ```sh
    pio run --target upload
    ```

## Usage

1. Connect the ESP32 to your computer via USB.
2. Open the Serial Monitor in PlatformIO with a baud rate of 115200.
3. Observe the distance measurements and the LED blinking based on the distance threshold.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
