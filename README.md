# 3SLi-ionMonitoringSTM32
​Project: STM32-Based 3S Li-ion Battery Monitoring System
​1. Objective
​The main goal of this project was to build a smart "health-check" system for a 3S Lithium-ion battery pack (11.1V – 12.6V). While standard batteries often fail due to overheating or cell imbalance, I wanted to create a solution using the STM32 (Blue Pill) that provides real-time data. The system is designed to continuously track individual cell voltages and temperatures, displaying them on a screen and flagging any "Unsafe Zones" (like overcharging or deep discharging) to ensure the battery lasts longer and stays safe.
​2. Requirements
​To build this, I divided the requirements into hardware for sensing and software for processing:
​Hardware Components:
​Microcontroller: STM32F103C8T6 (The brain of the system).
​Sensing: DHT22 for temperature and custom-built Voltage Divider circuits to safely step down the 12V signals for the STM32's 3.3V ADC pins.
​Display: 0.96" OLED (SSD1306) for a live data dashboard via I2C.
​Power Management: A Buck Converter to provide a steady 3.3V supply to the microcontroller from the main battery pack.
​Tools: ST-Link V2 for flashing the code and a 3S Li-ion Pack as the test subject.
​Software Environment:
​STM32CubeMX: Used for pin mapping, clock configuration, and initializing ADC/I2C peripherals.
​STM32CubeIDE: Used for writing the firmware and logic using HAL (Hardware Abstraction Layer) drivers.
​3. Conclusion
​This project successfully demonstrates how a high-performance microcontroller like the STM32 can be used for precise battery management. By integrating the ADC for voltage tracking and I2C for display, I created a functional prototype that gives much more insight than a standard "dumb" BMS.
​On a personal level, this project was a huge learning curve for me. I moved beyond basic coding and learned how to handle real-world analog signals, calibrate sensors against a multimeter, and manage power efficiency in embedded designs. It’s a practical solution that can be scaled for drones, portable power banks, or even DIY electric vehicles.
