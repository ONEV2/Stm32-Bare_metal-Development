/*
 * Blink program by manipulating registers
 * Created by - Prakhar Agrawal
 * Date - 6-07-22
 * Time - 16:15
 */

// Where is the led connected ?
// i.e -> port number and pin number
// Port: A
// Pin:	 5
// UL stands for unsigned long int

#include <stdint.h>

#define PERIPH_BASE				(0x40000000UL)
#define AHB1PERIPH_OFFSET		(0x00020000UL) // 0x4000 0000 + 0x0002 0000 = 0x4002 0000
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOA_OFFSET			(0x00000000UL)
#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET)

// RCC is responsible to enable clock access to peripherals connected to bus
#define RCC_OFFSET 				(0x00023800U)
#define RCC_BASE				(PERIPH_BASE + RCC_OFFSET)

#define GPIOAEN					(1U<<0)	//shift 1 at position 0

#define PIN5				(1U<<5)	//set bit 5 to 1
#define LED_PIN				PIN5



typedef struct
{
	volatile uint32_t MODER;	//address = 0x00
	volatile uint32_t dummy[4];	//dummy object
	volatile uint32_t ODR;	//address = 0x14

}GPIO_TypeDef;


typedef struct
{
	volatile uint32_t dummy[12];
	volatile uint32_t AHB1ENR;	//address offset = 0x30;
}RCC_TypeDef;

#define RCC				((RCC_TypeDef*)RCC_BASE)
#define GPIOA			((GPIO_TypeDef*)GPIOA_BASE)

/*
 * (1U<<10) shift 1 to position 10, ie set bit 10 to 1
 * &=~(1U<<11)	only set bit 11 to 0
 */



int main(){

	//Enable clock access to gpio peripheral
	RCC->AHB1ENR |= GPIOAEN;

	// set PA5 as output
	GPIOA->MODER |= (1U<<10);	//set bit 10 to 1
	GPIOA->MODER &= ~(1U<<11);	//set bit 11 to 0

	while(1){

		// Toggle LED
		GPIOA->ODR ^= LED_PIN;
		// using for loop for delay
		for(int i=0;i<100000;i++);
	}
	return 0;
}
