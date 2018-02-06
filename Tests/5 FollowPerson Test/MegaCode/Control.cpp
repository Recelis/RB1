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
  SensorData.SensorsSetup();
  KinematicsDriver.setup();
}

void Control::runCode() {
  // ultrasonic readings
    long* ultrasonicReadings = SensorData.returnUltrasonics();
    Objects.processData(ultrasonicReadings);
    printData(ultrasonicReadings);
    // KinematicsDriver.runKinematics(21,180,0);
    // delay(5000);
    // KinematicsDriver.runKinematics(21,0,0);
    // delay(5000);
  }

  void Control::printData(long* ultrasonicReadings){
    Serial.println("*");
    Serial.println("***********************************************************************New RunCode Loop*******************************************************************");
    for (int ii =0; ii < 6; ++ii){
      String message = "Range of " + ultrasonicOrient[ii] + " is: "; // not sure why first value is printed out as two boxes
      Serial.print(message);
      Serial.println(*(ultrasonicReadings+ii));
    }
  }