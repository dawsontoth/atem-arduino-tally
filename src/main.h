#include <M5StickCPlus.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Preferences.h>
#include <SPIFFS.h>
#include <WiFiSettings.h>
#include <ArduinoOTA.h>

extern unsigned int fullScreenWidth;
extern unsigned int fullScreenHeight;
extern unsigned int halfScreenWidth;
extern unsigned int halfScreenHeight;
extern unsigned int quarterScreenWidth;
extern unsigned int quarterScreenHeight;
extern unsigned int myCameraIndex;
extern unsigned int rotation;
extern unsigned int atemState[4];
extern String mqttServerAddress;
extern String hostName;

extern PubSubClient mqttClient;
extern Preferences preferences;

void setupWifi(bool forcePortal);
void rotationUpdated();
void connectMQTT();
void receiveMQTTPayload(char *topic, byte *payload, unsigned int length);
void saveCameraIndex();
void saveRotation();
void updateATEMLabels(bool force);
void drawAtemState(int cameraNumber, int x, int y, bool preview);
void drawLabel(unsigned long int screenColor, unsigned long int labelColor, String label, int size);
void startOTA();

void checkButtonStates();

// http://www.barth-dev.de/online/rgb565-color-picker/
#define GRAY 0x7BCF  //   8  8  8
#define DARK_GREEN 0x0200 //   0 64  0
#define RED 0xF800   // 255  0  0
