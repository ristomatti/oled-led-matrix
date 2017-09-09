#include "oled.h"

MicroOLED oled(PIN_RESET, DC_JUMPER);  // I2C Example

const int screenWidth = oled.getLCDWidth();
const int screenHeight = oled.getLCDHeight();

void oledSetup() {
  oled.begin();
  oled.clear(ALL);
  // oled.display();
}

void oledLoop() { }
