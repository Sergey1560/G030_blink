#include "timer.h"

void tim14_init(void){
	RCC->APBENR2 |= RCC_APBENR2_TIM14EN;

    TIM14->PSC = (64000-1);
    TIM14->CNT = 0;
    TIM14->ARR = 500-1;

    TIM14->EGR |= TIM_EGR_UG;
    while(!(TIM14->SR & TIM_SR_UIF)){};
    TIM14->SR = 0;

	TIM14->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM14_IRQn); 

	TIM14->CR1 |= TIM_CR1_CEN;
}


void TIM14_IRQHandler(void){
	static uint32_t flag=0;
	
	TIM14->SR &= ~TIM_SR_UIF;

	if(flag){
		GPIOC->BSRR = GPIO_BSRR_BR15;
		DEBUG("Led OFF");
		flag=0;
	}else{
		GPIOC->BSRR = GPIO_BSRR_BS15;
		DEBUG("Led ON");
		flag=1;
	}
}
