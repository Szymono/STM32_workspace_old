/*
 * lib.c
 *
 *  Created on: 07.09.2018
 *      Author: szymon
 */

#include <LIB/GPIO/gpio.h>
#include <stdio.h>
#include "stm32f10x.h"

/*
void SetPin(GPIO_TypeDef* port , uint16_t pin)
{
	port->ODR = pin;
}
*/

void ConfigPin(GPIO_TypeDef* const port, uint16_t pin , uint8_t mode)
{
	pin = __builtin_ctz(pin);

	if(pin<8)	//Rejestr Low - dla pin�w 0-7
	{
		port->CRL &= ~(0b1111<<(pin*4));		//zerowanie bit�w (domy�lnie s� ustawione 0100?)
		port->CRL |= (mode<<(pin*4));			//zapis konfiguracji trybu pracy pinu do pami�ci
	}
	else		//Rejestr High - dla pin�w 8-15
	{
		port->CRH &= ~(0b1111<<((pin-8)*4));	//zerowanie bit�w
		port->CRH |= (mode<<((pin-8)*4));		//zapis konfiguracji
	}
}


