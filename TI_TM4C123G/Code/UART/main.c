#include "TM4C123GH6PM.h"
#include "Q_BSP.h"
#include "Q_delay.h"
#include "Q_UART.h"


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
    led(GREEN_LED, TOGGLE);
   }


  return 0;
}



