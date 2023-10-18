#include "Q_PWM.h"

void pwm0_init(void) {
  //Enable the clock for the PWM0 module
   SYSCTL->RCGCPWM |= BIT0;
  //Enable clock for Port B
   SYSCTL->RCGCGPIO |= BIT1;

  //Configure the GPIO pins for PWM output
   GPIOB->AFSEL |= BIT7 | BIT6;
   GPIOB->PCTL  |= (4U<<6*4) | (4U<<7*4);
   GPIOB->DEN   |= BIT7 | BIT6;

  // Configure PWM clock
   //SYSCTL->RCC |= BIT20;  // Enable PWM clock Divisor
   //SYSCTL->RCC |= 2<<17;  // sys clock/8

   //Configure PWM generators
   PWM0->_0_GENA |= 0X02 << 2 | 0X03 << 6;  //Drive pwmA Low when counter = LOAD, and Drive pwmA High counter matches
                                            //comparator A while counting down
   PWM0->_0_GENB |= 0X03 << 2 | 0X02 << 6;  // Do reverse for pwmB


  //Configure the Period(or frequency) of the PWM signal
   PWM0->_0_LOAD = 100;

  //Configure the duty cycle for the PWM signals
   PWM0->_0_CMPA = 20;
   PWM0->_0_CMPB = 0;

  //Enable the PWM outputs
   PWM0->_0_CTL |= BIT0;   //Enable PWM
   PWM0->ENABLE |= BIT0| BIT1;

  //Configure the dead band
   PWM0->_0_DBCTL |=BIT0;
   PWM0->_0_DBRISE = 2;
   PWM0->_0_DBFALL = 2;
}


void pwm0_duty(uint8_t duty){
    PWM0->_0_CMPA = duty;
}
