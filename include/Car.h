#ifndef CAR_H
#define CAR_H

#include "Arduino.h"
#include "Bluetooth.h"
#include "DistanceSensor.h"

#define COMMAND_MOVE_FORWARD "B0"  // Komenda dla jazdy do przodu
#define COMMAND_MOVE_BACKWARD "B1" // Komenda dla jazdy do tyłu
#define COMMAND_TURN_LEFT "B2"     // Komenda dla jazdy w lewo
#define COMMAND_TURN_RIGHT "B3"    // Komenda dla jazdy w prawo
#define COMMAND_STOP "B4"          // Komenda stop

#define ENGINE_INPUT_1 14 // Pin IN1 dla silnika 1
#define ENGINE_INPUT_2 15 // Pin IN2 dla silnika 1
#define ENGINE_INPUT_3 16 // Pin IN3 dla silnika 2
#define ENGINE_INPUT_4 17 // Pin IN4 dla silnika 2

#define ENGINE_1_PWM 5
#define ENGINE_2_PWM 6

#define LED_OUTPUT 9

#define MIN_DISTANCE 10.0

enum Direction
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
};

class Car
{
private:
    Bluetooth bluetooth;
    DistanceSensor distanceSensor;
    Direction direction;

    void goForward();
    void goBackward();
    void turnLeft();
    void turnRight();
    void stop();
    void listenForCommands();
    void turnLEDOn();
    void handleDistanceSensor();

public:
    Car();

    void begin();
    void initialize();
};

#endif