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
//    Sensors(): bluetooth(11,12), ultrasonic_R(17,16),ultrasonic_B(4,3), ultrasonic_L(8,7), ultrasonic_F(15,14), ultrasonic_D(6,5){
//      }
    Sensors(): ultrasonic_R(44,45),ultrasonic_B(48,49), ultrasonic_L(46,47), ultrasonic_F(40,41), ultrasonic_D(42,43){
      }
    void SensorsSetup();
//    void BluetoothCon();
    void ultrasonicCon();
    int * ultrasonicOutputs();
//    int * IR_Beacon();
    int compass();
      
  private:
//    AltSoftSerial bluetooth;
    Ultrasonic ultrasonic_D;
    Ultrasonic ultrasonic_R;
    Ultrasonic ultrasonic_B;
    Ultrasonic ultrasonic_L;
    Ultrasonic ultrasonic_F;
    Compass onboardCompass;
    long Rightrange;
    long Backrange;
    long Leftrange;
    long Frontrange;
    long Downrange;
//    int bluetoothTx;
//    int bluetoothRx;
    int * ultrasonicReturn;
//    int slaveAddress;
//    byte headingData[2];
//    int i, headingValue;
//    int HMC6352Address = 0x42; 

//    int * IRvalues; 
};

#endif
