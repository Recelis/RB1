/* 
	Kinematics.cpp - Library for moving the omni wheel robot.
	Created by Jacky M. Lui 4 November 2015
	Workes within the BUDDY system

  updated on 9 June 2017
*/

#include "Kinematics.h"
#define PI 3.14159265

void Kinematics::setup(){
	  AMotorControl.setupinput();
  	BMotorControl.setupinput();
  	CMotorControl.setupinput();
		// set vels to 0
		for (int ii =0; ii < 3; ii++){
			vels[ii] = 0;
		}
}

void Kinematics::runKinematics(double speed, double direction, double spin){
	calcWheelVelocities(speed, direction, spin);
	Serial.println(vels[0]);
	Serial.println(vels[1]);
	Serial.println(vels[2]);
	AMotorControl.drive(vels[0]);
	BMotorControl.drive(vels[1]);
	CMotorControl.drive(vels[2]);
}

void Kinematics::convertToMotorValues(double* realVels){
		//convert to motor values
	for (int ii = 0; ii < 3; ii++) {
	int lowEnd = 5;
	if (realVels[ii] > 0) vels[ii] = (realVels[ii] / 21 * (21 - lowEnd) + lowEnd) / 21 * 255;
    else if (realVels[ii] < 0) vels[ii] = (realVels[ii] / 21 * (21 - lowEnd) - lowEnd) / 21 * 255;
    else {
      vels[ii] = 0;
		}
	}
}

// direction is in degrees, spin in degrees (max is 115, min -115) assume 9cm radius
void Kinematics::calcWheelVelocities(double speed, double direction, double spin){ 
	double angle = direction*PI/180; // angle is in radians
	double vy = speed * sin(angle);
	double vx =speed * cos(angle);
	
	//calculate wheel speeds in real speeds
	double* realVels = new double[3]; 
	realVels[0] = -0.333*vx - 0.577*vy + 0.18*spin;
	realVels[1] = -0.333*vx + 0.577*vy  +0.18*spin;
	realVels[2] = 0.666*vx + 0*vy + 0.18*spin;
	convertToMotorValues(realVels);
}

Kinematics::~Kinematics(){
	delete vels;
	vels = nullptr;
}
