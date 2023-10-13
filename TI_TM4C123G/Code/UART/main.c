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
  //initialize UART0 PA0, PA1
    SYSCTL->RCGCUART |= (1U<<0);        // Enable clock for UART0
    SYSCTL->RCGCGPIO |= (1U<<0);        // Enable clock for GPIOA
    GPIOA->AFSEL |=(1U<<1) | (1U<<0);   // Enable alternate function for PA0, PA1
    GPIOA->PCTL  |= (1U<<4) | (1U<<0);  // Choose Mode function as UART
    GPIOA->DEN   |= (1U<<1) | (1U<<0);  // Enable digital function for PA0, And PA1


    /*
     * BRD = 16000000 / (16 * 115200) =8.680555555555555
     *
     * UARTIBRD = 8 = 0X08;
     *
     * UARTFBRD[DIVFRAC] = integer(0.680555555555555 * 64 + 0.5) = 44 =0x2C
     *
     */

    UART0->CTL &= (~(1U<<0)) & (~(1U<<0)) & (~(1U<<0)); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
    UART0->IBRD =  0x08;      // Write the integer portion of the BRD to the UARTIBRD register.
    UART0->FBRD =  0x2C;      // Write the fractional portion of the BRD to the UARTFBRD register.
    UART0->LCRH |= (0X03<<5); // Data length of 8 bits, One stop bit, No parity
    UART0->CC   =  0x05;      // Use PIOSC
    UART0->CTL |=  (1U<<9)|(1U<<8)|(1U<<0);  // Enable the UART. RX enable, TX enable

    while(1){
     GPIOF->DATA |= (1U<<1);
     delay(100);
     GPIOF->DATA &= ~(1U<<1);
     delay(300);

     while( (UART0->FR & (0x05)) !=0  ){

     }

     UART0->DR = 'A';
     delay(1000);
    }

  return 0;
}



