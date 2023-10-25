#include <stdint.h>
#include"TM4C123GH6PM.h"
#include "Q_delay.h"
#include "Q_BSP.h"

int main(void){
   SysTick_Init();
   bsp_init();

    while(1){
     led(BLUE_LED, TOGGLE);
     delay(500);

    }

   return 0;
}




