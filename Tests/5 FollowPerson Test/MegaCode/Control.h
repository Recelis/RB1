/*
	Control.h - Class for controlling the robot on a high level.
	Created by Jacky M. Lui 4 November 2015.
	Works within the BUDDY system
*/

/*
	17/01/2016
	Issues with Software Serial dropping out
*/

#ifndef Control_h
#define Control_h

#include "Arduino.h"
#include "Sensors.h"


class Control
{
  public:
    Control(){
    }
    void Controlsetup();
    void runCode();

  private:
    Navigation Navigate;
};

#endif
