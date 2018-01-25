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
    void sendReceiveData(int speed, int direction, bool ON);
    void connectToRB1();

    private:
    SoftwareSerial bluetooth;
    bool zeroSpeed;
    int prevSpeed;
    int prevDirection;
<<<<<<< HEAD
    int onState;
=======
    bool locked;
>>>>>>> 0d669668dd6ca6aa6fc81f4a3a4f77e1f4783375
};

#endif
