#ifndef CONSTANTS
#define CONSTANTS

#define MOTOR_RIGHT_FRONT_PIN1 2
#define MOTOR_RIGHT_FRONT_PIN2 3

#define MOTOR_RIGHT_REAR_PIN1 6
#define MOTOR_RIGHT_REAR_PIN2 4


#define MOTOR_LEFT_FRONT_PIN1 9
#define MOTOR_LEFT_FRONT_PIN2 7

#define MOTOR_LEFT_REAR_PIN1 8
#define MOTOR_LEFT_REAR_PIN2 5

#define BLUETOOTH_STATE 14
#define BLUETOOTH_RX 15
#define BLUETOOTH_TX 16
#define BLUETOOTH_GND 17
#define BLUETOOTH_VCC 18
#define BLUETOOTH_EN 19

#define BLUETOOTH_CODE_UP '4'
#define BLUETOOTH_CODE_DOWN '5'
#define BLUETOOTH_CODE_RIGHT '6'
#define BLUETOOTH_CODE_LEFT '7'
#define BLUETOOTH_CODE_STOP '0'

#define pmi(pin) pinMode(pin, INPUT)
#define pmo(pin) pinMode(pin, OUTPUT)

#define dr digitalRead
#define dwh(pin) digitalWrite(pin, !inversed_logic[pin])
#define dwl(pin) digitalWrite(pin, inversed_logic[pin])

#define inversed true
#define not_inversed false

const char inversed_logic[20] = {
    not_inversed, // 0
    not_inversed, // 1
    inversed, // 2
    inversed, // 3
    inversed, // 4
    inversed, // 5
    inversed, // 6
    inversed, // 7
    inversed, // 8
    inversed, // 9
    not_inversed, // 10
    not_inversed, // 11
    not_inversed, // 12
    not_inversed, // 13
    not_inversed, // A0
    not_inversed, // A1
    not_inversed, // A2
    not_inversed, // A3
    not_inversed, // A4
    not_inversed // A5
};

#endif