/* 
	Kinematics.h - Library for moving the omni wheel robot.
	Created by Jacky M. Lui 4 November 2015
	Workes within the BUDDY system
*/
	#ifndef Kinematics_h
	#define Kinematics_h

	#include "Arduino.h"
	// #include <SoftwareSerial.h>	

	class Kinematics
	{
	public:
		Kinematics();
		int * RotateClockWise(double speed);
		int * RotateAntiClockWise(double speed);
		int * DriveDirection(double speed, double direction, double spin);
	private:
		
	};

	#endif