/*
  MotorControl.h - Library for controlling the motors 
  on a low level. 
  Created by Jacky M. Lui 22 October 2015.
  Works within the BUDDY system
*/

#ifndef MotorControl_h
#define MotorControl_h

#include "Arduino.h"

class MotorControl
{
public:
  MotorControl(int motorin1, int motorin2);
  void setupinput();
  void forward(int speed);
  void reverse(int speed);
  void drive(int speed);
  void coast();
  void brake();

private:
  int _motorin1;
  int _motorin2;
  int _motorset;
};

#endif