/*
	Control.h - Class for controlling the robot on a high level.
	Created by Jacky M. Lui 4 November 2015.
	Works within the BUDDY system
*/

/*
	17/01/2016
	Issues with Software Serial dropping out
*/

#ifndef Control_h
#define Control_h

#include "Arduino.h"
#include "MotorControl.h"
#include "Kinematics.h"
#include "Sensors.h"
#include "Test.h"
#include "BluetoothClass.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SET true
#define OFF false

#define SER_IN 29
#define CLK 30
#define L_CLK 28

class Control
{
  public:
    Control() : BMotorControl(2, 4, 3), CMotorControl(7, 8, 6), AMotorControl(11, 12, 5) {
      pinMode(SER_IN, OUTPUT); // Iron Man LED Array
      pinMode(CLK, OUTPUT);
      pinMode(L_CLK, OUTPUT);
    }
    void Controlsetup();
    void MotorController();
    void KinematicsController();
    int * processData(char* reading);
    void LightArray(int direction);
    void runTests();
    void runCode();
    double * outvels;
    double wheelVels[3];
    int * data;

  private:
    MotorControl AMotorControl;
    MotorControl BMotorControl;
    MotorControl CMotorControl;
    Kinematics OmniKinematics;
    Test MyTests;
    Sensors SensorData;
    BluetoothClass mybluetooth;
    char SerialGet;
    int SerialBegin;
    int wheelpow1;
    int wheelpow2;
    int wheelpow3;
    int lightcount;
    String serialDataIn;
    char inbyte;
    int counter;
    int speed;
    int direction;
    int spin;
    int startread;
    
    // Test
    int direct;
};

#endif
