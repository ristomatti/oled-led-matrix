#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

const int buzzerPin = D6;
const int frequency = 75;  // Specified in Hz

/**
 * Setup buzzer
 */
void buzzerSetup();

/**
 * Buzzer loop
 */
void buzzerLoop();

#endif
