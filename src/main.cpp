#include <Arduino.h>
#include <SoftwareSerial.h>
#include "constants.h"
#include "motor.h"

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
MotorController motor_controller;
int time;
void setup()
{
    motor_controller.right_motor.setup(MOTOR_RIGHT_PIN1, MOTOR_RIGHT_PIN2);
    motor_controller.left_motor.setup(MOTOR_LEFT_PIN1, MOTOR_LEFT_PIN2);
    Serial.begin(9600);
    bluetooth.begin(9600);
    pmo(10); dwl(10);
    pmo(11); dwh(11);
    pmi(12);
    time = 0;
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
        //default: motor_controller.stop(); return;
    }
    delay(50);
    motor_controller.stop();    
}
// #include <SoftwareSerial.h>

// SoftwareSerial mySerial(9, 8); // RX, TX

// int r1=2,r2=3,r3=4,r4=5;





// void stp(){
//   digitalWrite(r1,HIGH);
//   digitalWrite(r2,HIGH);
//   digitalWrite(r3,HIGH);
//   digitalWrite(r4,LOW);
// }

// void setup() {
//   pinMode(r1,OUTPUT);
//   pinMode(r2,OUTPUT);
//   pinMode(r3,OUTPUT);
//   pinMode(r4,OUTPUT);
//   pmo(10); dwl(10);
//     pmo(11); dwh(11);
//     pmi(12);
//     mySerial.begin(9600);
//     stp();
// }
// void avance(){
//   digitalWrite(r1,HIGH);
//   digitalWrite(r2,LOW);
//   digitalWrite(r3,HIGH);
//   digitalWrite(r4,HIGH);
  
// }
// void reculer(){
//   digitalWrite(r1,LOW);
//   digitalWrite(r2,HIGH);
//   digitalWrite(r3,LOW);
//   digitalWrite(r4,LOW);
  
// }
// void droit(){
//   digitalWrite(r1,HIGH);
//   digitalWrite(r2,LOW);
//   digitalWrite(r3,LOW);
//   digitalWrite(r4,LOW);
  
// }
// void gauche(){
//   digitalWrite(r1,LOW);
//   digitalWrite(r2,HIGH);
//   digitalWrite(r3,HIGH);
//   digitalWrite(r4,HIGH);
  
// }

// void loop() {
//  if(mySerial.available()){
//   char c= mySerial.read();
//   switch(c){
//     case '4':avance();break;
//     case '5':reculer();break;
//     case '6':droit();break;
//     case '7':gauche();break;
    
    
//   }
//  }
//  else 
//  stp();

// }
