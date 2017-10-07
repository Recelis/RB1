/*
  Sensors.h - H-File for RC1 Sensors

  Created by Jacky Lui. Jan 27, 2016.
  iteadstudio.com
*/ 



#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"
#include "Ultrasonic.h"
#include "compass.h"
  
class Sensors 
{
  public:
    Sensors(): ultrasonic_R(44,45),ultrasonic_MR(48,49), ultrasonic_L(46,47), ultrasonic_F(40,41), ultrasonic_ML(42,43){
      }
    void SensorsSetup();
    void ultrasonicCon();
    int * ultrasonicOutputs();
    int compass();
    int readVoltageLevel();  
  private:
    Ultrasonic ultrasonic_ML;
    Ultrasonic ultrasonic_R;
    Ultrasonic ultrasonic_MR;
    Ultrasonic ultrasonic_L;
    Ultrasonic ultrasonic_F;
    Compass onboardCompass;
    int Rightrange;
    int middleRightrange;
    int Leftrange;
    int Frontrange;
    int middleLeftrange;
    int * ultraPoint;
};

#endif
