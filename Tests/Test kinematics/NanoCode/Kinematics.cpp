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

double * Kinematics::DriveDirection(double speed, double direction, double spin) // direction is in degrees, spin in degrees (max is 135)
{
	static double vels[3];
	
	// Define important variables 
	double angle = direction*PI/180; // angle is in radians
  double vy = speed * sin(angle);
  double vx =speed * cos(angle);
  double radSpin = spin*PI/180; 
	//calculate wheel speeds in real speeds
	vels[0] = -0.1547*vx + 0.5773*vy + 5.196*radSpin;
	vels[1] = 2.1547*vx - 0.57735*vy  -5.196*radSpin;
	vels[2] = -2*vx + 0*vy + 9*radSpin;
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
