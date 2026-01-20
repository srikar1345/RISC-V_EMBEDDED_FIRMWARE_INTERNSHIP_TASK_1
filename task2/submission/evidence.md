


# Task-2: Hardware Validation Evidence

This document provides definitive proof of successful firmware bring-up, UART communication, and GPIO physical control on the VSDSquadron Mini RISC-V board.

---
```markdown
## 1. UART Evidence
The UART communication was validated using the PlatformIO Serial Monitor to confirm real-time telemetry from the RISC-V core.

### **UART Validation Details**
* **Baud Rate:** 115200
* **Data Format:** 8N1
* **Output:** Startup header followed by the mandatory 10+ consecutive heartbeat lines.

### **Serial Log Capture**
```text
--- VSDSquadron Mini Task-2 ---
Hardware: RISC-V CH32V003
Firmware Version: 1.1.0
-------------------------------
Heartbeat Count: 0 | Pin PD6 Toggled
Heartbeat Count: 1 | Pin PD6 Toggled
Heartbeat Count: 2 | Pin PD6 Toggled
Heartbeat Count: 3 | Pin PD6 Toggled
Heartbeat Count: 4 | Pin PD6 Toggled
Heartbeat Count: 5 | Pin PD6 Toggled
Heartbeat Count: 6 | Pin PD6 Toggled
Heartbeat Count: 7 | Pin PD6 Toggled
Heartbeat Count: 8 | Pin PD6 Toggled
Heartbeat Count: 9 | Pin PD6 Toggled
Heartbeat Count: 10 | Pin PD6 Toggled

```

### **UART Screenshots & Videos**

#### UART Terminal Output

#### UART Real-time Video

[Click here to watch the UART Validation Video](https://www.google.com/search?q=./1000052664.mp4)
### Serial Terminal Output
![UART Terminal Log](./1000052663.jpg)
---

## 2. GPIO Evidence

Physical pin control was demonstrated by toggling a specific GPIO pin and measuring the output with an external Arduino Uno setup.

### **Pin Mapping Details**

* **Physical Pin Label:** `PD6`
* **Firmware GPIO Number:** `GPIO_Pin_6` (mapped to `GPIOD`)
* **Configuration:** Output Mode, Push-Pull

### **Verification Explanation**

Correct behavior was verified using an **Arduino Uno** acting as a digital logic probe:

1. The VSDSquadron Mini **PD6** pin was connected to the Arduino **A0** analog pin.
2. A **Common Ground** wire was connected between both boards.
3. The Arduino measured the voltage transitions, confirming a high state of **~3.3V** and a low state of **~0V**.

### **GPIO Screenshots & Videos**

#### Hardware Setup and Connection

#### GPIO Toggling and Plotter Video

[Click here to watch the GPIO and LED Toggling Video](https://www.google.com/search?q=./1000052669.mp4)
### 
![GPIO Evidence](./1000052671.jpg)
---

Short Explanation
The objective of this task was to establish a Hardware Abstraction Layer (HAL) for the VSDSquadron Mini RISC-V board.

Modular API Design: Instead of writing directly to registers in the main application, I developed a standalone GPIO API (gpio.h and gpio.c) to handle initialization and pin state transitions.

System Integration: The firmware integrates the CH32V003 peripheral library to configure the system clock and UART at 115200 baud, enabling communication between the RISC-V core and the host PC.

Firmware Logic: A heartbeat loop was implemented to toggle the physical state of the PD6 pin every 500ms while simultaneously transmitting telemetry data via UART.

How I Verified Correct Behavior
Verification was conducted using a Hardware-in-the-Loop (HIL) approach to ensure that the software logic translated accurately into physical electrical signals.

UART Telemetry: I monitored the serial output using the PlatformIO Serial Monitor to confirm that the RISC-V core was successfully booting and executing the loop without crashing.

Visual Confirmation: The onboard LED connected to PD6 was observed for consistent blinking, providing immediate visual proof of the GPIO driver's functionality.

Signal Validation (Arduino Voltmeter): To gain precise electrical confirmation, I utilized an Arduino Uno as a digital logic probe:

Common Reference: Connected the GND of both the VSDSquadron and the Arduino.

Signal Sampling: Connected the VSDSquadron PD6 to Arduino Analog Pin A0.

Waveform Analysis: Used the Arduino Serial Plotter to visualize the output, confirming a stable square wave toggling between 0V and 3.3V.

```

**Would you like me to help you set `main` as the default branch in your GitHub settings so that this folder structure is the first thing anyone sees?**
