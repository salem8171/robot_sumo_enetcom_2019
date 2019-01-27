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
    Serial.begin(9600);
    bluetooth.begin(9600);
    pmo(10); dwl(10);
    pmo(11); dwh(11);
    pmi(12);
}

void loop()
{
    // if(Serial.available()) bluetooth.write(Serial.read());
    // if(bluetooth.available()) Serial.write(bluetooth.read());
    // return;

     if(!bluetooth.available()) 
    {
        motor_controller.stop();
        return;
    }
    
    switch (bluetooth.read())
    {
        case BLUETOOTH_CODE_UP: motor_controller.moveForward(); break;
        case BLUETOOTH_CODE_DOWN: motor_controller.moveBackward(); break;
        case BLUETOOTH_CODE_RIGHT: motor_controller.turnRight(); break;
        case BLUETOOTH_CODE_LEFT: motor_controller.turnLeft(); break;
        case BLUETOOTH_CODE_STOP: motor_controller.stop(); break;
    }
    delay(155);   
}