#include "main.h"

void saveCameraIndex()
{
    preferences.putUInt("myCameraIndex", myCameraIndex);
    updateATEMLabels(true);
}
