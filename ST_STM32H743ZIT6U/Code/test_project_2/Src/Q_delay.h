#ifndef __Q_DELAY_H__
#define __QDELAY_H__

#include <stdint.h>
#include "stm32h743xx.h"


#define DELAY_IN_MICRO_SECONDS          1000U
#define CLOCK_FREQUENCY_IN_MHZ          64U



void delay(uint32_t ms);
void SysTick_Init(void);




#endif //__QDELAY_H
