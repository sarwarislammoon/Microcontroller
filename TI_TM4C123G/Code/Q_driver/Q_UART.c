#include "Q_UART.h"


void uart0_init(uint32_t baudrate){
  // Enable the UART0 and GPIOA peripheral
  SYSCTL->RCGCUART |= BIT0;
  SYSCTL->RCGCGPIO |= BIT0;

  // Configure the UART0 pins
  GPIOA->DEN |= BIT1 | BIT0;   // Digital enable PA0 and PA1
  GPIOA->AFSEL |= BIT1 | BIT0; // Enable alternate function on PA0 and PA1
  GPIOA->PCTL |= BIT4 | BIT0;  // Configure PA0 and PA1 as UART pins


  // Disable UART0 before configuration
  UART0->CTL &= ~BIT0;

  // Baud rate of 115200, 8-bit data, 1 stop bit, no parity, FIFOs disabled

  /*
   * BRD = 16000000 / (16 * 115200) =8.680555555555555
   *
   * UARTIBRD = 8 = 0X08;
   *
   * UARTFBRD[DIVFRAC] = integer(0.680555555555555 * 64 + 0.5) = 44 =0x2C
   *
   */

  UART0->IBRD = 0x08;
  UART0->FBRD = 0x2C;
  UART0->LCRH |= BIT7 | BIT6 | BIT5 ;


  // Enable UART0, transmit, and receive
  UART0->CTL |= BIT9 | BIT8 | BIT0;
}


void uart0_putc(char c){
  while (UART0->FR & BIT5) {}       // Wait if the UART is busy
  UART0->DR = c;                    // Send the character
}



void uart0_puts(char* s){
  while (*s) {
      uart0_putc(*s);  // Send each character
    s++;
   }
}



