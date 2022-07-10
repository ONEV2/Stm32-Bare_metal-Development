#include <stm32f4xx.h>

#define GPIOAEN		(1U<<0)	// shift 1 to 0th position
#define PIN5		(1U<<5)	// set bit 5 to 1
#define LED_PIN		PIN5

int main(){
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	while(1){
		// using BSRR register instead of ODR
		// BSRR stands for bit set/reset registers

		GPIOA->BSRR |= LED_PIN;	//setting BS5 to 1
		for(int i=0;i<1000000;i++);

		GPIOA->BSRR |= (1U<<21);	//setting BR5 to 1
		for(int i=0;i<1000000;i++);

	}

	return 0;
}
