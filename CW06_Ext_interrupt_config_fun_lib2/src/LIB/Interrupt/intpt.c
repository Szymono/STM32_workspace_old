/*
 * intpt.c
 *
 *  Created on: 07.09.2018
 *      Author: szymon
 */

#include <LIB/Interrupt/intpt.h>
#include <LIB/Useful/useful.h>

#include <stdio.h>
#include "stm32f10x.h"

#define BB(rej,pin) *(__IO uint32_t*)( 0x42000000 + (32*(uint32_t)&rej) + (4*(__builtin_ctz(pin))))


void ConfigExtInt(GPIO_TypeDef* port, uint32_t pin , uint16_t ExtIcr , uint8_t mode)
{//ConfigExtInt(GPIOA,0,AFIO_EXTICR1_EXTI0_PA,mode1)

	BB(RCC->APB2ENR , RCC_APB2ENR_AFIOEN) = 1;	//w³. zegara AFIO

	if (pin < B4)
	 AFIO->EXTICR[0] = ExtIcr;	//select the source input for EXTIx (konkretnego pinu) external interrupt
	else if (pin < B8)
	 AFIO->EXTICR[1] = ExtIcr;
	else if (pin < B12)
	 AFIO->EXTICR[2] = ExtIcr;
	else if (pin < B16)	AFIO->EXTICR[3] = ExtIcr;

	BB(EXTI ->IMR , pin) = 1;//Configure the mask bits

	//trigger mode
	if (mode != 1)
	 BB(EXTI->RTSR , pin) = 1;

	if (mode != 0)
	 BB(EXTI->FTSR , pin) = 1;

	//enable external interrupt in NVIC
	if (pin == B0) 							NVIC_EnableIRQ(EXTI0_IRQn);
	else if (pin == B1) 					NVIC_EnableIRQ(EXTI1_IRQn);
	else if (pin == B2)						NVIC_EnableIRQ(EXTI2_IRQn);
	else if (pin == B3)						NVIC_EnableIRQ(EXTI3_IRQn);
	else if (pin == B4)						NVIC_EnableIRQ(EXTI4_IRQn);
	else if (pin < B10)						NVIC_EnableIRQ(EXTI9_5_IRQn);
	else if (pin < B16)						NVIC_EnableIRQ(EXTI15_10_IRQn);



}
