/* 
	Kinematics.h - Library for moving the omni wheel robot.
	Created by Jacky M. Lui 4 November 2015
	Workes within the BUDDY system
*/
	#ifndef Kinematics_h
	#define Kinematics_h

	#include "Arduino.h"
	#include "MotorControl.h"

	class Kinematics
	{
	public:
		Kinematics(): BMotorControl(2,4,3), CMotorControl(7,8,6), AMotorControl(11,12,5){};
		~Kinematics();
		void setup();
		void runKinematics(double speed, double direction, double spin);
	private:
		void calcWheelVelocities(double speed, double direction, double spin);
		void convertToMotorValues(double* realVels);
		MotorControl AMotorControl;
		MotorControl BMotorControl;
		MotorControl CMotorControl;
		double *vels = new double[3];
		
	};

	#endif
