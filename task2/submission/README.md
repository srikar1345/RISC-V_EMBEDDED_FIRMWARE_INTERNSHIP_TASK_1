# Task-2: RISC-V Hardware Bring-Up and GPIO/UART Integration

This task focuses on the transition from host-based firmware development to real hardware execution on the **VSDSquadron Mini** board, featuring the CH32V003 RISC-V SoC.

## 1. Implementation Overview
In this task, I successfully implemented a firmware layer that demonstrates core industry skills in hardware bring-up:
* **Firmware Flashing:** Successfully compiled and flashed the binary to the RISC-V core.
* **UART Communication:** Integrated a serial telemetry layer to provide real-time status updates to the host PC.
* **GPIO API Layer:** Developed a modular "driver" layer (`gpio_init`, `gpio_set`, `gpio_clear`) to abstract hardware registers from the main application logic.

## 2. GPIO Configuration
* **Chosen Physical Pin:** `PD6` (Port D, Pin 6).
* **Selection Rationale:** This pin is mapped to the onboard LED of the VSDSquadron Mini, providing immediate visual feedback of the firmware's execution.
* **Firmware Mapping:** The pin is controlled via the `GPIOD` peripheral and the `RCC_APB2Periph_GPIOD` clock.

## 3. UART Message Description
The UART is configured for a baud rate of **115200**. The firmware provides the following telemetry:
* **Startup Header:** Displays the Board Name ("VSDSquadron Mini") and Firmware Version immediately after reset.
* **Periodic Heartbeat:** A continuously increasing counter that prints "Heartbeat Count: X | Pin PD6 Toggled" every 1000ms.
* **Verification:** The UART log provides more than 10 consecutive lines of data to satisfy validation requirements.



## 4. How to Build and Flash

### Pre-requisites
* **PlatformIO** extension installed in VS Code.
* **CH32V Toolchain** (automatically handled by PlatformIO).

### Execution Steps
1. **Prepare Environment:** Ensure the VSDSquadron Mini is connected via USB.
2. **Build:** Click the **Checkmark (Build)** icon in the bottom status bar of VS Code.
3. **Flash:** Click the **Arrow (Upload)** icon to transfer the binary to the board.
4. **Monitor:** Open the **Serial Monitor (Plug icon)** and ensure the baud rate is set to **115200** to view the output.

---

## 5. Hardware-Software Validation
To verify the physical signal, an **Arduino Uno** was utilized as a voltmeter to measure the output on `PD6`.
1. **Connection:** `PD6` (VSDSquadron) was connected to `A0` (Arduino).
2. **Grounding:** Both boards share a common Ground (`GND`).
3. **Result:** The Arduino Serial Plotter successfully captured a square wave toggling between **0V** and **3.3V**, confirming correct firmware-to-hardware mapping.
