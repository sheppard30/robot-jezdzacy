#include <Arduino.h>
#include "bluetooth.h"

void setup()
{
  Serial.begin(9600);
  setupBluetooth();
}

void loop()
{
  handleBluetooth();
}