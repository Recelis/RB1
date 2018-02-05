/* 
  Sensors.cpp - Class for inputting the sensor data for RC-1.
  Created by Jacky M. Lui 27 December 2016.
  Works within the BUDDY system
*/


#include "Sensors.h"

void Sensors::SensorsSetup()
{
  for (int ii = 0; ii < 7; ii++){
    ultrasonicReturn[ii] = -1;
    Serial.println(ultrasonicReturn[ii]);
  }
}

/*
  Values within ultrasonicReturn
  F -0 
  FR -1
  BR -2
  FL -3
  BL -4 
  B -5
*/

void Sensors::ultrasonicCon()
{
   *ultrasonicReturn = ultraF.Ranging(CM);
   *(ultrasonicReturn + 1) = ultraFR.Ranging(CM);   
   *(ultrasonicReturn + 2) = ultraBR.Ranging(CM);   
   *(ultrasonicReturn + 3) = ultraFL.Ranging(CM);
   *(ultrasonicReturn + 4)  = ultraBL.Ranging(CM); 
   *(ultrasonicReturn + 5)  = ultraB.Ranging(CM); 
}

long* Sensors::returnUltrasonics(){
  ultrasonicCon();
  return ultrasonicReturn;
}



Sensors::~Sensors(){

}


