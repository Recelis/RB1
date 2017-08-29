/* 
  Sensors.cpp - Class for inputting the sensor data for RC-1.
  Created by Jacky M. Lui 27 December 2016.
  Works within the BUDDY system
*/


#include "Sensors.h"
#define VoltPin A15

void Sensors::SensorsSetup()
{
  Rightrange = -1;
  middleRightrange = -1;
  Leftrange = -1;
  Frontrange = -1;
  middleLeftrange = -1;
//  pinMode(VoltPin, INPUT);
  long ultrasonicReturn[7];
  for (int ii = 0; ii < 7; ii++)
  {
    ultrasonicReturn[ii] = -1;
  }
}

int Sensors::readVoltageLevel()
{
  
  int voltageLevel = analogRead(VoltPin);
  
  return voltageLevel;
}


void Sensors::ultrasonicCon()
{
   Rightrange = ultrasonic_R.Ranging(CM);
   middleRightrange = ultrasonic_MR.Ranging(CM);   
   Leftrange = ultrasonic_L.Ranging(CM);   
   Frontrange = ultrasonic_F.Ranging(CM);
   middleLeftrange = ultrasonic_ML.Ranging(CM); 
}

int* Sensors::ultrasonicOutputs()
{
   ultrasonicCon();
   static int ultrasonicReturn[5];
   ultrasonicReturn[0] =  Rightrange;
   ultrasonicReturn[1] =  middleRightrange;
   ultrasonicReturn[2] =  Leftrange;
   ultrasonicReturn[3] =  Frontrange;
   ultrasonicReturn[4] =  middleLeftrange;
   return ultrasonicReturn;
}


int Sensors::compass(){
  return onboardCompass.getHeading();
}

/*
 
 Serial.print("voltage is:");
 Serial.println(voltageLevel);
  
 */

