#include "main.h"

void rotationUpdated()
{
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setRotation(rotation);
  halfScreenWidth = (int)(M5.Lcd.width() / 2);
  halfScreenHeight = (int)(M5.Lcd.height() / 2);
  quarterScreenWidth = (int)(M5.Lcd.width() / 4);
  quarterScreenHeight = (int)(M5.Lcd.height() / 4);
}
