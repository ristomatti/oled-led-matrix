#include "buzzer.h"

unsigned long lastBeep = 0;
boolean beep = true;

void buzzerSetup() {}

void buzzerLoop() {
  // if (millis() - lastBeep >= 1000) {
  //   tone(buzzerPin, frequency, 100);
  //   lastBeep = millis();
  // }
}
