#ifndef CAR_H
#define CAR_H

#define CMD_MOVE_FORWARD "B0"  // Komenda dla jazdy do przodu
#define CMD_MOVE_BACKWARD "B1" // Komenda dla jazdy do tyłu
#define CMD_TURN_LEFT "B2"     // Komenda dla jazdy w lewo
#define CMD_TURN_RIGHT "B3"    // Komenda dla jazdy w prawo
#define CMD_STOP "B4"          // Komenda stop

#define ENGINE_INPUT_1 4 // Pin IN1 dla silnika 1
#define ENGINE_INPUT_2 5 // Pin IN2 dla silnika 1
#define ENGINE_INPUT_3 6 // Pin IN3 dla silnika 2
#define ENGINE_INPUT_4 7 // Pin IN4 dla silnika 2

#define ENGINE_1_PWM 9
#define ENGINE_2_PWM 10

#include "Bluetooth.h"

class Car
{
private:
    Bluetooth &bluetooth;

    void listenForCommands();

public:
    Car(Bluetooth &bluetooth);

    void run();
};

#endif