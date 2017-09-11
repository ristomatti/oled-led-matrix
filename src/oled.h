#ifndef OLED_H
#define OLED_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <U8g2lib.h>

const int screenWidth = 11;

extern U8G2_SSD1306_64X48_ER_F_SW_I2C u8g2;

/**
 * Setup OLED display
 */
void oledSetup();

/**
 * OLED display loop
 */
void oledLoop();

void printMessage(char* str);
void drawLine(char* str);

#endif
