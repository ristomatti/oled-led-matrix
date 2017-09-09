#include <SPI.h>
#include <Wire.h>
#include <SFE_MicroOLED.h>

#define PIN_RESET 255  //
#define DC_JUMPER 0    // I2C Addres: 0 - 0x3C, 1 - 0x3D

const int screenWidth = oled.getLCDWidth();
const int screenHeight = oled.getLCDHeight();

MicroOLED oled(PIN_RESET, DC_JUMPER);  // I2C Example

void oledSetup() {
  oled.begin();
  oled.clear(ALL);
  oled.display();
}

void oledLoop() { }
