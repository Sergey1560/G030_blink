#include "main.h"


int main(void){
	
	RCC_init();

	RCC->IOPENR |= RCC_IOPENR_GPIOCEN;
	GPIOC->MODER &= ~GPIO_MODER_MODE15;
	GPIOC->MODER |= GPIO_MODER_MODE15_0;

	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD15;
	GPIOC->PUPDR |= GPIO_PUPDR_PUPD15_1;
	

	tim14_init();   

	while(1){
		}
}

