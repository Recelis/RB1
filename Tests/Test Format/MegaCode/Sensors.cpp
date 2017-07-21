/* 
  Sensors.cpp - Class for inputting the sensor data for RC-1.
  Created by Jacky M. Lui 27 December 2016.
  Works within the BUDDY system
*/


#include "Sensors.h"
#define IR_F 10
#define IR_R 9
#define IR_B 12
#define IR_L 11 
#define VoltPin 39

void Sensors::SensorsSetup()
{
  Rightrange = -1;
  Backrange = -1;
  Leftrange = -1;
  Frontrange = -1;
  Downrange = -1;
  pinMode(VoltPin, INPUT);
  long ultrasonicReturn[7];
  for (int ii = 0; ii < 7; ii++)
  {
    ultrasonicReturn[ii] = -1;
  }
}

int Sensors::readVoltageLevel()
{
  Serial.println(analogRead(VoltPin));
  return analogRead(VoltPin);
}


void Sensors::ultrasonicCon()
{
   Rightrange = ultrasonic_R.Ranging(CM);
   Backrange = ultrasonic_B.Ranging(CM);   
   Leftrange = ultrasonic_L.Ranging(CM);   
   Frontrange = ultrasonic_F.Ranging(CM);
   Downrange = ultrasonic_D.Ranging(CM); 
}

int* Sensors::ultrasonicOutputs()
{
   ultrasonicCon();
   int ultrasonicReturn[7];
   ultrasonicReturn[0] =  Rightrange;
   ultrasonicReturn[1] =  Backrange;
   ultrasonicReturn[2] =  Leftrange;
   ultrasonicReturn[3] =  Frontrange;
   ultrasonicReturn[4] =  Downrange;
//   for (int ii =0; ii < 5; ii++){
//    Serial.print("reading of ultrasonic return is: ");
//    Serial.println(ultrasonicReturn[ii]);
//   }
   ultraPoint = ultrasonicReturn;
   return ultraPoint;
}


int Sensors::compass(){
  return onboardCompass.getHeading();
}



