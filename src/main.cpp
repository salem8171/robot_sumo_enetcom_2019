#include <Arduino.h>
#include <SoftwareSerial.h>
#include "constants.h"
#include "motor.h"

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
QuadMotorController motor_controller;

void setup()
{
    pmi(BLUETOOTH_STATE);
    pmo(BLUETOOTH_GND); dwl(BLUETOOTH_GND);
    pmo(BLUETOOTH_VCC); dwh(BLUETOOTH_VCC);
    pmi(BLUETOOTH_EN);

    motor_controller.front_motors_controller.right_motor.setup(MOTOR_RIGHT_FRONT_PIN1, MOTOR_RIGHT_FRONT_PIN2);
    motor_controller.rear_motors_controller.right_motor.setup(MOTOR_RIGHT_REAR_PIN1, MOTOR_RIGHT_REAR_PIN2);

    motor_controller.front_motors_controller.left_motor.setup(MOTOR_LEFT_FRONT_PIN1, MOTOR_LEFT_FRONT_PIN2);
    motor_controller.rear_motors_controller.left_motor.setup(MOTOR_LEFT_REAR_PIN1, MOTOR_LEFT_REAR_PIN2);

    bluetooth.begin(9600);
}

void loop()
{
    if(!bluetooth.available()) return motor_controller.stop();

    switch(bluetooth.read())
    {
        case BLUETOOTH_CODE_UP: motor_controller.moveForward(); break;
        case BLUETOOTH_CODE_DOWN: motor_controller.moveBackward(); break;
        case BLUETOOTH_CODE_RIGHT: motor_controller.turnRight(); break;
        case BLUETOOTH_CODE_LEFT: motor_controller.turnLeft(); break;
        case BLUETOOTH_CODE_STOP: motor_controller.stop(); break;
    }
    delay(50);
}
