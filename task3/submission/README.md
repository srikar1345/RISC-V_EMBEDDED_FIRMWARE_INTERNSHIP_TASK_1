# Task 3: Modular LED Control System

## Implemented Libraries
- **GPIO Library (`gpio.h/c`):** Handles pin initialization and abstraction of the VSDSquadron Mini physical pins.
- **Timer Library (`timer.h/c`):** Configures the RISC-V SysTick for millisecond-level timekeeping.

## API List
| Function | Description |
| :--- | :--- |
| `timer_init()` | Configures SysTick for 1ms interrupts and starts the global counter. |
| `timer_get_ms()` | Returns the current system uptime in milliseconds (uint32_t). |
| `gpio_init()` | Initializes PD6 (built-in LED) as a push-pull output. |
| `led_toggle()` | Reads the current state of the LED pin and flips it. |

## Demo Application
The application initializes the system clock and peripherals, then enters a non-blocking loop. Every 5000ms (5 seconds), it toggles the onboard LED and prints the current timestamp to the UART console.

## Build and Flash
1. Connect VSDSquadron Mini to your PC via USB.
2. Open terminal in the `task3/submission` folder.
3. Run `make` to compile.
4. Run `make flash` to upload the firmware using OpenOCD/WCH-Link.

## UART Configuration
- **Baud Rate:** 115200
- **Data Bits:** 8
- **Stop Bits:** 1
- **Parity:** None