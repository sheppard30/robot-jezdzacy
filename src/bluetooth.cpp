#include <SoftwareSerial.h>
#include <Arduino.h>
#include "bluetooth.h"

// Ustawienie pinów do SoftwareSerial (możesz ustawić inne piny)
SoftwareSerial bluetoothSerial(RX_BT, TX_BT); // RX, TX

String inputString = "";
bool stringComplete = false;

void setupBluetooth()
{
    bluetoothSerial.begin(9600);
}

void handleBluetooth()
{
    while (bluetoothSerial.available())
    {
        char inChar = (char)bluetoothSerial.read();
        inputString += inChar;

        if (inChar == '\n')
        {
            stringComplete = true;
        }
    }

    if (stringComplete)
    {
        Serial.println(inputString);

        inputString = "";
        stringComplete = false;
    }
}