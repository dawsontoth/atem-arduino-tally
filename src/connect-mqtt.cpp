#include "main.h"

void connectMQTT()
{
  if (!mqttClient.connected())
  {
    drawLabel(BLACK, RED, "Connecting to ATEM...", 2);
    if (mqttClient.connect(hostName.c_str()))
    {
      drawLabel(BLACK, RED, "Requesting state...", 2);
      mqttClient.subscribe("atem-state");
      mqttClient.publish("request-atem-state", "");
    }
    else
    {
      drawLabel(BLACK, RED, "Disconnected...", 2);
      delay(3000);
    }
  }
}
