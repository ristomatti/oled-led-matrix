#include "led.h"

// define a LED matrix on data pin 7, clock pin 5, intensity 0
TM1640 led(D7, D5, true, 0);

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
