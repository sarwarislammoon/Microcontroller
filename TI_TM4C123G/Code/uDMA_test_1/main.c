#include <stdint.h>
#include"TM4C123GH6PM.h"
#include "Q_delay.h"
#include "Q_BSP.h"

#define BUFFER_SIZE 16

uint8_t UDMA_CONTROL_TABLE[1024] = {0};


uint8_t src_buff[BUFFER_SIZE] = "Hello world!";
uint8_t dest_buff[BUFFER_SIZE] = {0};

uint32_t UDMA_CTRL =0;

int main(void){

   SysTick_Init();
   bsp_init();


   SYSCTL->RCGCDMA |=BIT0;  // Enable the uDMA clock using the RCGCDMA register

   UDMA->CFG |=BIT0;        // Enable DMA controller
   UDMA->ENASET &=~BIT0;    // Disable channel 30

   UDMA_CTRL |= 0x04<<14| (BUFFER_SIZE-1) <<4 |  02 <<0;

   //UDMA_CTRL |= 07<<4 |01 <<0; // 8-bit source and destination increment and data size, basic transfer

   *(uint32_t *)(&UDMA_CONTROL_TABLE[0x1E0]) = (uint32_t)src_buff;
   *(uint32_t *)(&UDMA_CONTROL_TABLE[0x1E4]) = (uint32_t)dest_buff;
   *(uint32_t *)(&UDMA_CONTROL_TABLE[0x1E8]) = UDMA_CTRL;



   UDMA->CTLBASE = (uint32_t)(&UDMA_CONTROL_TABLE);  // pass the control table address
   UDMA->PRIOSET |=BIT30;               // Channel 30 priority high
   UDMA->ALTCLR  |=BIT30;               // Use primary control structure
   UDMA->REQMASKCLR |=BIT30;            //

   //start transfer
   UDMA->ENASET |=BIT30;                //Enable the channel by setting bit 30 of the DMA Channel Enable Set (DMAENASET) register
   UDMA->SWREQ |=BIT30;                 //Issue a transfer request by setting bit 30 of the DMA Channel Software Request (DMASWREQ) register.
   delay(1);
   UDMA->SWREQ |=BIT30;                 //Issue a transfer request by setting bit 30 of the DMA Channel Software Request (DMASWREQ) register.


   return 0;
}




