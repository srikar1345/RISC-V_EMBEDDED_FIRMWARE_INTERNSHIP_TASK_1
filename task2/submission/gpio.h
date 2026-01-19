#ifndef VSD_GPIO_H
#define VSD_GPIO_H

#include <ch32v00x.h>

// Function Prototypes
void gpio_init(void);
void gpio_set(uint16_t pin);
void gpio_clear(uint16_t pin);

#endif