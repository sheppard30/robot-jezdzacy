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
