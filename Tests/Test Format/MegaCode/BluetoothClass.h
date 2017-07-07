/*
  bluetooth.h - Library for bluesmirf bluetooth Module.
  Created by Jacky, Jul 6, 2017.
*/

#include <SoftwareSerial.h>
#include <string.h>
#include "Arduino.h"

#ifndef Bluetooth_h
#define Bluetooth_h


class BluetoothClass
{
  public:
    BluetoothClass():bluetooth(50,51){};

    void setupBlue();
    String sendReceiveData();
    String myBuffer;
    String output;
  private:
   SoftwareSerial bluetooth;

};

#endif
