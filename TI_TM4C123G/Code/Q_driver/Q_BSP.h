#ifndef __Q_BSP_H__
#define ___Q_BSP_H__

#include <stdint.h>
#include "TM4C123GH6PM.h"
#include "Q_common.h"


#define RED_LED     1
#define BLUE_LED    2
#define GREEN_LED   3


void bsp_init(void);
void led(uint8_t colour, uint8_t state);
uint8_t get_button_status(uint8_t button);

#endif /* ___Q_BSP_H__*/
