/*
  Sensors.h - H-File for RC1 Sensors

  Created by Jacky Lui. Jan 27, 2016.
  iteadstudio.com
*/ 



#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"
#include "Ultrasonic.h"
  
class Sensors 
{
  public:
    Sensors(): ultraFR(38,39),ultraF(40,41), ultraFL(42,43), ultraBR(44,45),ultraBL(46,47), ultraB(48,49){};
    ~Sensors();
    void SensorsSetup();
    long* returnUltrasonics();
  private:
    Ultrasonic ultraFR;
    Ultrasonic ultraF;
    Ultrasonic ultraFL;
    Ultrasonic ultraBR;
    Ultrasonic ultraBL;
    Ultrasonic ultraB;
    void ultrasonicCon();
    long *ultrasonicReturn = new long [6];
};

#endif

/*
  Values within ultrasonicReturn
  F -0 
  FR -1
  BR -2
  FL -3
  BF -4 
  B -5
*/
