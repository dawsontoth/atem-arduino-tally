#include "main.h"

unsigned int smallButtonPressedFor = 0;

void checkButtonStates()
{
  // Big button.
  if (M5.BtnA.wasReleased())
  {
    mqttClient.publish("cut", "1");
    //mqttClient.publish("auto-transition", "1");
  }

  // Little button.
  if (M5.BtnB.pressedFor(10000))
  {
    smallButtonPressedFor = 10;
    setupWifi(true);
  }
  else if (M5.BtnB.pressedFor(3000))
  {
    smallButtonPressedFor = 3;
  }

  if (M5.BtnB.wasReleased())
  {
    if (smallButtonPressedFor == 3)
    {
      myCameraIndex = atemState[0];
      saveCameraIndex();
    }
    else
    {
      saveRotation();
    }
    smallButtonPressedFor = 0;
  }
}
