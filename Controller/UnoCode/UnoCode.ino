/*
  Example Bluetooth Serial Passthrough Sketch
  by: Jim Lindblom
  SparkFun Electronics
  date: February 26, 2013
  license: Public domain
  This example sketch converts an RN-42 bluetooth module to
  communicate at 9600 bps (from 115200), and passes any serial
  data between Serial Monitor and bluetooth module.
*/
#include "BluetoothClass.h"
#include "Switch.h"
BluetoothClass mybluetooth;
Switch mySwitch;

void setup()
{
  mySwitch.setupPins();
  mybluetooth.setupBlue();
  mybluetooth.connectToRB1();
  
}

void loop(){
  mySwitch.readPins();
  int speed = mySwitch.getSpeed();
  int direction = mySwitch.calculateDirection();
  mybluetooth.sendReceiveData(speed, direction);
}


