#include <stdint.h>
#include"TM4C123GH6PM.h"

void delay(uint32_t count);
uint32_t i;


int main(void){
    SYSCTL->RCGCGPIO = 0x20;
    GPIOF->DIR = 0x0E;
    GPIOF->DEN = 0x0E;

    uint32_t on_time  = 100000;
    uint32_t off_time = 1000000;

    while(1){
     GPIOF->DATA |= (1U<<1);
     delay(on_time);
     GPIOF->DATA &= ~(1U<<1);
     delay(off_time);

     GPIOF->DATA |= (1U<<2);
     delay(on_time);
     GPIOF->DATA &= ~(1U<<2);
     delay(off_time);

     GPIOF->DATA |= (1U<<3);
     delay(on_time);
     GPIOF->DATA &= ~(1U<<3);
     delay(off_time);
    }
  return 0;
}


void delay(uint32_t count){
 for(i=0;i<count;i++){
 }
}
