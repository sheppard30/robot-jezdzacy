#include "Car.h"

Car::Car() : direction(Direction::STOP)
{
}

void Car::begin()
{
    this->bluetooth.begin();
    this->distanceSensor.begin();

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
        this->goForward();
    } else if (command == COMMAND_MOVE_BACKWARD) {
        this->goBackward();
    } else if (command == COMMAND_TURN_LEFT) {
        this->turnLeft();
    } else if (command == COMMAND_TURN_RIGHT) {
        this->turnRight();
    } else if (command == COMMAND_STOP) {
        this->stop();
    } });
}

void Car::turnLEDOn()
{
    digitalWrite(LED_OUTPUT, HIGH);
}

void Car::goForward()
{
    debug.println("Jade do przodu");

    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, HIGH);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, HIGH);

    this->direction = Direction::FORWARD;
}

void Car::goBackward()
{
    debug.println("Jade do tylu");

    digitalWrite(ENGINE_INPUT_1, HIGH);
    digitalWrite(ENGINE_INPUT_2, LOW);
    digitalWrite(ENGINE_INPUT_3, HIGH);
    digitalWrite(ENGINE_INPUT_4, LOW);

    this->direction = Direction::BACKWARD;
}

void Car::turnLeft()
{
    debug.println("Jade w lewo");
    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, HIGH);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, LOW);

    this->direction = Direction::LEFT;
}

void Car::turnRight()
{
    debug.println("Jade w prawo");
    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, LOW);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, HIGH);

    this->direction = Direction::RIGHT;
}

void Car::stop()
{
    debug.println("Halt!");
    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, LOW);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, LOW);

    this->direction = Direction::STOP;
}

void Car::handleDistanceSensor()
{
    this->distanceSensor.initialize();

    if (this->direction == FORWARD && this->distanceSensor.getDistance() < MIN_DISTANCE)
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
    this->handleDistanceSensor();
    this->listenForCommands();
}