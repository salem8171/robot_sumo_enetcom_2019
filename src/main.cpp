#include <Arduino.h>
#include "constants.h"
#include "motor.h"
#include <PSX.h>

PSX psx;

MotorController motor_controller;
Motor arm_motor;

void setup()
{
    motor_controller.right_motor.setup(MOTOR_RIGHT_PIN1, MOTOR_RIGHT_PIN2);
    motor_controller.left_motor.setup(MOTOR_LEFT_PIN1, MOTOR_LEFT_PIN2);

    arm_motor.setup(MOTOR_ARM_PIN1, MOTOR_ARM_PIN2);

    psx.setupPins(12, 11, 10, 13, 10);
    psx.config(PSXMODE_ANALOG);
}

void loop()
{
    PSX::PSXDATA PSXdata;
    if (psx.read(PSXdata) != PSXERROR_SUCCESS) return;
    if (PSXdata.buttons & PSXBTN_UP) motor_controller.moveForward();
    if (PSXdata.buttons & PSXBTN_DOWN) motor_controller.moveBackward();
    if (PSXdata.buttons & PSXBTN_RIGHT) motor_controller.turnRight();
    if (PSXdata.buttons & PSXBTN_LEFT) motor_controller.turnLeft();
    if (PSXdata.buttons & PSXBTN_TRIANGLE) arm_motor.moveForward();
    if (PSXdata.buttons & PSXBTN_CROSS) arm_motor.moveBackward();
    delay(10);
    motor_controller.stop();
    arm_motor.stop();
}
