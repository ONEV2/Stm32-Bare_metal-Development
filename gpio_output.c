#include <stm32f4xx.h>

#define GPIOAEN		(1U<<0)	// shift 1 to 0th position
#define PIN5		(1U<<5)	// set bit 5 to 1
#define LED_PIN		PIN5

int main(){
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	while(1){
		GPIOA->ODR ^= LED_PIN;
		for(int i=0;i<1000000;i++){};
	}
	return 0;
}
