#include <Arduino.h>
#include "Setup.h"
#include "Car.h"

void setupSerialMonitor()
{
    Serial.begin(9600);
}

void setupEnginesController()
{
    pinMode(ENGINE_INPUT_1, OUTPUT);
    pinMode(ENGINE_INPUT_2, OUTPUT);
    pinMode(ENGINE_INPUT_3, OUTPUT);
    pinMode(ENGINE_INPUT_4, OUTPUT);
    pinMode(ENGINE_1_PWM, OUTPUT);
    pinMode(ENGINE_2_PWM, OUTPUT);

    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, LOW);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, LOW);
}
