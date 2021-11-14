#include "L298NX4.h"
#include "L298N.h"
//定义第一组控制引脚（M1
const unsigned int IN_A1 = 4;
const unsigned int IN_A2 = 2;
const unsigned int EN_A  = 3;
//定义第二组控制引脚（M2
const unsigned int IN_B1 = 11;
const unsigned int IN_B2 = 10;
const unsigned int EN_B  = 5;
//定义第三组控制引脚（M3
const unsigned int IN_C1 = 8;
const unsigned int IN_C2 = 7;
const unsigned int EN_C  = 6;
//定义第四组控制引脚（M4
const unsigned int IN_D1 = 13;
const unsigned int IN_D2 = 12;
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
