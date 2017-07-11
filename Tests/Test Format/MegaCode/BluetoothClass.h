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
    BluetoothClass(): bluetooth(50, 51) {};

    void setupBlue();
    char* sendReceiveData();
    bool lockSend(bool lock);
    char myBuffer[20];
    char output[20];
    bool receivedFlag;
  private:
    SoftwareSerial bluetooth;
    int index;
};

#endif
