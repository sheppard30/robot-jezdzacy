#include <Arduino.h>
#include "Setup.h"
#include "Car.h"

#include <SoftwareSerial.h>

Bluetooth bluetooth;
Car car(bluetooth);

void setup()
{
  bluetooth.begin();
  setupSerialMonitor();
  setupEnginesController();
}

void loop()
{
  car.run();
}