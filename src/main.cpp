#include <Arduino.h>
#include "Car.h"

Bluetooth bluetooth;
DistanceSensor distanceSensor;
Car car(bluetooth, distanceSensor);

void setup()
{
  bluetooth.begin();
  car.begin();
  distanceSensor.begin();
  Serial.begin(9600);
}

void loop()
{
  car.initialize();
}