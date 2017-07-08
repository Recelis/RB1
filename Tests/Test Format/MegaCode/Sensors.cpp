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

void Sensors::SensorsSetup()
{
//  bluetoothTx = 11;
//  bluetoothRx = 12;
//  bluetooth.begin(115200); // The Bluetooth Mate defaults to 115200bps
//  bluetooth.print("Bluetooth is running");
  Rightrange = -1;
  Backrange = -1;
  Leftrange = -1;
  Frontrange = -1;
  Downrange = -1;
  long ultrasonicReturn[7];
  for (int ii = 0; ii < 7; ii++)
  {
    ultrasonicReturn[ii] = -1;
  }
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
   ultrasonicReturn[0] = 0;
//   ultrasonicReturn[1] = 0;
   ultrasonicReturn[2] =  Rightrange;
   ultrasonicReturn[3] =  Backrange;
   ultrasonicReturn[4] =  Leftrange;
   ultrasonicReturn[5] =  Frontrange;
   ultrasonicReturn[6] =  Downrange;
   return ultrasonicReturn;
}


int Sensors::compass(){
  return onboardCompass.getHeading();
}



