/*
  Test.h - Library for running tests. 
  Created by Jacky M. Lui 10 June 2017.
  Works within the BUDDY system
*/

#ifndef Test_h
#define Test_h

#include "Arduino.h"
#include "Sensors.h"

class Test
{
 public:
   Test();
   int* spin();
   int* forwardAndBackward();
   int* kinematics();
   void ultrasonics();
   Sensors testSensor;
 private:
  int direct;
  int count;
  int * ultrasonicReadings;
};

#endif


