
#include <stm32f4xx.h>

// RCC clock for gpio ports A and C
#define GPIOAEN		(1U<<0)	// shift 1 to 0th position
#define GPIOCEN		(1U<<2)	// set bit 2 to 1


#define PIN5		(1U<<5)	// set bit 5 to 1
#define LED_PIN		PIN5

#define PIN13		(1U<<13) // set bit 13 to 1
#define BUTTON		PIN13

int main(){
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	// for led as output
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	// for push button as input
	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);


	while(1){
		if(!(GPIOC->IDR & (BUTTON))){
			GPIOA->BSRR |= LED_PIN;	//setting BS5 to 1
		}
		else{
			GPIOA->BSRR |= (1U<<21);	//setting BR5 to 1
		}
	}
	return 0;
}
