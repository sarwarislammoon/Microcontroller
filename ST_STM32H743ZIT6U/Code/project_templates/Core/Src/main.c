#include <stdint.h>
#include <stm32h743xx.h>

#define BIT0    (1U<<0)
#define BIT1    (1U<<1)
#define BIT2    (1U<<2)
#define BIT3    (1U<<3)
#define BIT4    (1U<<4)
#define BIT5    (1U<<5)
#define BIT6    (1U<<6)
#define BIT7    (1U<<7)

#define BIT8    (1U<<8)
#define BIT9    (1U<<9)
#define BIT10   (1U<<10)
#define BIT11   (1U<<11)
#define BIT12   (1U<<12)
#define BIT13   (1U<<13)
#define BIT14   (1U<<14)
#define BIT15   (1U<<15)

#define BIT16   (1U<<16)
#define BIT17   (1U<<17)
#define BIT18   (1U<<18)
#define BIT19   (1U<<19)
#define BIT20   (1U<<20)
#define BIT21   (1U<<21)
#define BIT22   (1U<<22)
#define BIT23   (1U<<23)

#define BIT24   (1U<<24)
#define BIT25   (1U<<25)
#define BIT26   (1U<<26)
#define BIT27   (1U<<27)
#define BIT28   (1U<<28)
#define BIT29   (1U<<29)
#define BIT30   (1U<<30)
#define BIT31   (1U<<31)


//Global variables
uint32_t _ms_counter = 0U;

void delay(uint32_t ms){
 _ms_counter = 0;
 while(ms > _ms_counter){
 }

}


void SysTick_Init(void){
	uint32_t DELAY_IN_MICRO_SECONDS = 1000U;
	uint32_t CLOCK_FREQUENCY_IN_MHZ = 64U;

	SysTick->CTRL = 0b00000111;     // Enable SysTick timer, SysTick interrupt and use CPU clock.
    SysTick->LOAD = (DELAY_IN_MICRO_SECONDS * CLOCK_FREQUENCY_IN_MHZ) - 1;

}



void SysTick_Handler(void) {
    _ms_counter++;
}



int main(void){
	RCC->CR |=BIT0;   		//enable high speed internal clock
	RCC->AHB4ENR |=BIT1; 	//Enable GPIOB clock
	//PB0 as output
	GPIOB->MODER &= ~BIT1;
	GPIOB->MODER |=  BIT0;

    SysTick_Init();

	while(1){
		GPIOB->ODR |=  BIT0;  //Turn on GREEN LED
		delay(500);
		GPIOB->ODR &= ~BIT0;  //Turn Off GREEN LED
		delay(500);
	}



}


