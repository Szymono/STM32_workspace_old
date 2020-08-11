/*
 * SPFD5408.h
 *
 *  Created on: 16.11.2017
 *      Author: rafal
 */

#ifndef SPFD5408_SPFD5408_H_
#define SPFD5408_SPFD5408_H_

#define TFTWIDTH   240
#define TFTHEIGHT  320


enum COLORS 
{
	black,
	blue,
	red ,
	green,
	cyan ,
	magenta,
	yellow,
	white
};

extern const uint16_t colors[8];


void TFT_write8_bits (uint8_t data);
void TFT_reset(void);
void TFT_init (void);
void TFT_setAddrWindow(int x1, int y1, int x2, int y2);
void TFT_setRotation(uint8_t x);
void TFT_setPixel (uint16_t x, uint16_t y, uint16_t color);
void TFT_drwLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
void TFT_fillScreen(uint16_t color);
void TFT_fillRect (uint16_t x, uint16_t y, uint16_t wid, uint16_t hei, uint16_t color);
void TFT_fullRect (uint16_t x, uint16_t y, uint16_t wid, uint16_t hei, uint16_t color);
void TFT_sendChar (uint16_t x, uint16_t y, uint16_t color, char data, uint8_t size, uint16_t background);
void TFT_putString (uint16_t x, uint16_t y,  uint16_t color, uint8_t size, char * string, uint16_t background);
void TFT_clrString (uint16_t x, uint16_t y,  uint16_t color, uint8_t size, uint8_t len);
void TFT_sendBITMAP (uint16_t x, uint16_t y, uint16_t wid, uint16_t hei, const uint8_t * color);
void TFT_drawcircle(int x0, int y0, int radius, uint16_t color);
void TFT_fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void TFT_drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void TFT_drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void _delay_ms(uint32_t _ms);
void _delay_us(uint32_t _us);

#endif /* SPFD5408_SPFD5408_H_ */
