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
    int rightSensor;
    int middleRightSensor;
    int leftSensor;
    int frontSensor;
    int middleLeftSensor; 
  private:

    int xdirection;
    int ydirection;

    double vector0x;
    double vector0y;

    double vector1x;
    double vector1y;

    double vector2x;
    double vector2y;

    double vector3x;
    double vector3y;

    double vector4x;
    double vector4y;

    double vorgX;
    double vorgY;

    bool notCrisis;
};

#endif
