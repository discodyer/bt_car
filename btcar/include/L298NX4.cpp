/*
  L298N.cpp - Libreria per gestire i movimenti di un motore DC con il modulo L298N
  Autore:   Andrea Lombardo
  Sito web: http://www.lombardoandrea.com  
*/

#include "L298NX4.h"
#include "L298N.h"

#define DEBUG 0

typedef void (*CallBackFunction)();

L298NX4::L298NX4(uint8_t pinEnable_A,
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
                uint8_t pinIN2_D) : _motorA(pinEnable_A,
                                             pinIN1_A,
                                             pinIN2_A),
                                    _motorB(pinEnable_B,
                                             pinIN1_B,
                                             pinIN2_B),
                                    _motorC(pinEnable_C,
                                             pinIN1_C,
                                             pinIN2_C),
                                    _motorD(pinEnable_D,
                                             pinIN1_D,
                                             pinIN2_D)
{
  _canMove = true;
  _lastMs = 0;
}


void trace(String msg)
{
  if (DEBUG)
  {
    Serial.println(msg);
  }
}

//Motor A
void L298NX4::setSpeedA(unsigned short pwmVal)
{
  _motorA.setSpeed(pwmVal);
}

unsigned short L298NX4::getSpeedA()
{
  return _motorA.getSpeed();
}

void L298NX4::forwardA()
{
  _motorA.forward();
}

void L298NX4::backwardA()
{
  _motorA.backward();
}

void L298NX4::runA(L298N::Direction direction)
{
  _motorA.run(direction);
}

void L298NX4::runForA(unsigned long delay_A, L298N::Direction direction_A)
{
  trace("runForA(d, d)");
  _motorA.runFor(delay_A, direction_A);
}

void L298NX4::runForA(unsigned long delay_A, L298N::Direction direction_A, CallBackFunction callback_A)
{
  trace("runForA(d, d, c)");
  _motorA.runFor(delay_A, direction_A, callback_A);
}

void L298NX4::forwardForA(unsigned long delay, CallBackFunction callback)
{
  this->runForA(delay, L298N::FORWARD, callback);
}

void L298NX4::forwardForA(unsigned long delay)
{
  this->runForA(delay, L298N::FORWARD);
}

void L298NX4::backwardForA(unsigned long delay, CallBackFunction callback)
{
  this->runForA(delay, L298N::BACKWARD, callback);
}

void L298NX4::backwardForA(unsigned long delay)
{
  this->runForA(delay, L298N::BACKWARD);
}

void L298NX4::stopA()
{
  _motorA.stop();
}

void L298NX4::resetA()
{
  _motorA.reset();
}

boolean L298NX4::isMovingA()
{
  return _motorA.isMoving();
}

L298N::Direction L298NX4::getDirectionA()
{
  return _motorA.getDirection();
}

/*















*/

//Motor B
void L298NX4::setSpeedB(unsigned short pwmVal)
{
  _motorB.setSpeed(pwmVal);
}

unsigned short L298NX4::getSpeedB()
{
  return _motorB.getSpeed();
}

void L298NX4::forwardB()
{
  _motorB.forward();
}
void L298NX4::backwardB()
{
  _motorB.backward();
}

void L298NX4::runB(L298N::Direction direction)
{
  _motorB.run(direction);
}

void L298NX4::runForB(unsigned long delay_B, L298N::Direction direction_B)
{
  _motorB.runFor(delay_B, direction_B);
}
void L298NX4::runForB(unsigned long delay_B, L298N::Direction direction_B, CallBackFunction callback_B)
{
  _motorB.runFor(delay_B, direction_B, callback_B);
}

void L298NX4::forwardForB(unsigned long delay, CallBackFunction callback)
{
  this->runForB(delay, L298N::FORWARD, callback);
}

void L298NX4::forwardForB(unsigned long delay)
{
  this->runForB(delay, L298N::FORWARD);
}

void L298NX4::backwardForB(unsigned long delay, CallBackFunction callback)
{
  this->runForB(delay, L298N::BACKWARD, callback);
}

void L298NX4::backwardForB(unsigned long delay)
{
  this->runForB(delay, L298N::BACKWARD);
}

void L298NX4::stopB()
{
  _motorB.stop();
}

void L298NX4::resetB()
{
  _motorB.reset();
}

boolean L298NX4::isMovingB()
{
  return _motorB.isMoving();
}

L298N::Direction L298NX4::getDirectionB()
{
  return _motorB.getDirection();
}

/*
















*/
//Motor C
void L298NX4::setSpeedC(unsigned short pwmVal)
{
  _motorC.setSpeed(pwmVal);
}

unsigned short L298NX4::getSpeedC()
{
  return _motorC.getSpeed();
}

void L298NX4::forwardC()
{
  _motorC.forward();
}

void L298NX4::backwardC()
{
  _motorC.backward();
}

void L298NX4::runC(L298N::Direction direction)
{
  _motorC.run(direction);
}

void L298NX4::runForC(unsigned long delay_C, L298N::Direction direction_C)
{
  trace("runForC(d, d)");
  _motorC.runFor(delay_C, direction_C);
}

void L298NX4::runForC(unsigned long delay_C, L298N::Direction direction_C, CallBackFunction callback_C)
{
  trace("runForC(d, d, c)");
  _motorC.runFor(delay_C, direction_C, callback_C);
}

void L298NX4::forwardForC(unsigned long delay, CallBackFunction callback)
{
  this->runForC(delay, L298N::FORWARD, callback);
}

void L298NX4::forwardForC(unsigned long delay)
{
  this->runForC(delay, L298N::FORWARD);
}

void L298NX4::backwardForC(unsigned long delay, CallBackFunction callback)
{
  this->runForC(delay, L298N::BACKWARD, callback);
}

void L298NX4::backwardForC(unsigned long delay)
{
  this->runForC(delay, L298N::BACKWARD);
}

void L298NX4::stopC()
{
  _motorC.stop();
}

void L298NX4::resetC()
{
  _motorC.reset();
}

boolean L298NX4::isMovingC()
{
  return _motorC.isMoving();
}

L298N::Direction L298NX4::getDirectionC()
{
  return _motorC.getDirection();
}

/*
















*/
//Motor D
void L298NX4::setSpeedD(unsigned short pwmVal)
{
  _motorD.setSpeed(pwmVal);
}

unsigned short L298NX4::getSpeedD()
{
  return _motorD.getSpeed();
}

void L298NX4::forwardD()
{
  _motorD.forward();
}

void L298NX4::backwardD()
{
  _motorD.backward();
}

void L298NX4::runD(L298N::Direction direction)
{
  _motorD.run(direction);
}

void L298NX4::runForD(unsigned long delay_D, L298N::Direction direction_D)
{
  trace("runForD(d, d)");
  _motorD.runFor(delay_D, direction_D);
}

void L298NX4::runForD(unsigned long delay_D, L298N::Direction direction_D, CallBackFunction callback_D)
{
  trace("runForD(d, d, c)");
  _motorD.runFor(delay_D, direction_D, callback_D);
}

void L298NX4::forwardForD(unsigned long delay, CallBackFunction callback)
{
  this->runForD(delay, L298N::FORWARD, callback);
}

void L298NX4::forwardForD(unsigned long delay)
{
  this->runForD(delay, L298N::FORWARD);
}

void L298NX4::backwardForD(unsigned long delay, CallBackFunction callback)
{
  this->runForD(delay, L298N::BACKWARD, callback);
}

void L298NX4::backwardForD(unsigned long delay)
{
  this->runForD(delay, L298N::BACKWARD);
}

void L298NX4::stopD()
{
  _motorD.stop();
}

void L298NX4::resetD()
{
  _motorD.reset();
}

boolean L298NX4::isMovingD()
{
  return _motorD.isMoving();
}

L298N::Direction L298NX4::getDirectionD()
{
  return _motorD.getDirection();
}

/*
















*/

// ALL
void L298NX4::setSpeed(unsigned short pwmVal)
{
  _motorA.setSpeed(pwmVal);
  _motorB.setSpeed(pwmVal);
  _motorC.setSpeed(pwmVal);
  _motorD.setSpeed(pwmVal);
}

void L298NX4::forward()
{
  _motorA.forward();
  _motorB.forward();
  _motorC.forward();
  _motorD.forward();
}

void L298NX4::backward()
{
  _motorA.backward();
  _motorB.backward();
  _motorC.backward();
  _motorD.backward();
}

void L298NX4::run(L298N::Direction direction)
{
  _motorA.run(direction);
  _motorB.run(direction);
  _motorC.run(direction);
  _motorD.run(direction);
}

//Timing and callback
void L298NX4::runFor(unsigned long delay, L298N::Direction direction, CallBackFunction callback)
{

  if ((_lastMs == 0) && _canMove)
  {
    _lastMs = millis();
    switch (direction)
    {
    case L298N::FORWARD:
      this->forward();
      break;
    case L298N::BACKWARD:
      this->backward();
      break;
    case L298N::STOP:
    default:
      this->stop();
      break;
    }
  }

  if (((millis() - _lastMs) > delay) && _canMove)
  {
    this->stop();
    _lastMs = 0;
    _canMove = false;

    callback();
  }
}

void L298NX4::runFor(unsigned long delay, L298N::Direction direction)
{
  this->runFor(delay, direction, fakeCallback);
}

void L298NX4::forwardFor(unsigned long delay, CallBackFunction callback)
{
  this->runFor(delay, L298N::FORWARD, callback);
}

void L298NX4::forwardFor(unsigned long delay)
{
  this->runFor(delay, L298N::FORWARD);
}

void L298NX4::backwardFor(unsigned long delay, CallBackFunction callback)
{
  this->runFor(delay, L298N::BACKWARD, callback);
}

void L298NX4::backwardFor(unsigned long delay)
{
  this->runFor(delay, L298N::BACKWARD);
}

void L298NX4::stop()
{
  _motorA.stop();
  _motorB.stop();
  _motorC.stop();
  _motorD.stop();
}

void L298NX4::reset()
{
  _canMove = true;
  _motorA.reset();
  _motorB.reset();
  _motorC.reset();
  _motorD.reset();
}

void L298NX4::fakeCallback()
{
}
