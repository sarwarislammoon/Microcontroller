#include "Q_delay.h"

//Global variables
uint32_t _ms_counter = 0U;

void delay(uint32_t ms){
 _ms_counter = 0;
 while(ms > _ms_counter){
 }

}


void SysTick_Init(void){
    SysTick->CTRL = 0b00000111;     // Enable SysTick timer, SysTick interrupt and use CPU clock.
    SysTick->LOAD = (DELAY_IN_MICRO_SECONDS * CLOCK_FREQUENCY_IN_MHZ) - 1;

}



void SysTick_Handler(void) {
    _ms_counter++;
}
