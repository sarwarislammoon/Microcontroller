#include <stdint.h>
#include"TM4C123GH6PM.h"
#include "Q_PWM.h"
#include "Q_delay.h"


uint8_t i =0;

int main(void) {
    pwm0_init();

    SysTick_Init();

    while(1){
        for (i=0;i<100;i++){
            pwm0_duty(i);
            delay(250);
        }

        for (i=100;i>0;i--){
            pwm0_duty(i);
            delay(250);
        }


    }

}


