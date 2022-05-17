#include "main.h"

void drawLabel(unsigned long int screenColor, unsigned long int labelColor, String label, int size)
{
  M5.Lcd.fillScreen(screenColor);
  M5.Lcd.setTextColor(labelColor);
  int offset = (int)(size * 9 / 2);
  M5.Lcd.drawCentreString(label, halfScreenWidth, halfScreenHeight - offset, size);
  Serial.println(label);
}
