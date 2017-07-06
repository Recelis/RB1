/*
  BluetoothClass.h - Library for bluesmirf bluetooth Module.
  Created by Jacky, Jul 6, 2017.
*/

#include <SoftwareSerial.h> 
#include "Arduino.h"

#ifndef Bluetooth_h
#define Bluetooth_h

class BluetoothClass
{
  public:
    BluetoothClass():bluetooth(2,3){};
    void setupBlue();
    void sendReceiveData();
    void connectToRB1();

    private:
    SoftwareSerial bluetooth;
    
};

#endif
