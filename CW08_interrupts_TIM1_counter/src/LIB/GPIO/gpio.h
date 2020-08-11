/*
 * lib.h
 *
 *  Created on: 07.09.2018
 *      Author: szymon
 */

#ifndef LIB_GPIO_GPIO_H_
#define LIB_GPIO_GPIO_H_

#include "stm32f10x.h"

//- - - - - - - - - - - - - - - - - - - - - -

void ConfigPin(GPIO_TypeDef* const port, uint16_t pin , uint8_t mode);
//#define LowPinConfig(port,pin,mode) (port)->CRL = (mode<<(pin*4))
//#define HiPinConfig(port,pin,mode) (port)->CRH = (mode<<(pin*4))

//- - - - - - - - - - - - - - - - - - - - -//
//[MODE]\\- - - - - - - - - - - - - - - - - -

#define input_PUD		0b1000	// pull-up/pull-down
#define input_fl		0b0100	// folating

#define output_PP_LS		0b0010	// pull/push 	, low-speed
#define output_OD_LS		0b0110	// open-drain 	, low-speed
#define alternate_PP_LS		0b1010	// pull-push 	, low-speed
#define alternate_OD_LS		0b1010	// open-drain 	, low-speed

#define output_PP_MS		0b0001	// pull/push	, medium-speed
#define output_OD_MS		0b0101	// open-drain 	, medium-speed
#define alternate_PP_MS		0b1001	// pull-push 	, medium-speed
#define alternate_OD_MS		0b1001	// open-drain 	, medium-speed

#define output_PP_HS		0b0011	// pull/push 	, high-speed
#define output_OD_HS		0b0111	// open-drain 	, high-speed
#define alternate_PP_HS		0b1011	// pull-push 	, high-speed
#define alternate_OD_HS		0b1011	// open-drain 	, high-speed

#define analog			0b0000

//- - - - - - - - - - - - - - - - - - - - -//
//- - - - - - - - - - - - - - - - - - - - - -

#define SetPin(port,pin) (port)->BSRR = (pin)
#define ResetPin(port,pin) (port)->BRR = (pin)
/*void SetPin(GPIO_TypeDef* , uint16_t pin);*/
//- - - - - - - - - - - - - - - - - - - - - -


//GPIOA
#define PA0			0b0000000000000001	//albo ((uint32_t)0x0001)
#define PA1			0b0000000000000010
#define PA2			0b0000000000000100
#define PA3			0b0000000000001000
#define PA4			0b0000000000010000
#define PA5			0b0000000000100000
#define PA6			0b0000000001000000
#define PA7			0b0000000010000000
#define PA8			0b0000000100000000
#define PA9			0b0000001000000000
#define PA10		0b0000010000000000
#define PA11		0b0000100000000000
#define PA12		0b0001000000000000
#define PA13		0b0010000000000000
#define PA14		0b0100000000000000
#define PA15		0b1000000000000000


//GPIOB
#define PB0			0b0000000000000001
#define PB1			0b0000000000000010
#define PB2			0b0000000000000100
#define PB3			0b0000000000001000
#define PB4			0b0000000000010000
#define PB5			0b0000000000100000
#define PB6			0b0000000001000000
#define PB7			0b0000000010000000
#define PB8			0b0000000100000000
#define PB9			0b0000001000000000
#define PB10		0b0000010000000000
#define PB11		0b0000100000000000
#define PB12		0b0001000000000000
#define PB13		0b0010000000000000
#define PB14		0b0100000000000000
#define PB15		0b1000000000000000


//GPIOC
#define PC0			0b0000000000000001
#define PC1			0b0000000000000010
#define PC2			0b0000000000000100
#define PC3			0b0000000000001000
#define PC4			0b0000000000010000
#define PC5			0b0000000000100000
#define PC6			0b0000000001000000
#define PC7			0b0000000010000000
#define PC8			0b0000000100000000
#define PC9			0b0000001000000000
#define PC10		0b0000010000000000
#define PC11		0b0000100000000000
#define PC12		0b0001000000000000
#define PC13		0b0010000000000000
#define PC14		0b0100000000000000
#define PC15		0b1000000000000000

#endif /* LIB_GPIO_GPIO_H_ */
