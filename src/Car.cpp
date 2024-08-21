#include "Car.h"

Car::Car(Bluetooth &bt) : bluetooth(bt)
{
}

void Car::run()
{
    this->bluetooth.onDataAvailable([](String data)
                                    { Serial.println(data); });
}