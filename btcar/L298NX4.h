#ifndef L298NX4_h
#define L298NX4_h

#include "Arduino.h"
#include "L298N.h"

typedef void (*CallBackFunction)();

class L298NX4
{
public:
   L298NX4(
       uint8_t pinEnable_A,
       uint8_t pinIN1_A,
       uint8_t pinIN2_A,
       uint8_t pinEnable_B,
       uint8_t pinIN1_B,
       uint8_t pinIN2_B,
       uint8_t pinEnable_C,
       uint8_t pinIN1_C,
       uint8_t pinIN2_C,
       uint8_t pinEnable_D,
       uint8_t pinIN1_D,
       uint8_t pinIN2_D);

   //MOTOR A
   void setSpeedA(unsigned short pwmVal_A);
   unsigned short getSpeedA();
   void forwardA();
   void forwardForA(unsigned long delay_A, CallBackFunction callback_A);
   void forwardForA(unsigned long delay_A);
   void backwardA();
   void backwardForA(unsigned long delay_A, CallBackFunction callback_A);
   void backwardForA(unsigned long delay_A);
   void runA(L298N::Direction direction_A);
   void runForA(unsigned long delay_A, L298N::Direction direction_A);
   void runForA(unsigned long delay_A, L298N::Direction direction_A, CallBackFunction callback_A);
   void stopA();
   void resetA();
   boolean isMovingA();
   L298N::Direction getDirectionA();

   //MOTOR B
   void setSpeedB(unsigned short pwmVal_B);
   unsigned short getSpeedB();
   void forwardB();
   void forwardForB(unsigned long delay_B, CallBackFunction callback_B);
   void forwardForB(unsigned long delay_B);
   void backwardB();
   void backwardForB(unsigned long delay_B, CallBackFunction callback_B);
   void backwardForB(unsigned long delay_B);
   void runB(L298N::Direction direction_B);
   void runForB(unsigned long delay_B, L298N::Direction direction_B);
   void runForB(unsigned long delay_B, L298N::Direction direction_B, CallBackFunction callback_B);
   void stopB();
   void resetB();
   boolean isMovingB();
   L298N::Direction getDirectionB();



   //MOTOR C
   void setSpeedC(unsigned short pwmVal_C);
   unsigned short getSpeedC();
   void forwardC();
   void forwardForC(unsigned long delay_C, CallBackFunction callback_C);
   void forwardForC(unsigned long delay_C);
   void backwardC();
   void backwardForC(unsigned long delay_C, CallBackFunction callback_C);
   void backwardForC(unsigned long delay_C);
   void runC(L298N::Direction direction_C);
   void runForC(unsigned long delay_C, L298N::Direction direction_C);
   void runForC(unsigned long delay_C, L298N::Direction direction_C, CallBackFunction callback_C);
   void stopC();
   void resetC();
   boolean isMovingC();
   L298N::Direction getDirectionC();

   //MOTOR D
   void setSpeedD(unsigned short pwmVal_D);
   unsigned short getSpeedD();
   void forwardD();
   void forwardForD(unsigned long delay_D, CallBackFunction callback_D);
   void forwardForD(unsigned long delay_D);
   void backwardD();
   void backwardForD(unsigned long delay_D, CallBackFunction callback_D);
   void backwardForD(unsigned long delay_D);
   void runD(L298N::Direction direction_D);
   void runForD(unsigned long delay_D, L298N::Direction direction_D);
   void runForD(unsigned long delay_D, L298N::Direction direction_D, CallBackFunction callback_D);
   void stopD();
   void resetD();
   boolean isMovingD();
   L298N::Direction getDirectionD();

   //All4
   void setSpeed(unsigned short pwmVal);
   void forward();
   void forwardFor(unsigned long delay, CallBackFunction callback);
   void forwardFor(unsigned long delay);
   void backward();
   void backwardFor(unsigned long delay, CallBackFunction callback);
   void backwardFor(unsigned long delay);
   void run(L298N::Direction direction);
   void runFor(unsigned long delay, L298N::Direction direction);
   void runFor(unsigned long delay, L298N::Direction direction, CallBackFunction callback);
   void stop();
   void reset();

private:
   L298N _motorA;
   L298N _motorB;
   L298N _motorC;
   L298N _motorD;


   unsigned long _lastMs;
   boolean _canMove;

   static void fakeCallback();
};

#endif