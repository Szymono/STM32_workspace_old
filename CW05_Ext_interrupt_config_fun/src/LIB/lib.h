/*
 * lib.h
 *
 *  Created on: 28.08.2018
 *      Author: szymon
 */

#ifndef LIB_H_
#define LIB_H_

#include <stdio.h>
#include "stm32f10x.h"

//- - - - - - - - - - - - - - - - - - - - - -

//- - - - - - - - - - - - - - - - - - - - - -

//- - - - - - - - - - - - - - - - - - - - - -

#define intpt __attribute__((interrupt))

//- - - - - - - - - - - - - - - - - - - - - -

void ConfigPin(GPIO_TypeDef* const port, uint8_t pin , uint8_t mode);
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
//bit-banding\\ - - - - - - - - - - - - - - -

#define BB(rej,pin) *(__IO uint32_t*)( 0x42000000 + (32*(uint32_t)&rej) + (4*(__builtin_ctz(pin))))

//- - - - - - - - - - - - - - - - - - - - -//



//POJEDYŃCZE BITY
#define B0		0b00000000000000000000000000000001 //albo ((uint32_t)0x0001)
#define B1		0b00000000000000000000000000000010
#define B2		0b00000000000000000000000000000100
#define B3		0b00000000000000000000000000001000
#define B4		0b00000000000000000000000000010000
#define B5		0b00000000000000000000000000100000
#define B6		0b00000000000000000000000001000000
#define B7		0b00000000000000000000000010000000
#define B8		0b00000000000000000000000100000000
#define B9		0b00000000000000000000001000000000
#define B10		0b00000000000000000000010000000000
#define B11		0b00000000000000000000100000000000
#define B12		0b00000000000000000001000000000000
#define B13		0b00000000000000000010000000000000
#define B14		0b00000000000000000100000000000000
#define B15		0b00000000000000001000000000000000
#define B16		0b00000000000000010000000000000000
#define B17		0b00000000000000100000000000000000
#define B18		0b00000000000001000000000000000000
#define B19		0b00000000000010000000000000000000
#define B20		0b00000000000100000000000000000000
#define B21		0b00000000001000000000000000000000
#define B22		0b00000000010000000000000000000000
#define B23		0b00000000100000000000000000000000
#define B24		0b00000001000000000000000000000000
#define B25		0b00000010000000000000000000000000
#define B26		0b00000100000000000000000000000000
#define B27		0b00001000000000000000000000000000
#define B28		0b00010000000000000000000000000000
#define B29		0b00100000000000000000000000000000
#define B30		0b01000000000000000000000000000000
#define B31		0b10000000000000000000000000000000


//GPIOA
#define PA0			0b0000000000000001
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

#endif /* LIB_H_ */
