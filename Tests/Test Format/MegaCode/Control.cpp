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
  AMotorControl.setupinput();
  BMotorControl.setupinput();
  CMotorControl.setupinput();
  lightcount = 0; //start lightcount
  counter = 0;
  speed = 0;
  direction = 0;
  spin = 0;
  mybluetooth.setupBlue();
  
}

void Control::runCode() {
  SensorData.SensorsSetup();
  int *ultrasonicReadings;
  ultrasonicReadings = SensorData.ultrasonicOutputs();
  int heading = SensorData.compass();

}

void Control::runTests()
{
  char* raw = mybluetooth.sendReceiveData();
  
  if (mybluetooth.receivedFlag) {
    procData = processData(raw);
    Serial.println(*(procData+1));
    Serial.println(*(procData+2));
    Serial.println(*(procData+3));
    MyTests.compass();
    data = MyTests.navigation(procData);
    //  //  data = MyTests.forwardAndBackward();
    speed = *(data + 1);
    direction = *(data + 2);
    spin = *(data + 3);
    Serial.print("Speed: ");
    Serial.println(speed);
    Serial.print("Direction: ");
    Serial.println(direction);
    Serial.print("Spin: ");
    Serial.println(spin);
    LightArray(direction);
  } 
}

int* Control::processData(char* reading) {
  int blueData [4];
  char stringSpeed[10];
  char stringDirection[10];
  bool readingSpeedFlag = false;
  bool readingDirectionFlag = false;
  int speedCount = 0;
  int directCount = 0;
  // placeholder values
  blueData[0] = 0; // placeholder
  blueData[1] = 0; // speed
  blueData[2] = 90; // direction
  blueData[3] = 0; // spin
  char * pEnd;
  char * pdEnd;
  for (int ii = 0; ii < 20; ii++) {

    char scanValue = *(reading + ii);

    // getting speed
    if (scanValue == 'S') {
      readingSpeedFlag = true;
      continue;
    }
    if (readingSpeedFlag == true) {
      if (scanValue == '\r' || scanValue == '\n' || scanValue == ' ') {
        blueData[1] = strtol(stringSpeed, NULL, 10);
        //        Serial.println(blueData[1]);
        speedCount = 0;
        readingSpeedFlag = false;
        memset(stringSpeed, '-', 10);
      }
      else {
        stringSpeed[speedCount] = scanValue;
        speedCount++;
      }
    }


    // getting direction
    if (scanValue == 'D') {
      readingDirectionFlag = true;
      continue;
    }
    if (readingDirectionFlag == true) {
      if (scanValue == '\r' || scanValue == '\n' || scanValue == ' ') {
        blueData[2] = strtol(stringDirection, NULL, 10);
        //        Serial.println(blueData[2]);
        directCount = 0;
        readingDirectionFlag = false;
        memset(stringDirection, '-', 10);
      }
      else {
        stringDirection[directCount] = scanValue;
        directCount++;
      }
    }
  }
  int *processPoint;
  processPoint = blueData;
  return processPoint;
}



void Control::KinematicsController()
{
  outvels = OmniKinematics.DriveDirection(speed, direction, spin);
  wheelVels[0] = *outvels;
  wheelVels[1] = *(outvels + 1);
  wheelVels[2] = *(outvels + 2);
}

void Control::MotorController()
{
  //  Serial.println("wheelVels 0 ");
  //  Serial.println(wheelVels[0]);
  //  Serial.println("wheelVels 1");
  //  Serial.println(wheelVels[1]);
  //  Serial.println("wheelVels 2");
  //  Serial.println(wheelVels[2]);
  // Convert to 10-21 scale and to power values
  int lowEnd = 5;
  double wheelpower = 0;
  for (int ii = 0; ii < 3; ii++) {
    if (wheelVels[ii] > 0) wheelpower = (wheelVels[ii] / 21 * (21 - lowEnd) + lowEnd) / 21 * 255;
    else if (wheelVels[ii] < 0) wheelpower = (wheelVels[ii] / 21 * (21 - lowEnd) - lowEnd) / 21 * 255;
    else {
      wheelpower = 0;
      //      Serial.print("check ");
      //      Serial.println(ii);
    }

    switch (ii) {
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

void Control::LightArray(int direction) {
  // position of light
  int lightMask[8] = {1, 1, 1, 1, 1, 1, 1, 1};
  if (direction < 0) direction = 360 + direction;
  if (direction < 22.5 || direction >= 337.5) lightMask[1] = 0;
  else if (direction >= 22.5 && direction < 67.5) lightMask[0] = 0;
  else if (direction >= 67.5 && direction < 112.5) lightMask[7] = 0;
  else if (direction >= 112.5 && direction < 157.5) lightMask[4] = 0;
  else if (direction >= 157.5 && direction < 202.5) lightMask[6] = 0;
  else if (direction >= 202.5 && direction < 247.5) lightMask[5] = 0;
  else if (direction >= 247.5 && direction < 292.5) lightMask[3] = 0;
  else if (direction >= 292.5 && direction < 337.5) lightMask[2] = 0;
  else {};

  digitalWrite(L_CLK, LOW);
  digitalWrite(CLK, LOW);
  digitalWrite(SER_IN, LOW);
  for (int ii = 0; ii < 8; ii++) {
    //    Serial.println(ii);
    digitalWrite(CLK, LOW);
    delay(2);
    if (lightMask[ii] == 0) {
      //      Serial.println("low");
      digitalWrite(SER_IN, LOW);
    }
    else {
      //      Serial.println("HIGH");
      digitalWrite(SER_IN, HIGH);
    }
    digitalWrite(CLK, HIGH);
    delay(2);
  }
  digitalWrite(L_CLK, HIGH);
  delay(10);

}

