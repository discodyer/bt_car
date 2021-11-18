#include <Arduino_FreeRTOS.h>      //using freertos to realize multithreading 

#include "L298NX4.h"
#include "L298N.h"

//init ports of M1
const unsigned int IN_A1 = 4;
const unsigned int IN_A2 = 2;
const unsigned int EN_A  = 3;
//init ports of M2
const unsigned int IN_B1 = 11;
const unsigned int IN_B2 = 10;
const unsigned int EN_B  = 5;
//init ports of M3
const unsigned int IN_C1 = 8;
const unsigned int IN_C2 = 7;
const unsigned int EN_C  = 6;
//init ports of M4
const unsigned int IN_D1 = 13;
const unsigned int IN_D2 = 12;
const unsigned int EN_D  = 9;


/*
         ↑Front↑
      ┌----------┐
   A ▤│M1     M2│▤ B
      │          │
      │          │
      │          │
   C ▤│M3     M4│▤ D
      └----------┘
*/


L298NX4 motors( EN_A, IN_A1, IN_A2,
                EN_B, IN_B1, IN_B2, 
                EN_C, IN_C1, IN_C2, 
                EN_D, IN_D1, IN_D2);



//init two speed
unsigned short LOW_SPEED = 55;
unsigned short HIGH_SPEED = 255;


void printSomeInfo();//print motor info to serial
void debugTestAll();//test all motors 



void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.

  // Set initial speed for ALL motors
  
  }
  motors.setSpeed(200);
}


void loop() {
    debugTestAll();
  //  Empty. Things are done in Tasks.

}


//Print some informations in Serial Monitor

void printSomeInfo()
{
  Serial.print("Motor A is moving = ");
  Serial.print(motors.isMovingA() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motors.getSpeedA());
  Serial.print("Motor B is moving = ");
  Serial.print(motors.isMovingB() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motors.getSpeedB());
}





void debugTestAll()        //test all motors
{
  // motors.setSpeed(80);
  // motors.forward();
  // printSomeInfo();
  // delay(2000);
  // motors.stop();
  
  // motors.backward();
  // printSomeInfo();
  // delay(2000);
  // motors.stop();

  // motors.forwardA();
  // delay(1000);
  // motors.stop();
  // motors.backwardA();
  // delay(1000);
  // motors.stop();

  // motors.forwardB();
  // delay(1000);
  // motors.stop();
  // motors.backwardB();
  // delay(1000);
  // motors.stop();

  // motors.forwardC();
  // delay(1000);
  // motors.stop();
  // motors.backwardC();
  // delay(1000);
  // motors.stop();

  // motors.forwardD();
  // delay(1000);
  // motors.stop();
  // motors.backwardD();
  // delay(1000);
  // motors.stop();

  //半径约为1米逆时针前进

  motors.forwardA();
  motors.forwardC();
  delay(400);
  motors.stop();
  motors.backwardB();
  motors.backwardD();
  delay(200);
  motors.stop();
}
