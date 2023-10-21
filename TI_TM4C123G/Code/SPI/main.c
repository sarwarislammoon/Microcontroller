#include <stdint.h>
#include"TM4C123GH6PM.h"
#include "Q_delay.h"
#include "Q_UART.h"
#include "Q_BSP.h"


uint32_t i;

// Clock-> PB4, SS-> PB5; MOSI-> PB6; MOSI-> PB7

void spi2_init(uint32_t frequency, uint8_t mode);
void spi2_write(uint8_t data);
uint8_t spi2_read(void);

void spi2_init(uint32_t frequency, uint8_t mode){

    //init SPI
    //Enable the SSI module using the RCGCSSI register
    SYSCTL->RCGCSSI |= BIT2;
    //Enable PORTB clock
    SYSCTL->RCGCGPIO |=BIT1;
    //Set the GPIO AFSEL bits for the appropriate pins
    GPIOB->AFSEL |= BIT4 | BIT5 | BIT6 | BIT7;
    //Set the GPIO AFSEL bits for the appropriate pins
    GPIOB->PCTL |= 2<<4*4 | 2<<5*4 | 2<<6*4 | 2<<7*4;
    //Program the GPIODEN register to enable the pin's digital function
    GPIOB->DEN |= BIT4 | BIT5 | BIT6 | BIT7;

    //Disable SSI2
    SSI2->CR1 &= ~BIT1;

    //Configure  as master
    SSI2->CR1 =0x00;

    //Select PIOSE as clock source
    SSI2->CC = 0x05;

    /*
    Write the SSICR0 register with the following configuration:
     1.Serial clock rate (SCR)
     2.Desired clock phase/polarity, if using Freescale SPI mode (SPH and SPO)
     3.The protocol mode: Freescale SPI, TI SSF, MICROWIRE (FRF)
     4.The data size (DSS)
    */

    SSI2->CR0 |=0<<7 |0<<6 |00<<4 | 0x07; // 8bit, SPI, CPOL=0, CPHA=0.

    //Enable SSI2
      SSI2->CR1 |= BIT1;
}

void spi2_write(uint8_t data){
  while ((SSI2->SR &=BIT4) == 1); // wait until BSY flag is cleared
  SSI2->DR = data;
  while((SSI2->SR &=BIT0) ==0);   // Wait until data transfer is completed
}


uint8_t spi2_read(void){
   while (SSI2->SR &=BIT4 == 1); // wait until BSY flag is cleared
   //SSI2->DR = 0x00;
   return SSI2->DR;
}


uint8_t tx_data;
uint8_t rx_data;

int main(void){
  uart0_init(115200);
  SysTick_Init();
  spi2_init(20000000, 0);


  while(1){
   //uart0_puts("Hello World!\n");

   for(tx_data = 'A'; tx_data <= 'Z'; tx_data ++){
       spi2_write(tx_data);
       rx_data=spi2_read();
       uart0_puts("Rx_data: ");
       uart0_putc(rx_data);
       uart0_putc('\n');
       delay(500);
   }


  }
  return 0;
}


