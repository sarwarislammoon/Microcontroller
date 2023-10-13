#include <stdint.h>
#include"TM4C123GH6PM.h"
#include "./Q_delay/Q_delay.h"


int main(void){
  //Enable the GPIOF peripheral

    SYSCTL->RCGCGPIO = 0x20;
    GPIOF->DIR = 0x02;
    GPIOF->DEN = 0x02;

  //Initialize SysTick timer

    SysTick_Init();


    while(1){
     GPIOF->DATA |= (1U<<1);
     delay(100);
     GPIOF->DATA &= ~(1U<<1);
     delay(300);
    }

  return 0;
}



