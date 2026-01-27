#include "gpio.h"

void gpio_init(void) {
    // Enable the clock for Port D
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void gpio_set(uint16_t pin) {
    GPIO_WriteBit(GPIOD, pin, Bit_SET);
}

void gpio_clear(uint16_t pin) {
    GPIO_WriteBit(GPIOD, pin, Bit_RESET);
}


void gpio_toggle(uint16_t pin) {
    // Read current state and toggle
    if (GPIOD->OUTDR & pin) {
        GPIO_WriteBit(GPIOD, pin, Bit_RESET);
    } else {
        GPIO_WriteBit(GPIOD, pin, Bit_SET);
    }
}