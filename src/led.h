#ifndef LED_H
#define LED_H

/**
 * LED Matrix Number Loop
 *
 * byte image array: https://goo.gl/HpBg16
 * bit reversal: http://www.geekviewpoint.com/java/bitwise/reverse_bits_byte
 */

#include <Arduino.h>
#include <TM1638.h>
#include <TM1640.h>
#include <Wire.h>

// numbers from 0 to 9
const uint64_t IMAGES[] = {0x7e1818181c181800,
                           0x7e060c3060663c00,
                           0x3c66603860663c00,
                           0x30307e3234383000,
                           0x3c6660603e067e00,
                           0x3c66663e06663c00,
                           0x1818183030667e00,
                           0x3c66663c66663c00,
                           0x3c66607c66663c00,
                           0x3c66666e76663c00};

const int IMAGES_LEN = sizeof(IMAGES) / 8;

const int buttonPin = D3;
const int speed = 1000;

byte reverseBits(byte x);
void drawImage(uint64_t image);

void buttonLoop();

/**
 * Setup LED matrix display
 */
void ledSetup();

/**
 * LED matrix display loop
 */
void ledLoop();

#endif
