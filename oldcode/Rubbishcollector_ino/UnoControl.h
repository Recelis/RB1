/* 
	UnoControl.h - Class for controlling the robot on a high level on the Uno.
	Created by Jacky M. Lui 8 December 2015.
	Works within the BUDDY system
*/

#ifndef UnoControl_h
#define UnoControl_h

#include "Arduino.h"
#include <math.h>
#include "AltSoftSerial.h"
#include "Ultrasonic.h"
#include "Sensors.h"
#include <math.h>
	
#define SET 1  
#define OFF 0
#define DEBOUNCE 2


class UnoControl
{
public:
	UnoControl() : SerialTrans(19,18), SerialTransEleven(9,10){
		pinMode(13, OUTPUT); // Built in LED 
	}
	void UnoControlsetup();
  void Interface();
  void SerialNano();
	void Light(int l_switch);
  void Navigation();
  void DangerScenarios();
  void SensorUno();
  void ComputerRead();
  void SerialEleven();
  int Rightsensor;
  int Backsensor;
  int Leftsensor;
  int Frontsensor;
  int Downsensor;
  
  
private:
  AltSoftSerial SerialTrans;
  AltSoftSerial SerialTransEleven;
  Sensors SensorCon;
  int SerialStart;
  char SerialListen;
  int dropoutcount;
  int lightcount;
  int robspeed;
  int robdirection;
  int robspin;
  int prevrobspeed;
  int prevrobdirection;
  int prevrobspin;
  long * UltrasonicReturn;
  char ComputerCommand;
  int ComputerStop;
  int Danger_Flag;
  int xdirection;
  int ydirection;
  int * IRread;
};

#endif 	
