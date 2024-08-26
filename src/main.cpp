#include <Arduino.h>
#include "Car.h"
#include "Logger.h"
#include "DistanceSensor.h"
#include "bluetooth.h"

Car car;

void setup()
{
  car.begin();

  Logger::init(false);
  Logger::debug("Wlaczono");
}

void loop()
{
  car.initialize();
}