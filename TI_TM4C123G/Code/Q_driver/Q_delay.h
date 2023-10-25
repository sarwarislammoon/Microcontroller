#ifndef __Q_DELAY_H__
#define __QDELAY_H__

#include <stdint.h>
#include"TM4C123GH6PM.h"


#define DELAY_IN_MICRO_SECONDS          1000U
#define CLOCK_FREQUENCY_IN_MHZ          16U


void delay(uint32_t ms);
void SysTick_Init(void);




#endif //__QDELAY_H
