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

// define a LED matrix on data pin 7, clock pin 5, intensity 0
TM1640 led(D7, D5, true, 0);

const int speed = 1000;

byte reverseBits(byte x) {
  int intSize = 8;
  byte y = 0;
  for (int position = intSize - 1; position > 0; position--) {
    y += ((x & 1) << position);
    x >>= 1;
  }
  return y;
}

void drawImage(uint64_t image) {
  led.clearDisplay();
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xff;
    led.setRow(1, 7 - i, row);
  }
}

int imgIdx = 0;
unsigned long lastImageDraw = 0;

void buttonLoop() {
  // if (digitalRead(buttonPin) == LOW)
  // {
  //   imgIdx = 0;
  // }
}

void ledSetup() { led.clearDisplay(); }

void ledLoop() {
  buttonLoop();

  if (millis() - lastImageDraw >= speed) {
    uint64_t image;
    memcpy_P(&image, &IMAGES[imgIdx], 8);

    drawImage(image);
    if (++imgIdx >= IMAGES_LEN) {
      imgIdx = 0;
    }
    lastImageDraw = millis();
  }
}
