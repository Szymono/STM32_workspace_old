/*
 * ex.h
 *
 *  Created on: 06.09.2018
 *      Author: szymon
 */

#ifndef LIB_INTERRUPT_EX_H_
#define LIB_INTERRUPT_EX_H_

void ConfigExtInt(GPIO_TypeDef* port, uint32_t pin , uint16_t ExtIcr , uint8_t mode);

#define EXTI_mode_RT 	0	//Rising trigger
#define EXTI_mode_FT 	1	//Falling trigger
#define EXTI_mode_RFT 	2	//Rising & Falling trigger
#define EXTI_mode_FRT 	2	//Rising & Falling trigger

#endif /* LIB_INTERRUPT_EX_H_ */
