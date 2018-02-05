/*
  MotorControl.cpp - Library for controlling the motors 
  on a low level. 
  Created by Jacky M. Lui 22 October 2015.
  Works within the BUDDY system
*/

#include "MotorControl.h"


MotorControl::MotorControl(int motorin1, int motorin2, int motorset)
{
  // setup pinmodes
  pinMode(motorin1, OUTPUT);
  pinMode(motorin2, OUTPUT);
  pinMode(motorset, OUTPUT);
   
  pinMode(13, OUTPUT);	
  _motorin1 = motorin1;
  _motorin2 = motorin2;
  _motorset = motorset;
}

void MotorControl::setupinput()
{
   // setup input switches
  digitalWrite(_motorset, HIGH); 
}

void MotorControl::forward(int speed)
{
  analogWrite(_motorin1, speed);
  analogWrite(_motorin2, 0);
}

void MotorControl::reverse(int speed)
{
  analogWrite(_motorin1, 0);
  analogWrite(_motorin2, speed);	
}

void MotorControl::drive(int speed) // for kinematics controller
{
  if (speed > 0)
  {
    analogWrite(_motorin1, speed);
    analogWrite(_motorin2, 0);    
  }
  else 
  {
    speed = -speed;
    analogWrite(_motorin1, 0);
    analogWrite(_motorin2, speed);   
  }
}

void MotorControl::brake()
{
  analogWrite(_motorin1, 255);
  analogWrite(_motorin2, 255);	
}

void MotorControl::coast()
{
  analogWrite(_motorin1, 0);
  analogWrite(_motorin2, 0);	
}