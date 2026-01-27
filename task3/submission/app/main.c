#include "timer.h"
#include "gpio.h"
#include "boardmap.h"
#include <ch32v00x.h>
#include <debug.h>
int main(void) {
    SystemCoreClockUpdate();

    // RULE: All hardware interaction goes through library APIs
    timer_init();
    gpio_init(); // Sets up PD6 internally
    USART_Printf_Init(115200);

    uint32_t last_blink = 0;
    uint32_t last_log = 0;

    while (1) {
        uint32_t now = timer_get_ms();

        // Application logic calls ONLY library functions
        if (now - last_blink >= 5000) {
            gpio_toggle(STATUS_LED_PIN); // Logic: toggle pin 6
            last_blink = now;
        }

        if (now - last_log >= 1000) {
            printf("%lu\r\n", now); // Logic: log the time
            last_log = now;
        }
    }
}