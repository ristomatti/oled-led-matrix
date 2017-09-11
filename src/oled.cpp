#include "oled.h"
#include <string.h>

U8G2_SSD1306_64X48_ER_F_SW_I2C u8g2 = U8G2_SSD1306_64X48_ER_F_SW_I2C(U8G2_R0, D1, D2);

int cursorLine;

void oledSetup() {
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_mf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setFontPosTop();
  u8g2.enableUTF8Print();
}

void oledLoop() {}

void printMessage(char* str) {
  u8g2.clearBuffer();
  cursorLine = 0;

  const char s[2] = " ";
  char buffer[500];
  char* token;

  token = strtok(str, s);

  while (token != NULL) {
    int length = strlen(buffer);
    if (length >= screenWidth || length + strlen(token) > screenWidth - 1) {
      drawLine(buffer);
    }
    if (strlen(buffer) == 0) {
      strcpy(buffer, token);
    } else {
      strcat(buffer, token);
    }
    strcat(buffer, " ");
    token = strtok(NULL, s);
  }
  drawLine(buffer);
  u8g2.sendBuffer();
}

void drawLine(char* buffer) {
  int lineHeight = u8g2.getFontAscent() - u8g2.getFontDescent();
  u8g2.drawUTF8(0, lineHeight * cursorLine, buffer);
  buffer[0] = '\0';
  cursorLine++;
}
