#ifndef __Q_PWM_H__
#define __Q_PWM_H__

#include <stdint.h>
#include "TM4C123GH6PM.h"
#include "Q_common.h"

void pwm0_init(void);
void pwm0_duty(uint8_t duty);



#endif  //__Q_PWM_H__


