#ifndef CONSTANTS
#define CONSTANTS

#define MOTOR_RIGHT_PIN1 2
#define MOTOR_RIGHT_PIN2 3
#define MOTOR_LEFT_PIN1 4
#define MOTOR_LEFT_PIN2 5

#define BLUETOOTH_RX 7
#define BLUETOOTH_TX 8

#define BLUETOOTH_CODE_UP '0'
#define BLUETOOTH_CODE_DOWN '1'
#define BLUETOOTH_CODE_RIGHT '2'
#define BLUETOOTH_CODE_LEFT '3'

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
    not_inversed, // 2
    not_inversed, // 3
    not_inversed, // 4
    not_inversed, // 5
    not_inversed, // 6
    not_inversed, // 7
    not_inversed, // 8
    not_inversed, // 9
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