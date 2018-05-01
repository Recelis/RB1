/*
  Ultrasonic.h - Library for HR-SC04 Ultrasonic Ranging Module.
  Created by ITead studio. Alex, Apr 20, 2010.
  iteadstudio.com
*/


#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

#define CM 1
#define INC 0
#define TIMEOUT 13333 // at 300m/s speed of sound for distance of 2m, 4m in total

class Ultrasonic
{
  public:
    Ultrasonic(int TP, int EP);
    long Timing();
    int Ranging(int sys);

    private:
    int Trig_pin;
    int Echo_pin;
    long  duration;
    int distacne_cm,distance_inc;
    
};

#endif
