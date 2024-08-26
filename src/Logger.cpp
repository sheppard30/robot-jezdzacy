#include "Logger.h"

SoftwareSerial *Logger::softwareSerial = nullptr;
bool Logger::isDefaultSerial = true;

void Logger::init(bool isDefaultSerial)
{
    Logger::isDefaultSerial = isDefaultSerial;
    Logger::softwareSerial = new SoftwareSerial(SOFTWARE_SERIAL_RX, SOFTWARE_SERIAL_TX);
    Logger::softwareSerial->begin(9600);
    Serial.begin(9600);
}

void Logger::debug(String message)
{
    if (Logger::isDefaultSerial)
    {
        Serial.println(message);
    }
    else
    {
        Logger::softwareSerial->println(message);
    }
}