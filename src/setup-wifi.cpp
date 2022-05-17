#include "main.h"

void setupWifi(bool forcePortal)
{
  WiFiSettings.hostname = hostName;
  WiFiSettings.secure = false;

  WiFiSettings.onPortal = []()
  {
    drawLabel(BLACK, RED, "Ready to Configure!", 2);
    startOTA();
  };
  WiFiSettings.onPortalWaitLoop = []()
  {
    ArduinoOTA.handle();
  };

  if (forcePortal)
  {
    WiFiSettings.portal();
  }
  else
  {
    mqttServerAddress = WiFiSettings.string("mqtt_host", "10.1.10.200", "MQTT Host");
    WiFiSettings.connect();
    WiFi.config(IPAddress(0, 0, 0, 0), IPAddress(0, 0, 0, 0), IPAddress(0, 0, 0, 0));
  }

  startOTA();
}
