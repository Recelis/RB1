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
    int rightSensor;
    int backSensor;
    int leftSensor;
    int frontSensor;
    int downSensor; 
  private:

    int xdirection;
    int ydirection;

    int vector0x;
    int vector0y;

    int vector1x;
    int vector1y;

    int vector2x;
    int vector2y;

    int vorgX;
    int vorgY;
};

#endif
