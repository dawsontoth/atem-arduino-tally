#include "main.h"

void drawAtemState(int cameraNumber, int x, int y, bool preview)
{
  M5.Lcd.fillRect(
      x,
      y,
      halfScreenWidth,
      halfScreenHeight,
      cameraNumber == myCameraIndex ? preview ? DARK_GREEN : RED : BLACK);
  M5.Lcd.setTextColor(cameraNumber == myCameraIndex ? BLACK : GRAY);
  M5.Lcd.drawCentreString(String(cameraNumber), x + quarterScreenWidth, y + quarterScreenHeight - 18, 6);
}
