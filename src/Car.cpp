#include "Car.h"

Car::Car() : direction(Direction::STOP)
{
}

void Car::begin()
{
    bluetooth.begin();
    distanceSensor.begin();

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

    analogWrite(ENGINE_1_PWM, 120);
    analogWrite(ENGINE_2_PWM, 120);
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
    Logger::debug("Jade do przodu");

    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, HIGH);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, HIGH);

    this->direction = Direction::FORWARD;
}

void Car::goBackward()
{
    Logger::debug("Jade do tylu");

    digitalWrite(ENGINE_INPUT_1, HIGH);
    digitalWrite(ENGINE_INPUT_2, LOW);
    digitalWrite(ENGINE_INPUT_3, HIGH);
    digitalWrite(ENGINE_INPUT_4, LOW);

    this->direction = Direction::BACKWARD;
}

void Car::turnLeft()
{
    Logger::debug("Jade w lewo");

    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, HIGH);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, LOW);

    this->direction = Direction::LEFT;
}

void Car::turnRight()
{
    Logger::debug("Jade w prawo");

    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, LOW);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, HIGH);

    this->direction = Direction::RIGHT;
}

void Car::stop()
{
    Logger::debug("Halt!");

    digitalWrite(ENGINE_INPUT_1, LOW);
    digitalWrite(ENGINE_INPUT_2, LOW);
    digitalWrite(ENGINE_INPUT_3, LOW);
    digitalWrite(ENGINE_INPUT_4, LOW);

    this->direction = Direction::STOP;
}

void Car::handleDistanceSensor()
{
    this->distanceSensor.initialize();

    if (this->direction == Direction::FORWARD && this->distanceSensor.getDistance() < MIN_DISTANCE)
    {
        this->stop();
    }
}

void Car::initialize()
{
    this->turnLEDOn();
    this->handleDistanceSensor();
    this->listenForCommands();
}