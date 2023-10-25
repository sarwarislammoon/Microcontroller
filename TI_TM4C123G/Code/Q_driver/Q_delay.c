#include <Q_delay.h>


//Global variables
uint32_t _ms_counter = 0U;

void delay(uint32_t ms){
 _ms_counter = 0;
 while(ms > _ms_counter){
 }

}


void SysTick_Init(void){
    SysTick->CTRL = 0b00000011;     // Enable SysTick timer, SysTick interrupt and use Precision internal oscillator (PIOSC) divided by 4
    SysTick->LOAD = 1000U*4 - 1;    // 1000uSeconds delay
}


void SysTick_Handler(void) {
    _ms_counter++;
}
