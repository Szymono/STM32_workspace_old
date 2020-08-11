/*
 * pins.h
 *
 *  Created on: 16.11.2017
 *      Author: rafal
 */

#ifndef SPFD5408_PINS_H_
#define SPFD5408_PINS_H_

#define COMMAND_PORT GPIOB

#define RD	0b100000		//5
#define WR	0b1000000		//6
#define RS	0b10000000		//7	//XM , X-
#define CS	0b1				//0	//YP , Y+
#define RST	0b1000000000	//9

#define 	XP		PA0	//ADC
#define 	XM 		PB7
#define 	YP 		PB0	//ADC
#define 	YM		PA1


#define RD_ON		GPIOB->BRR   = RD
#define RD_OFF		GPIOB->BSRR  = RD

#define WR_ON		GPIOB->BRR   = WR
#define WR_OFF		GPIOB->BSRR  = WR

#define RS_ON		GPIOB->BRR   = RS
#define RS_OFF		GPIOB->BSRR  = RS

#define CS_ON		GPIOB->BRR   = CS
#define CS_OFF		GPIOB->BSRR  = CS

#define RST_ON		GPIOB->BRR   = RST
#define RST_OFF		GPIOB->BSRR  = RST

#define DATA_OUT	GPIOA->CRL   = (uint32_t)0x33333333UL;
#define DATA_IN		GPIOA->CRL   = (uint32_t)0x88888888UL;

#define DATA_MODE		RS_OFF
#define COMMAND_MODE	RS_ON

#define DATA_PORT GPIOA->BSRR
#define DATA_PIN  GPIOA->IDR
#define DELAY_CYCLE ;
#define WR_PULSE { WR_ON; DELAY_CYCLE; WR_OFF; }
#define RD_PULSE { RD_ON; RD_OFF; }

//{asm("nop"); asm("nop");asm("nop");asm("nop");asm("nop");}

#endif /* SPFD5408_PINS_H_ */
