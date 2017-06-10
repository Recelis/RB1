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
  AMotorControl.setupinput();
  BMotorControl.setupinput();
  CMotorControl.setupinput();
  lightcount = 0; //start lightcount
  counter = 0;
  speed = 0;
  direction = 0;
  spin = 0;
  
}	

void Control::runCode(){
  SensorData.SensorsSetup();
  SensorData.UltrasonicCon();
  int *ultrasonicReadings;
  ultrasonicReadings = SensorData.UltrasonicOutputs();
  
}

void Control::runTests()
{
    MyTests.navigation();
//  data = MyTests.forwardAndBackward();
//  speed = *data;
//  direction = *(data+1);
//  spin = *(data+2);
} 


void Control::KinematicsController()
{
  outvels = OmniKinematics.DriveDirection(speed,direction,spin);
  wheelVels[0] = *outvels;
  wheelVels[1] = *(outvels+1);
  wheelVels[2] = *(outvels+2); 
}

void Control::MotorController()
{
//  Serial.println("wheelVels 0 ");
//  Serial.println(wheelVels[0]);
//  Serial.println("wheelVels 1");
//  Serial.println(wheelVels[1]);
//  Serial.println("wheelVels 2");
//  Serial.println(wheelVels[2]);
  // Convert to 10-21 scale and to power values
  int lowEnd = 5;
  double wheelpower = 0;
  for (int ii =0; ii < 3; ii++){
    if (wheelVels[ii] > 0) wheelpower = (wheelVels[ii]/21*(21-lowEnd)+ lowEnd)/21*255;
    else if (wheelVels[ii] < 0) wheelpower = (wheelVels[ii]/21*(21-lowEnd)- lowEnd)/21*255;
    else {
      wheelpower = 0;
//      Serial.print("check ");
//      Serial.println(ii);
    }

    switch(ii){
      case 0:
        wheelpow1 = wheelpower;
        break;
      case 1:
        wheelpow2 = wheelpower;
        break;
      case 2:
        wheelpow3 = wheelpower;
        break;
    }
  }  
  AMotorControl.drive(wheelpow1);
  BMotorControl.drive(wheelpow2);
  CMotorControl.drive(wheelpow3);
  startread = 1; // after setting drive speed, go back into serial waiting mode
  // bluetooth.print("bluetooth is running");
//   Serial.println("pow w1 ");
//   Serial.println(wheelpow1);
//   Serial.println("pow w2 ");
//   Serial.println(wheelpow2);
//   Serial.print("pow w3 ");
//   Serial.println(wheelpow3);
  // Remember that without full power, not all of the wheels will move
}

