#ifndef MOTOR
#define MOTOR

#include <Arduino.h>
#include "constants.h"

class Motor
{
    public:
        void setup(uint8_t, uint8_t);
        void moveForward();
        void moveBackward();
        void stop();
    
    private:
        uint8_t pin1;
        uint8_t pin2;
};

class MotorController
{
    public:
        Motor right_motor;
        Motor left_motor;

        void moveForward();
        void moveBackward();
        void turnRight();
        void turnLeft();
        void stop();
};

class QuadMotorController
{
    public:
        MotorController front_motors_controller;
        MotorController rear_motors_controller;

        void moveForward();
        void moveBackward();
        void turnRight();
        void turnLeft();
        void stop();
};

void Motor::setup(uint8_t pin1, uint8_t pin2)
{
    this -> pin1 = pin1;
    this -> pin2 = pin2;

    pmo(pin1);
    pmo(pin2);

    stop();
}

void Motor::moveForward()
{
    dwh(pin1);
    dwl(pin2);
}

void Motor::moveBackward()
{
    dwl(pin1);
    dwh(pin2);
}

void Motor::stop()
{
    dwl(pin1);
    dwl(pin2);
}

void MotorController::moveForward()
{
    right_motor.moveForward();
    left_motor.moveForward();
}

void MotorController::moveBackward()
{
    right_motor.moveBackward();
    left_motor.moveBackward();
}

void MotorController::turnRight()
{
    right_motor.moveBackward();
    left_motor.moveForward();
}

void MotorController::turnLeft()
{
    right_motor.moveForward();
    left_motor.moveBackward();
}

void MotorController::stop()
{
    right_motor.stop();
    left_motor.stop();
}

void QuadMotorController::moveForward()
{
    front_motors_controller.moveForward();
    rear_motors_controller.moveForward();
}

void QuadMotorController::moveBackward()
{
    front_motors_controller.moveBackward();
    rear_motors_controller.moveBackward();
}

void QuadMotorController::turnRight()
{
    front_motors_controller.turnRight();
    rear_motors_controller.turnRight();
}

void QuadMotorController::turnLeft()
{
    front_motors_controller.turnLeft();
    rear_motors_controller.turnLeft();
}

void QuadMotorController::stop()
{
    front_motors_controller.stop();
    rear_motors_controller.stop();
}

#endif