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
	// fill vels with zeros first
	for (int ii = 0; ii < 3; ii++)
	{
		vels[ii] = 0;
	}
	// Define important variables 
	int vy1 = 0;
	int vy2 = 0;
	int vx1 = 0;
	int vx2 = 0;
	int vy = 0;
	int vx =0;
	int angle = direction*PI/180; // angle is in radians

	if (direction != 90 || direction != 270)
	{
		vy1 = sqrt(speed*speed/(1+tan(angle)*tan(angle)));
		vy2 = -sqrt(speed*speed/(1+tan(angle)*tan(angle)));
		vx1 = vy1*tan(angle);
		vx2 = vy2*tan(angle);
		vy = 0;
		vx = 0;
	}
	else 
	{
		
	}
	if (direction < 90 || direction > 270)
	{
		vy = vy1;
		vx = vx1;
	}
	else 
	{	
		vy = vy2;
		vx = vx2;
	}

	// Make Sure tan angle doesn't become infinity
	switch ((int)direction) 
	{
		case (90):
			vx = speed;
			vy = 0;
			break;
		case (270):
			vx = -speed;
			vy = 0;
			break;
	}

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