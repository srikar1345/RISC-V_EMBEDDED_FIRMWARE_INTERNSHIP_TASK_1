# Task 1: Firmware Library Fundamentals

## 1. Objective
The goal of this task is to understand how firmware libraries are structured, how application code utilizes APIs, and to simulate hardware behavior using a C-based development environment.

---

## 2. Core Concepts

### What is a Firmware Library?
A **Firmware Library** is a collection of code (functions and source files) that runs on or simulates embedded hardware. It serves as the intermediary between the high-level application logic and the low-level hardware registers. 
* It consists of **Header Files (`.h`)** for declarations and **Source Files (`.c`)** for implementation.
* In this task, `gpio.c` and `gpio.h` form the library, providing the logic to manage GPIO pins.



### Why are APIs important in Embedded Systems?
An **API (Application Programming Interface)** is the "contract" that defines how the application interacts with the hardware. APIs are vital for:
* **Hardware Abstraction:** They hide complex register-level details. A developer calls `gpio_write()` instead of manually masking bits at specific memory addresses.
* **Portability:** The same application code (`main.c`) can run on different hardware platforms as long as the API remains the same.
* **Modularity:** It allows developers to work on the application layer without needing to worry about the underlying hardware driver logic.
* **Maintenance:** Changes in hardware only require updates to the library/driver, not the entire application codebase.



### What was understood from the Lab Code?
The lab code demonstrates the fundamental **separation of concerns** in embedded development:
1. **Interface vs. Implementation:** `gpio.h` defines *what* the hardware can do, while `gpio.c` defines *how* it performs those actions.
2. **Simulation Flow:** Firmware logic can be validated on a PC using simulation (such as `printf` outputs) to verify logic before deploying to actual hardware.
3. **Application Layering:** `main.c` represents the application layer, which remains hardware-agnostic by only interacting with the API.
4. **Compilation Flow:** Linking multiple source files (`main.c` and `gpio.c`) using `gcc` is the foundational process for building modular firmware.

---

## 3. GPIO Function Overview

| Function | Meaning |
| :--- | :--- |
| `gpio_init()` | Configures the pin direction (Input or Output). |
| `gpio_write()` | Sets the pin state (HIGH/ON or LOW/OFF). |
| `gpio_read()` | Reads the current state of a pin. |

---

## 4. Lab Code Implementation

### gpio.h
```c
#ifndef GPIO_H
#define GPIO_H

/* Simple GPIO library (simulation) */

/* GPIO direction definitions */
#define GPIO_OUTPUT 1
#define GPIO_INPUT  0

/* API functions */
void gpio_init(int pin, int direction);
void gpio_write(int pin, int value);
int  gpio_read(int pin);

#endif
```
### gpio.c
```c
#include <stdio.h>
#include "gpio.h"

/*
 * This file simulates a GPIO firmware library.
 * In real hardware, these functions would access registers.
 */

void gpio_init(int pin, int direction)
{
    if (direction == GPIO_OUTPUT) {
        printf("GPIO %d initialized as OUTPUT\n", pin);
    } else {
        printf("GPIO %d initialized as INPUT\n", pin);
    }
}

void gpio_write(int pin, int value)
{
    printf("GPIO %d write value: %d\n", pin, value);
}

int gpio_read(int pin)
{
    printf("GPIO %d read value\n", pin);
    return 1; // simulated value
}

```
### main.c
```c
#include <stdio.h>
#include "gpio.h"

#define LED_PIN 5
#define BTN_PIN 3

int main(void)
{
    printf("Starting firmware application\n");

    gpio_init(LED_PIN, GPIO_OUTPUT);
    gpio_init(BTN_PIN, GPIO_INPUT);

    gpio_write(LED_PIN, 1);

    int button_state = gpio_read(BTN_PIN);
    printf("Button state: %d\n", button_state);

    gpio_write(LED_PIN, 0);

    printf("Firmware application finished\n");

    return 0;
}



```
## 5. Final output

### Command
```c

gcc main.c gpio.c -o task1_demo
./task1_demo

```
### Output 

```c
PS C:\Users\karun\Desktop\EMBEDDED\vsdsquadron-mini-core\task1> ./task1_demo
Starting firmware application
GPIO 5 initialized as OUTPUT
GPIO 3 initialized as INPUT
GPIO 5 write value: 1
GPIO 3 read value
Button state: 1
GPIO 5 write value: 0
Firmware application finished


```

