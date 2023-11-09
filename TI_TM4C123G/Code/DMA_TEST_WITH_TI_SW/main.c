/**
 * main.c
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/udma.h"

//Allocate the channel control table
uint8_t DMA_Control_Table[1024];

//source and destination buffer for DMA transfer
uint8_t Source_Buffer[256];
uint8_t Dest_Buffer[256];

uint8_t Source_Buffer[256]="DMA Test";



int main(void)
{
    //Enable the uDMA peripheral
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);

	//Enable the uDMA controller
    uDMAEnable();
    //Set the base for channel control table
    uDMAControlBaseSet(&DMA_Control_Table[0]);
    //The attributes are cleared here if they are set elsewhere
    uDMAChannelAttributeDisable(UDMA_CHANNEL_SW, UDMA_ATTR_ALL);
    //8-bit data size, with byte wise buffer copy & bus arbitration size of 8
    uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_SIZE_8|UDMA_SRC_INC_8|UDMA_DST_INC_8|UDMA_ARB_8);
    //DMA Transfer uses Auto mode
    uDMAChannelTransferSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT, UDMA_MODE_AUTO, Source_Buffer, Dest_Buffer, sizeof(Dest_Buffer));
   //The channel is enabled and for software transfer a request must also be made
    uDMAChannelEnable(UDMA_CHANNEL_SW);
    uDMAChannelRequest(UDMA_CHANNEL_SW);

    while(1){

    }

    return 0;
}
