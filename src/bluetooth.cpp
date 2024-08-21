#include <SoftwareSerial.h>
#include "Bluetooth.h"

Bluetooth::Bluetooth() : serial(RX_BT, TX_BT)
{
    this->data = "";
    this->dataComplete = false;
}

void Bluetooth::begin()
{
    this->serial.begin(9600);
}

void Bluetooth::onDataAvailable(void (*callback)(String))
{
    while (this->serial.available())
    {
        char inChar = (char)this->serial.read();

        if (inChar == '\n')
        {
            this->dataComplete = true;
        }
        else
        {
            this->data += inChar;
        }
    }

    if (dataComplete)
    {
        Serial.println(this->data);

        this->data = "";
        this->dataComplete = false;

        callback(this->data);
    }
}