#include "Q_BSP.h"

void bsp_init(void){
  //Enable GPIOF clock
    SYSCTL->RCGCGPIO |= BIT5;

  /*
   *As the Red Blue and Green are connected to PF1, PF2 and PF3 respectvely
   *so set these GPIo direction as Output
  */

    GPIOF->DIR |= (BIT1 | BIT2 | BIT3);   // Set the direction of the GPIO pins as output

   // Enable digital functions for the GPIO pins
    GPIOF->DEN |= (BIT1 | BIT2 | BIT3);


}


void led(uint8_t colour, uint8_t state){
    switch (colour){
      case RED_LED:
        if (state == ON){
         GPIOF->DATA |= (BIT1); //Turn on Red Led
        }
        else if (state == OFF){
         GPIOF->DATA &= ~(BIT1); //Turn off Red Led
        }

        else if(state == TOGGLE)
         GPIOF->DATA ^= (BIT1); //Toggle Red Led

        break;

      case BLUE_LED:
        if (state == ON){
         GPIOF->DATA |= (BIT2); //Turn on Blue Led
        }
        else if (state == OFF){
         GPIOF->DATA &= ~(BIT2); //Turn off Blue Led
        }
        else if(state == TOGGLE)
         GPIOF->DATA ^= (BIT2); //Toggle Blue Led

        break;

      case GREEN_LED:
        if (state == ON){
         GPIOF->DATA |= (BIT3); //Turn on Green Led
        }
        else if (state == OFF){
         GPIOF->DATA &= ~(BIT3); //Turn off Green Led
        }
        else if(state == TOGGLE)
         GPIOF->DATA ^= (BIT3); //Toggle Green Led

        break;


    }

}


uint8_t get_button_status(uint8_t button){

}

