/*
  compass.h - Library for HMC6352 Sparkfun Compass Module.
  Created by ITead studio. Alex, Apr 20, 2010.
  modified by Jacky Lui 11 June 2017
*/


#ifndef compass_h
#define compass_h

#include "Arduino.h"
#include <Wire.h>

class Compass
{
  public:
    Compass();
    int getHeading();
    private:
      int HMC6352SlaveAddress = 0x42;
      int HMC6352ReadAddress = 0x41; //"A" in hex, A command is:
      int headingValue; 
};

#endif
