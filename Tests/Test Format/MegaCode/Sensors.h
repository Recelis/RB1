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
    Sensors(): ultrasonic_R(44,45),ultrasonic_B(48,49), ultrasonic_L(46,47), ultrasonic_F(40,41), ultrasonic_D(42,43){
      }
    void SensorsSetup();
    void ultrasonicCon();
    int * ultrasonicOutputs();
    int compass();
    int readVoltageLevel();  
  private:
    Ultrasonic ultrasonic_D;
    Ultrasonic ultrasonic_R;
    Ultrasonic ultrasonic_B;
    Ultrasonic ultrasonic_L;
    Ultrasonic ultrasonic_F;
    Compass onboardCompass;
    int Rightrange;
    int Backrange;
    int Leftrange;
    int Frontrange;
    int Downrange;
    int * ultraPoint;
};

#endif
