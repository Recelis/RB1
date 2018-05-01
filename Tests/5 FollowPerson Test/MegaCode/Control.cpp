/*
	Control.cpp - Class for controlling the robot on a high level.
	Created by Jacky M. Lui 4 November 2015.
	Works within the BUDDY system

  updated on 9 June 2017
*/

#include "Control.h"

void Control::Controlsetup()
{
  Serial.begin(9600); // Begin the serial monitor at 9600bps
  Serial.println("serialMonitor is turned on");
}

void Control::runCode() {
  
    // KinematicsDriver.runKinematics(21,180,0);
    // delay(5000);
    // KinematicsDriver.runKinematics(21,0,0);
    // delay(5000);
  }

  