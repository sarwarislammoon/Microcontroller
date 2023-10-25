#include <stdint.h>
#include "Q_delay.h"
#include "Q_common.h"
#include "Q_BSP.h"

uint32_t last_led=GREEN_LED;

int main(void){
	bsp_init();

    SysTick_Init();

	while(1){
		if(get_button_status(0) == HIGH ){
			if(last_led ==GREEN_LED){
				led(RED_LED, TOGGLE);
				last_led=RED_LED;
			}

			else if(last_led ==RED_LED){
				led(YELLOW_LED, TOGGLE);
				last_led=YELLOW_LED;
			}

			else if(last_led==YELLOW_LED){
				led(GREEN_LED, TOGGLE);
				last_led=GREEN_LED;
			}

		}
	}

}













