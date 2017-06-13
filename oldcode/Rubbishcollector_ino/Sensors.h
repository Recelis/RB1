/*
  Sensors.h - H-File for RC1 Sensors

  Created by Jacky Lui. Jan 27, 2016.
  iteadstudio.com
*/ 



#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"
#include "Ultrasonic.h"
#include "AltSoftSerial.h"
// #include <Wire.h>
  
class Sensors 
{
  public:
    Sensors(): bluetooth(11,12), ultrasonic_R(17,16),ultrasonic_B(4,3), ultrasonic_L(8,7), ultrasonic_F(15,14), ultrasonic_D(6,5){
      }
    void SensorsSetup();
    void BluetoothCon();
    void UltrasonicCon();
    long * UltrasonicOutputs();
    int * IR_Beacon();
      
  private:
    AltSoftSerial bluetooth;
    Ultrasonic ultrasonic_D;
    Ultrasonic ultrasonic_R;
    Ultrasonic ultrasonic_B;
    Ultrasonic ultrasonic_L;
    Ultrasonic ultrasonic_F;
    long Rightrange;
    long Backrange;
    long Leftrange;
    long Frontrange;
    long Downrange;
    int bluetoothTx;
    int bluetoothRx;
    long * UltrasonicReturn;
    int slaveAddress;
    byte headingData[2];
    int i, headingValue;
    int HMC6352Address = 0x42; 

    int * IRvalues; 
};

#endif
