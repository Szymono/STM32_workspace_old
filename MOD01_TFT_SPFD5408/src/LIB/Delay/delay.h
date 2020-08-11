#ifndef LIB_DELAY_DELAY_H_
#define LIB_DELAY_DELAY_H_

#include "stm32f10x.h"
#include <LIB/Useful/useful.h>


void delay_ms(uint16_t ms);
void delay_us(uint16_t us);
void config_delay();


#endif /* LIB_DELAY_DELAY_H_ */
