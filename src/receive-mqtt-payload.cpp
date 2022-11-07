#include "main.h"

void receiveMQTTPayload(char *topic, byte *payload, unsigned int length)
{
  if (length > 0)
  {
    if (payload[0] == 'm')
    {
      String myString = "";
      for (int i = 1; i < length; i++)
      {
        myString = myString + (char)payload[i];
      }
      drawLabel(BLACK, RED, myString, 2);
    }
    else
    {
      String current = "";
      bool changed = false;
      int j = 0;
      for (int i = 0; i < length; i++)
      {
        if (payload[i] == ',')
        {
          int newState = current.toInt();
          if (atemState[j] != newState)
          {
            atemState[j] = newState;
            changed = true;
          }
          current = "";
          j = j + 1;
        }
        else
        {
          current = current + (char)payload[i];
        }
      }
      int newState = current.toInt();
      if (atemState[j] != newState)
      {
        atemState[j] = newState;
        changed = true;
      }
      if (changed)
      {
        updateATEMLabels(false);
      }
    }
  }
}
