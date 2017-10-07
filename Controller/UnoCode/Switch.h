/*
  Switch.h - Library for bluesmirf bluetooth Module.
  Created by Jacky, Jul 6, 2017.
*/

#include <SoftwareSerial.h> 
#include <math.h> 
#include "Arduino.h"

#ifndef Switch_h
#define Switch_h

#define sw 17
#define vrx 19
#define vry 18
#define led 4

class Switch
{
  public:
    void setupPins();
    void readPins();
    int readPush();
    int calculateDirection();
    int getSpeed();
    private:
    int switchState;
    double vrxRead;
    double vryRead;
};

#endif
