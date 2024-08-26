#ifndef SOFTWARESERIAL_H
#define SOFTWARESERIAL_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#define SOFTWARE_SERIAL_RX 7
#define SOFTWARE_SERIAL_TX 8

class Logger
{
private:
    static SoftwareSerial *softwareSerial;
    static bool isDefaultSerial;

public:
    static void init(bool isDefaultSerial);
    static void debug(String message);
};

#endif