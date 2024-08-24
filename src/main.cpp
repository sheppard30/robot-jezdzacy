#include <Arduino.h>
#include "Car.h"
#include "DebugSerial.h"
#include "DistanceSensor.h"
#include "bluetooth.h"

Car car;

void setup()
{
  car.begin();

  Serial.begin(9600);
  Serial.begin(9600);

  Serial.println("Wlaczono");
}

void loop()
{
  car.initialize();
}