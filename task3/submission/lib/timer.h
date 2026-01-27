#ifndef TIMER_H
#define TIMER_H

#include <stdint.h> // Standard types only, no hardware headers here!

void timer_init(void);
uint32_t timer_get_ms(void);
void timer_delay_ms(uint32_t ms);

#endif