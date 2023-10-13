#include <stdint.h>
#include"TM4C123GH6PM.h"

void delay(uint32_t count);
uint32_t i;


int main(void){
  //Enable the GPIOF peripheral
    SYSCTL->RCGCGPIO = 0x20;
    GPIOF->DIR = 0x02;
    GPIOF->DEN = 0x02;

    while(1){
     GPIOF->DATA |= (1U<<1);
     delay(100000);
     GPIOF->DATA &= ~(1U<<1);
     delay(100000);
    }
  return 0;
}


void delay(uint32_t count){
 for(i=0;i<count;i++){
 }
}
