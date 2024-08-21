#ifndef BLUETOOTH_H
#define BLUETOOTH_H

// Definicja pinów do komunikacji z modułem Bluetooth
#define RX_BT 3 // Pin RX modułu Bluetooth (do odbioru danych)
#define TX_BT 2 // Pin TX modułu Bluetooth (do wysyłania danych)

#include <SoftwareSerial.h>

class Bluetooth
{
private:
    SoftwareSerial serial;
    String data;
    bool dataComplete;

public:
    Bluetooth();

    void begin();
    void onDataAvailable(void (*callback)(String));
};

#endif