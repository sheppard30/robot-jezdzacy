#include <Arduino.h>
#include "Car.h"
#include "DebugSerial.h"

Car car;

void setup()
{
  car.begin();
  debug.begin(9600);
  Serial.begin(9600);

  debug.println("Wlaczono");
}

void loop()
{
  car.initialize();
}