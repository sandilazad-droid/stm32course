// ili9143.h
// Basic ILI9143 LCD driver header for STM32

#ifndef ILI9143_H
#define ILI9143_H

#include <stdint.h>

// Define your hardware interface functions here
void ILI9143_Init(void);
void ILI9143_Reset(void);
void ILI9143_WriteCommand(uint8_t cmd);
void ILI9143_WriteData(uint8_t data);
void ILI9143_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void ILI9143_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9143_FillScreen(uint16_t color);

#endif // ILI9143_H