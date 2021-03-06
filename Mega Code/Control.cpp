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
  SerialTrans.begin(9600);
  SerialTrans.print("Serial ready!");
  AMotorControl.setupinput();
  BMotorControl.setupinput();
  CMotorControl.setupinput();
  lightcount = 0; //start lightcount
  serialDataIn = String("");
  counter = 0;
  speed = 0;
  direction = 0;
  spin = 0;
  inbyte = 'N';
  SerialBegin = 0;
  startread = 1;
  // Test
  direct = 0;
}	

void Control::SerialUno()
{
  // Test Kinematics
  delay(5000);
  direct += 90;
  if (direct >= 360) direct = 0;
  data[0] = "21";
  data[1] = String(direct);
  data[2] = "0";
  speed = data[0].toInt(); // set speed
  direction = data[1].toInt(); // set direction
  spin = data[2].toInt(); // set spin
  Serial.print("direction ");
  Serial.println(data[1]);
  while (SerialTrans.available() > 0 & startread >= 1) 
  {
    inbyte = SerialTrans.read();
    //Reading data
    if (inbyte == 'S')
    {
      startread = 1; //start reading new data
    }
    if (inbyte == 'E')
    {
      startread = 0; // data stream has ended, will be later used to stop reading data into the stream.
    }
    if (startread == 1)
    {
      if (inbyte >= '0' & inbyte <= '9') // detected values
      {
        serialDataIn += inbyte;
        // Serial.print("inbyte is ");
//        Serial.print(inbyte);
      }
      if (inbyte == ' ') // if detected space, input serialDataIn into data cell
      {
        data[counter] = serialDataIn;
        counter++;
        if (counter >= 3)
        {
          counter = 0;
        }
//        Serial.print("SerialDataIn: ");
//        Serial.println(serialDataIn);
        serialDataIn = ""; // Reset serialDataIn
      }
    }
    if (inbyte == 'E') // reset the counter and values
    { 
//       Serial.println("leaving Serial Collection mode");
       counter = 0; // reset counter
       // Save previous speeds
       prevspeed = speed; 
       prevdirection = direction;
       prevspin = spin;
       speed = data[0].toInt(); // set speed
       direction = data[1].toInt(); // set direction
       spin = data[2].toInt(); // set spin
//       Serial.print("Spin0: ");
//       Serial.println(data[2].toInt()); 
       if (speed > 21 | direction > 360 | spin > 360 | spin < -360) // there's been a misreading
       {
        Serial.println("MISREADING: Resetting values");
        speed = prevspeed;
        direction = prevdirection;
        spin = prevspin;
       }
       serialDataIn = ""; // Reset serialDataIn
       for (int ii =0; ii < 3; ii++) // reset data
       {
        data[ii] = ""; 
       }
//       Serial.print("Speed "); 
//       Serial.println(speed);
//       Serial.print("Direction ");
//       Serial.println(direction);
//       Serial.print("Spin ");
//       Serial.println(spin); 
    }
    if (inbyte == 'F') // Emergency Break
    {
      startread = 0;
      speed = 0;
      direction = 0;
      spin = 0;
      serialDataIn = ""; // Reset serialDataIn
      for (int ii =0; ii < 3; ii++) // reset data
      {
        data[ii] = ""; 
      }      
    } 
    inbyte = 'N';//clear inbyte
  }
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
  Serial.println("wheelVels 0 ");
  Serial.println(wheelVels[0]);
  Serial.println("wheelVels 1");
  Serial.println(wheelVels[1]);
  Serial.println("wheelVels 2");
  Serial.println(wheelVels[2]);
  // Convert to 10-21 scale and to power values
  int lowEnd = 5;
  double wheelpower = 0;
  for (int ii =0; ii < 3; ii++){
    if (wheelVels[ii] > 0) wheelpower = (wheelVels[ii]/21*(21-lowEnd)+ lowEnd)/21*255;
    else if (wheelVels[ii] < 0) wheelpower = (wheelVels[ii]/21*(21-lowEnd)- lowEnd)/21*255;
    else {
      wheelpower = 0;
      Serial.print("check ");
      Serial.println(ii);
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
