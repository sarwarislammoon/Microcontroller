#include "Q_BSP.h"

void bsp_init(void){
  //Enable GPIOB, GPIOC and GPIOE clock
	RCC->CR |=BIT0;   				//enable high speed internal clock
	RCC->AHB4ENR |=BIT1 | BIT2 | BIT4; 	//Enable GPIOB, GPIOC and GPIOE clock

  /*
   *As the Red yellow and Green are connected to PB14, PE1 and PB0 respectvely
   *so set these GPIo direction as Output
  */

	//PB14 as output
	GPIOB->MODER &= ~BIT29;
	GPIOB->MODER |=  BIT28;

	//PE1 as output
	GPIOE->MODER &= ~BIT3;
	GPIOE->MODER |=  BIT2;

	//PB0 as output
	GPIOB->MODER &= ~BIT1;
	GPIOB->MODER |=  BIT0;

    //PC13 as input for user Button
	GPIOC->MODER &= ~BIT27;
	GPIOC->MODER &= ~BIT26;


}


void led(uint8_t colour, uint8_t state){
    switch (colour){
      case RED_LED:
        if (state == ON){
         GPIOB->ODR |= (BIT14); //Turn on Red Led ,PB14
        }
        else if (state == OFF){
         GPIOB->ODR &= ~(BIT14); //Turn off Red Led
        }

        else if(state == TOGGLE)
         GPIOB->ODR ^= (BIT14); //Toggle Red Led

        break;

      case YELLOW_LED:
        if (state == ON){
         GPIOE->ODR |= (BIT1); //Turn on Yellow Led ,  PE1
        }
        else if (state == OFF){
         GPIOE->ODR &= ~(BIT1); //Turn off Yellow Led
        }
        else if(state == TOGGLE)
         GPIOE->ODR ^= (BIT1); //Toggle Yellow Led

        break;

      case GREEN_LED:
        if (state == ON){
         GPIOB->ODR |= (BIT0); //Turn on Green Led , PB0
        }
        else if (state == OFF){
         GPIOB->ODR &= ~(BIT0); //Turn off Green Led
        }
        else if(state == TOGGLE)
         GPIOB->ODR ^= (BIT0); //Toggle Green Led

        break;


    }

}


uint8_t get_button_status(uint8_t button){

	if ((GPIOC->IDR &= BIT13) != 0){
		while((GPIOC->IDR &= BIT13)){

		} // wait until the button is released

		return HIGH;
	}
	else {
		return LOW;
	}
}

