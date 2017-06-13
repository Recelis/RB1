/*
  Test.h - Library for running tests. 
  Created by Jacky M. Lui 10 June 2017.
  Works within the BUDDY system
*/

#ifndef Test_h
#define Test_h

#include "Arduino.h"
#include "Sensors.h"
#include "Navigation.h"

class Test
{
 public:
   Test();
   int* spin();
   int* forwardAndBackward();
   int* kinematics();
   int* ultrasonics();
   void compass();
   Sensors testSensor;
   Navigation testNavigation;
   int* navigation();
 private:
  int direct;
  int count;
  
};

#endif


