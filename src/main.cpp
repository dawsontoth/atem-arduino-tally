#include "main.h"

void setup()
{
  setCpuFrequencyMhz(1);
  btStop();

  M5.begin();
  SPIFFS.begin(true);
  preferences.begin("atem", false);
  myCameraIndex = preferences.getUInt("myCameraIndex", myCameraIndex);
  rotation = preferences.getUInt("rotation", rotation);
  hostName = preferences.getString("hostName", "Tally-" + String(random(0xffff), HEX));
  rotationUpdated();

  drawLabel(BLACK, RED, "Booting...", 2);

  setupWifi(false);
  mqttClient.setServer(mqttServerAddress.c_str(), 1883);
  mqttClient.setCallback(receiveMQTTPayload);
}

void loop()
{
  M5.update();
  ArduinoOTA.handle();
  checkButtonStates();

  if (!mqttClient.connected())
  {
    connectMQTT();
  }
  mqttClient.loop();

  delay(33);
}
