#include <Arduino.h>
#include <SoftwareSerial.h>
#include "constants.h"
#include "motor.h"

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
MotorController motor_controller;

void setup()
{
    motor_controller.right_motor.setup(MOTOR_RIGHT_PIN1, MOTOR_RIGHT_PIN2);
    motor_controller.left_motor.setup(MOTOR_LEFT_PIN1, MOTOR_LEFT_PIN2);
}

void loop()
{
    if(!bluetooth.available()) return;
    
    switch (bluetooth.read())
    {
        case BLUETOOTH_CODE_UP: motor_controller.moveForward(); break;
        case BLUETOOTH_CODE_DOWN: motor_controller.moveBackward(); break;
        case BLUETOOTH_CODE_RIGHT: motor_controller.turnRight(); break;
        case BLUETOOTH_CODE_LEFT: motor_controller.turnLeft(); break;
    }
    
    delay(50);
    motor_controller.stop();
}