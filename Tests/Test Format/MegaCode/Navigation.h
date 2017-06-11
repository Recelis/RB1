/*
  Navigation.h - H-File for RB1 Navigation Vector Fields

  Created by Jacky Lui. June 10, 2017.
*/ 



#ifndef Navigation_h
#define Navigation_h

#include "Arduino.h"

  
class Navigation 
{
  public:
    Navigation();
    int* vectorFields(int *data, int* ultrasonicReadings);
    int * detectedObject(); 
  private:
    int rightSensor;
    int backSensor;
    int leftSensor;
    int frontSensor;
    int downSensor;

    int xdirection;
    int ydirection;
};

#endif
