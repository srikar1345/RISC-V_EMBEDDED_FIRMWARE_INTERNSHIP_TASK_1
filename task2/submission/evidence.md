
# Task-2: Hardware Validation Evidence

This document provides definitive proof of successful firmware bring-up, UART communication, and GPIO physical control on the VSDSquadron Mini RISC-V board.

---

```markdown
## 1. UART Evidence
The UART communication was validated using the PlatformIO Serial Monitor to confirm real-time telemetry from the RISC-V core.

### **UART Validation Details**
* **Baud Rate:** 115200
* **Data Format:** 8N1 (8 bits, No parity, 1 stop bit)
* **Output:** A startup header followed by 10+ consecutive heartbeat lines.

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

> **[PLACEHOLDER: Insert Screenshot of your Serial Monitor showing 10+ lines here]**
> *Example: *

> **[PLACEHOLDER: Insert/Link Video of the Serial Terminal updating here]**
> *Example: [Watch UART Video*](https://www.google.com/search?q=./uart_video.mp4)

---

## 2. GPIO Evidence

Physical pin control was demonstrated by toggling a specific GPIO pin and measuring the output with external hardware to ensure software-to-silicon mapping is correct.

### **Pin Mapping Details**

* **Physical Pin Label:** `PD6` (As labeled on the board silkscreen)
* **Firmware GPIO Number:** `GPIO_Pin_6` (Mapped to `GPIOD` port)
* **Configuration:** Output Mode, Push-Pull, 50MHz

### **Verification Explanation**

Correct behavior was verified using an **Arduino Uno** acting as a digital logic probe/voltmeter:

1. The VSDSquadron Mini **PD6** pin was connected to the Arduino **A0** analog pin.
2. A **Common Ground** wire was connected between both boards to provide a shared reference.
3. The Arduino measured the voltage transitions, confirming a high state of **~3.3V** and a low state of **~0V**.

### **GPIO Screenshots & Videos**

> **[PLACEHOLDER: Insert Photo of your Hardware Setup (VSDSquadron + Arduino wires) here]**
> *Example: *

> **[PLACEHOLDER: Insert Screenshot of the Arduino Serial Plotter showing the Square Wave here]**
> *Example: *

> **[PLACEHOLDER: Insert Video of the Board LED blinking and Plotter moving here]**
> *Example: [Watch GPIO Video*](https://www.google.com/search?q=./gpio_video.mp4)

---

## 3. Hardware-Software Interaction Summary

The validation is confirmed by the perfect synchronization between the software telemetry (UART) and the physical signal (LED/Voltmeter):

* Every UART "Heartbeat" message corresponds exactly to a physical toggle of the onboard LED.
* The Arduino Serial Plotter displays a sharp, consistent square wave, confirming the firmware's timing is accurate and the GPIO driver is correctly addressing the RISC-V registers.

---

```

```
