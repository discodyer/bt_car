#include "L298NX4.h"
#include "L298N.h"
//定义第一组控制引脚
const unsigned int IN_A1 = 2;
const unsigned int IN_A2 = 4;
const unsigned int EN_A  = 3;
//定义第二组控制引脚
const unsigned int IN_B1 = 7;
const unsigned int IN_B2 = 8;
const unsigned int EN_B  = 5;
//定义第三组控制引脚
const unsigned int IN_C1 = 10;
const unsigned int IN_C2 = 11;
const unsigned int EN_C  = 6;
//定义第四组控制引脚
const unsigned int IN_D1 = 12;
const unsigned int IN_D2 = 13;
const unsigned int EN_D  = 9;

L298NX4 motors( EN_A, IN_A1, IN_A2,
                EN_B, IN_B1, IN_B2, 
                EN_C, IN_C1, IN_C2, 
                EN_D, IN_D1, IN_D2);

//定义两种速度
unsigned short LOW_SPEED = 55;
unsigned short HIGH_SPEED = 255;


void setup() {

Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }
  // Set initial speed for ALL motors
  motors.setSpeed(80);
}

void loop() {
  // Tell both motors to go forward (may depend by your wiring)
  motors.forward();

  // Alternative method:
  // motors.run(L298N::FORWARD);

  //print the motor status in the serial monitor
  printSomeInfo();

  delay(3000);

  // Stop
  motors.stop();

  // Alternative method:
  // motors.run(L298N::STOP);

  printSomeInfo();

  delay(3000);

  // Change individual speeds
  motors.setSpeedA(255);
  motors.setSpeedB(90);

  // Tell motor A to go back (may depend by your wiring)
  motors.backwardA();

  // Alternative method:
  // motors.runA(L298N::BACKWARD);

  // Tell motor B to go forward (may depend by your wiring)
  motors.backwardB();

  // Alternative method:
  // motors.runB(L298N::FORWARD);

  printSomeInfo();

  delay(3000);

  // Stop
  motors.stop();

  printSomeInfo();

  // Change individual speeds
  motors.setSpeedA(90);
  motors.setSpeedB(255);

  delay(3000);
}

/*
Print some informations in Serial Monitor
*/
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
