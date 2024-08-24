#include "DistanceSensor.h"
#include "DebugSerial.h"

DistanceSensor::DistanceSensor() : distance(-1)
{
}

void DistanceSensor::begin()
{
    pinMode(ECHO_INPUT, INPUT);
    pinMode(TRIGGER_OUTPUT, OUTPUT);
}

void DistanceSensor::initialize()
{
    this->trigger();
    this->calculateDistance();
}

void DistanceSensor::trigger()
{
    unsigned long currentTime = micros();

    if (!this->triggered || currentTime - this->triggerTime >= TRIGGER_INTERVAL * 1000)
    {
        this->triggered = true;
        this->triggerTime = currentTime;

        digitalWrite(TRIGGER_OUTPUT, HIGH);
    }

    if (this->triggered && currentTime - this->triggerTime >= 10)
    {
        digitalWrite(TRIGGER_OUTPUT, LOW);
        this->triggered = false;
    }
}

void DistanceSensor::calculateDistance()
{
    short status = digitalRead(ECHO_INPUT);

    if (!this->measuring && status == HIGH)
    {
        this->echoStartTime = micros();
        this->measuring = true;
        return;
    }

    if (this->measuring && status == LOW)
    {
        unsigned long diff = micros() - this->echoStartTime;

        this->distance = (diff * 34) / 1000 / 2.0;
        this->measuring = false;
    }
}

double DistanceSensor::getDistance()
{
    return this->distance;
}