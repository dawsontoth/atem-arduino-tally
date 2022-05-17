#include "main.h"

void saveRotation()
{
    rotation = (rotation + 1) % 4;
    preferences.putUInt("rotation", rotation);
    rotationUpdated();
    updateATEMLabels();
}
