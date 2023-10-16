#include "TM4C123GH6PM.h"
#include <Q_driver/Q_delay.h>
#include <Q_driver/Q_UART.h>
#include <Q_driver/Q_BSP.h>

int main(void){
 //Initialize SysTick timer
   SysTick_Init(); // this is required for proper delay operation
 //BSP init
   bsp_init();

 //UART init
  uart0_init(115200);
  char message[] = "Hello this is UART code...!\n";
  while(1){
    uart0_puts(message);
    delay(1000);
    led(RED_LED, TOGGLE);
   }


  return 0;
}



