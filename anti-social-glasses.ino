/*
All the source code is written by Ji and Rob, from ITECH master program class 2019. this source code is trying control servo by tilt switch.
the circulation tilt switch connect to analog A0 and 5V.
Servos using digital out (5, 6), 5V and gnd.
Tilt switch connect to  analog A0, 5V.   
*/
#include <Servo.h>

Servo leftServo;
Servo rightServo;
int iLServoPin = 5;
int iRServoPin = 6;

void setup() {
  Serial.begin(9600);
  leftServo.attach(iLServoPin);
  rightServo.attach(iRServoPin);
}

void loop() {
  int sensorValue = analogRead(A0);
  //Serial.println(sensorValue);
  delay(100);

   if (sensorValue == 1023) {
    //Serial.println("ON/ closed window");
    rightServo.write(60);
    leftServo.write(0);
  } 
  else  {
    //Serial.println("OFF/ look down");
    rightServo.write(30); //down
    leftServo.write(30);
  }
  
}
