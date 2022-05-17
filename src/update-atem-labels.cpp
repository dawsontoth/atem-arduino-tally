#include "main.h"

void updateATEMLabels()
{
  drawAtemState(atemState[0], 0, 0, true);
  drawAtemState(atemState[1], halfScreenWidth, 0, false);
  drawAtemState(atemState[2], 0, halfScreenHeight, true);
  drawAtemState(atemState[3], halfScreenWidth, halfScreenHeight, false);
}
