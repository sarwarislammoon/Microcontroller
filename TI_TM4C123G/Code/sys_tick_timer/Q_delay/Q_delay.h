#ifndef __Q_DELAY_H__
#define __QDELAY_H__

#include <stdint.h>
#include"TM4C123GH6PM.h"

void delay(uint32_t ms);
void SysTick_Init(void);




#endif //__QDELAY_H
