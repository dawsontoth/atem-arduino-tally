#include "main.h"

bool onProgram = false;
bool onPreview = false;

void updateATEMLabels(bool force)
{
  if (atemState[1] == myCameraIndex || atemState[3] == myCameraIndex)
  {
    if (force == true || onProgram != true)
    {
      onProgram = true;
      onPreview = false;
      M5.Lcd.fillRect(0, 0, fullScreenWidth, fullScreenHeight, RED);
    }
  }
  else if (atemState[0] == myCameraIndex || atemState[2] == myCameraIndex)
  {
    if (force == true || onPreview != true)
    {
      onProgram = false;
      onPreview = true;
      M5.Lcd.fillRect(0, 0, fullScreenWidth, fullScreenHeight, DARK_GREEN);
    }
  }
  else
  {
    if (force == true || onProgram == true || onPreview == true)
    {
      onProgram = false;
      onPreview = false;
      M5.Lcd.fillRect(0, 0, fullScreenWidth, fullScreenHeight, BLACK);
    }
  }
}
