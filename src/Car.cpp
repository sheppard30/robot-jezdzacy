#include "Car.h"

Car::Car(Bluetooth &bt, DistanceSensor &s) : bluetooth(bt), sensor(s), direction(Direction::STOP)
{
}

void Car::begin()
{
    pinMode(ENGINE_INPUT_1, OUTPUT);
    pinMode(ENGINE_INPUT_2, OUTPUT);
    pinMode(ENGINE_INPUT_3, OUTPUT);
    pinMode(ENGINE_INPUT_4, OUTPUT);
    pinMode(ENGINE_1_PWM, OUTPUT);
    pinMode(ENGINE_2_PWM, OUTPUT);
    pinMode(LED_OUTPUT, OUTPUT);

    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, LOW);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, LOW);

    digitalWrite(ENGINE_1_PWM, 255);
    digitalWrite(ENGINE_2_PWM, 255);
}

void Car::listenForCommands()
{

    this->bluetooth.watch([this](String command)
                          { 
                            
    if (command == COMMAND_MOVE_FORWARD)
    {
        Serial.println("Jade do przodu");
        digitalWrite(ENGINE_INPUT_1, LOW);
        digitalWrite(ENGINE_INPUT_2, HIGH);
        digitalWrite(ENGINE_INPUT_3, LOW);
        digitalWrite(ENGINE_INPUT_4, HIGH);
    } else if (command == COMMAND_MOVE_BACKWARD) {
        Serial.println("Jade do tylu");
        digitalWrite(ENGINE_INPUT_1, HIGH);
        digitalWrite(ENGINE_INPUT_2, LOW);
        digitalWrite(ENGINE_INPUT_3, HIGH);
        digitalWrite(ENGINE_INPUT_4, LOW);
    } else if (command == COMMAND_TURN_LEFT) {
        Serial.println("Jade w lewo");
        digitalWrite(ENGINE_INPUT_1, LOW);
        digitalWrite(ENGINE_INPUT_2, HIGH);
        digitalWrite(ENGINE_INPUT_3, LOW);
        digitalWrite(ENGINE_INPUT_4, LOW);
    } else if (command == COMMAND_TURN_RIGHT) {
        Serial.println("Jade w prawo");
        digitalWrite(ENGINE_INPUT_1, LOW);
        digitalWrite(ENGINE_INPUT_2, LOW);
        digitalWrite(ENGINE_INPUT_3, LOW);
        digitalWrite(ENGINE_INPUT_4, HIGH);
    } else if (command == COMMAND_STOP) {
        Serial.println("Halt!");
        digitalWrite(ENGINE_INPUT_1, LOW);
        digitalWrite(ENGINE_INPUT_2, LOW);
        digitalWrite(ENGINE_INPUT_3, LOW);
        digitalWrite(ENGINE_INPUT_4, LOW);
    } });
}

void Car::turnLEDOn()
{
    digitalWrite(LED_OUTPUT, HIGH);
}

void Car::handleDistanceSensor()
{
    this->sensor.initialize();

    if (this->direction == = FORWARD && this->sensor.getDistance() < MIN_DISTANCE)
    {
        digitalWrite(ENGINE_INPUT_1, LOW);
        digitalWrite(ENGINE_INPUT_2, LOW);
        digitalWrite(ENGINE_INPUT_3, LOW);
        digitalWrite(ENGINE_INPUT_4, LOW);
    }
}

void Car::initialize()
{
    this->turnLEDOn();
    this->handleSensor();
    this->listenForCommands();
}