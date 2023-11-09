#include <stdint.h>
#include"TM4C123GH6PM.h"
//#include "Q_delay.h"
//#include "Q_BSP.h"
#include "Q_common.h"

#define BUFFER_SIZE 256

uint8_t UDMA_CONTROL_TABLE[1024] = {0};


uint8_t src_buff[BUFFER_SIZE] = "Hello world!";
uint8_t dest_buff[BUFFER_SIZE] = {0};

uint32_t UDMA_CTRL_WORD =0;

int main(void){

   //SysTick_Init();
   //bsp_init();


  //Module Initialization
   SYSCTL->RCGCDMA |=BIT0;  // Enable the uDMA clock using the RCGCDMA register
   UDMA->CFG |=BIT0;        // Enable the uDMA controller by setting the MASTEREN bit of the DMA Configuration (DMACFG)register
   UDMA->CTLBASE = (uint32_t)(&UDMA_CONTROL_TABLE);    // pass the control table address
   //UDMA->ENASET &=~BIT0;    // Disable channel 30

  //Configure the Channel Attributes
   UDMA->PRIOSET |=BIT30;                              // Channel 30 priority high, Program bit 30 of the DMA Channel (DMAPRIOSET) for High priority .
   UDMA->USEBURSTCLR |=BIT30;                          // Set bit 30 of the DMA Channel Useburst Clear (DMAUSEBURSTCLR) register to allow the UDMA controller to respond to single and burst requests.
   UDMA->ALTCLR  |=BIT30;                              // Set bit 30 of the DMA Channel Primary Alternate Clear (DMAALTCLR) register to select the primary channel control structure for this transfer.
   UDMA->REQMASKCLR |=BIT30;                           // Set bit 30 of the DMA Channel Request Mask Clear (DMAREQMASKCLR) register to allow the UDMA controller to recognize requests for this channel.

  //Configure the Channel Control Structure




   *(uint32_t *)(&UDMA_CONTROL_TABLE[0x1E0]) = (uint32_t)src_buff+(BUFFER_SIZE-1);    // Program the source end pointer at offset 0x1E0 to the address of the source buffer + buffer_size.
   *(uint32_t *)(&UDMA_CONTROL_TABLE[0x1E4]) = (uint32_t)dest_buff+(BUFFER_SIZE-1);   // Program the destination end pointer at offset 0x1E4 to the address of the destination buffer + buffer_size.

   //data size (source and dest) 8 bit, address increment byte for both source and dest and set auto transfer

    //UDMA_CTRL_WORD |= 2<<30 | 2<<28 | 2<<26 | 2<<24 | 3<<14 | (BUFFER_SIZE-1) <<4 |  02 <<0;
    //UDMA_CTRL_WORD |=  3<<14 | (BUFFER_SIZE-1) <<4 |  02 <<0;
    UDMA_CTRL_WORD |= 2<<30  | 2<<26 |   3<<14 | (BUFFER_SIZE-1) <<4 |  02 <<0;

   *(uint32_t *)(&UDMA_CONTROL_TABLE[0x1E8]) = UDMA_CTRL_WORD;



   //Start the Transfer
   UDMA->ENASET |=BIT30;                //Enable the channel by setting bit 30 of the DMA Channel Enable Set (DMAENASET) register
   UDMA->SWREQ |=BIT30;                 //Issue a transfer request by setting bit 30 of the DMA Channel Software Request (DMASWREQ) register.




   while(1){

   }


   return 0;
}




