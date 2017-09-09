#include <Arduino.h>

const int buzzerPin = D6;
const int frequency = 75;  // Specified in Hz

unsigned long lastBeep = 0;
boolean beep = true;

void buzzerSetup() { Serial.begin(115200); }

void buzzerLoop() {
  // if (millis() - lastBeep >= 1000) {
  //   tone(buzzerPin, frequency, 100);
  //   lastBeep = millis();
  // }
}
