#ifndef OLED_H
#define OLED_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <SFE_MicroOLED.h>

#define PIN_RESET 255  //
#define DC_JUMPER 0  // I2C Addres: 0 - 0x3C, 1 - 0x3D

/**
 * Setup OLED display
 */
void oledSetup();

/**
 * OLED display loop
 */
void oledLoop();

#endif
