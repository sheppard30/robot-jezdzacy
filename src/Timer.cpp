#include <Arduino.h>
#include "Timer.h"

Timer::Timer(unsigned int delay)
{
    this->active = false;
    this->delay = delay;
}

void Timer::setInterval(void (*callback)())
{
    if (!this->active)
    {
        this->startTime = millis();
        this->active = true;
        return;
    }

    unsigned long current = millis();

    if (this->startTime + this->delay < current)
    {
        callback();
        this->active = false;
    }
}
