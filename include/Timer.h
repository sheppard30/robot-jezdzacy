#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
private:
    bool active;
    unsigned long startTime;
    unsigned short delay;

public:
    Timer(unsigned int delay);

    void setInterval(void (*callback)());
};

#endif