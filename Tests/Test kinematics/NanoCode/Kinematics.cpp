/* 
	Kinematics.cpp - Library for moving the omni wheel robot.
	Created by Jacky M. Lui 4 November 2015
	Workes within the BUDDY system
*/

#include "Kinematics.h"
#define PI 3.14159265

Kinematics::Kinematics()
{

}

int * Kinematics::RotateClockWise(double speed)
{

}

int * Kinematics::RotateAntiClockWise(double speed)
{

}

int * Kinematics::DriveDirection(double speed, double direction, double spin) // direction is in degrees, spin in degrees (max is 135)
{
	static int vels[3];
	
	// Define important variables 
	int angle = direction*PI/180; // angle is in radians
  int vy = speed * sin(angle);
  int vx =speed * cos(angle);
  
	//calculate wheel speeds in real speeds
	vels[0] = -0.6667*vx + 0*vy + 0.3333*spin*PI/180;
	vels[1] = 0.3333*vx + 0.5774*vy + 0.3333*spin*PI/180;
	vels[2] = 0.3333*vx - 0.5774*vy + 0.3333*spin*PI/180;
	if (speed == 0 && direction == 0)
	{
		Serial.print("Spin: ");
		Serial.println(spin);
		//calculate wheel speeds in real speeds
		vels[0] = (int) spin/6.4;
		vels[1] = (int) spin/6.4;
		vels[2] = (int) spin/6.4;	
	} 
	// Serial.println("vy ");
	// Serial.println(vy);
	// Serial.println("vx ");
	// Serial.println(vx);


	return vels;
}
