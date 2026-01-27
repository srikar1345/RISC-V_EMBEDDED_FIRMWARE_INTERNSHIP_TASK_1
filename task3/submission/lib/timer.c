#include "timer.h"
#include <ch32v00x.h> // Register access is isolated HERE only

static volatile uint32_t ms_ticks = 0;

void timer_init(void) {
    // Rule: Handle all hardware setup inside the library
    SystemCoreClockUpdate();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    
    SysTick->SR = 0;
    SysTick->CMP = (SystemCoreClock / 1000) - 1;
    SysTick->CNT = 0;
    SysTick->CTLR = 0xF; 
    NVIC_EnableIRQ(SysTick_IRQn);
}

void SysTick_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void SysTick_Handler(void) {
    ms_ticks++;
    SysTick->SR = 0;
}

uint32_t timer_get_ms(void) { return ms_ticks; }