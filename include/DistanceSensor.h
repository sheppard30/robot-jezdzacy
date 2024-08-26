#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include <Arduino.h>
#include "Logger.h"

#define TRIGGER_INTERVAL 500
#define ECHO_INPUT 18     // PC4
#define TRIGGER_OUTPUT 19 // PC5

class DistanceSensor
{
public:
    DistanceSensor();

    void begin();
    double getDistance();
    void initialize();

private:
    unsigned long triggerTime;
    bool triggered;
    unsigned long echoStartTime;
    bool measuring;
    float distance;

    void trigger();
    void calculateDistance();
};

#endif