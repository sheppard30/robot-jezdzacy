#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "Logger.h"

// Definicja pinów do komunikacji z modułem Bluetooth
#define RX_BT 2 // Pin RX modułu Bluetooth (do odbioru danych)
#define TX_BT 3 // Pin TX modułu Bluetooth (do wysyłania danych)

class Bluetooth
{
private:
    SoftwareSerial serial;
    String data;
    bool dataComplete;

public:
    Bluetooth();

    void begin();

    template <typename T>
    void watch(T callback)
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
            Logger::debug("BT: " + this->data);
            callback(this->data);

            this->data = "";
            this->dataComplete = false;
        }
    }
};

#endif