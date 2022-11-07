#include "main.h"

// These will be read from memory later, and can be switched via button presses.
// The numbers assigned here will be used as the defaults.
unsigned int myCameraIndex = 1;
unsigned int rotation = 3;

String mqttServerAddress;
String hostName;

WiFiClient espClient;
PubSubClient mqttClient(espClient);
Preferences preferences;

unsigned int fullScreenWidth;
unsigned int fullScreenHeight;
unsigned int halfScreenWidth;
unsigned int halfScreenHeight;
unsigned int quarterScreenWidth;
unsigned int quarterScreenHeight;

unsigned int atemState[4];

bool warnedAboutConfiguring = false;