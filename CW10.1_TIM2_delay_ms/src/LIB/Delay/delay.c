/* < Szymon Ostrowski - 19.09.2018 >
 * < CW10.1_TIM2_delay_ms - delay.c >
 *
 * >Frequency timer = [ frq. crystal / ( (ARR + 1) * (PSC + 1) ) ]
 * >Delay = [ ( (ARR + 1) * (PSC + 1) ) /  frq. crystal ]
 */

#include "delay.h"
#include <stdio.h>
#include "stm32f10x.h"


void delay_ms(uint16_t ms)
{
	TIM2->ARR = ((ms * 2) - 1);
	TIM2->CR1 |= TIM_CR1_CEN;
	while(TIM2->CR1 & TIM_CR1_CEN);
}


void config_delay()
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;	//Enable TIM2
	TIM2->PSC = 35995;					//
	TIM2->ARR = 10000;	//nie istotne ze wzgledu na wymuszenie , ale wartoœc ARR musi byc wieksza od 0
	TIM2->CR1 |= TIM_CR1_OPM;
	TIM2->EGR = TIM_EGR_UG;		//wymuszenie UEV
}
