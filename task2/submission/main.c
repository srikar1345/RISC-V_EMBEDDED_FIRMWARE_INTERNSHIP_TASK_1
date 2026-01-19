#include <ch32v00x.h>
#include <debug.h>
#include "gpio.h" // Add this line!

int main(void) {
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    Delay_Ms(1000); 

    gpio_init();

    printf("--- VSDSquadron Mini Task-2 ---\r\n");

    int counter = 0;
    while (1) {
        gpio_set(GPIO_Pin_6);
        Delay_Ms(500); // 5000 is 5 seconds, 500 is 0.5s for faster testing
        
        gpio_clear(GPIO_Pin_6);
        Delay_Ms(500);

        printf("Heartbeat Count: %d | LED Toggled on PD6\r\n", counter++);
    }
}