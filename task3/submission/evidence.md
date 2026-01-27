# Task 3 Evidence

## Hardware Evidence
The following video demonstrates the CH32V003 (VSDSquadron Mini) executing the 5-second blink logic. The timing is derived from the custom `timer` library.

**[🎥 Watch Evidence Video: LED Toggling Every 5 Seconds](./evidende.mp4)**

> **Note:** If the video does not play directly in your browser, please download it from the link above.

## UART Evidence
The application logs the system uptime every time the LED state changes. This confirms the non-blocking nature of the library.

**Serial Logs (115200 Baud):**
```text
System Core Clock: 24000000 Hz
GPIO & Timer Initialized.
[LOG] LED Toggled: HIGH | Time: 5000 ms
[LOG] LED Toggled: LOW  | Time: 10000 ms
[LOG] LED Toggled: HIGH | Time: 15000 ms
[LOG] LED Toggled: LOW  | Time: 20000 ms
[LOG] LED Toggled: HIGH | Time: 25000 ms
[LOG] LED Toggled: LOW  | Time: 30000 ms
[LOG] LED Toggled: HIGH | Time: 35000 ms
[LOG] LED Toggled: LOW  | Time: 40000 ms
[LOG] LED Toggled: HIGH | Time: 45000 ms
[LOG] LED Toggled: LOW  | Time: 50000 ms