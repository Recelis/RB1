/*
  bluetooth.cpp - Library for bluetooth
  Created by Jacky M. Lui 6 July 2017.
*/

#include "BluetoothClass.h"


void BluetoothClass::setupBlue()
{
  Serial.begin(9600);
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(1000);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  delay(1000);
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  zeroSpeed = false;
  prevSpeed = 0;
  prevDirection = 0;
}

void BluetoothClass::connectToRB1()
{
  bluetooth.print("$");
  bluetooth.print("$");
  bluetooth.print("$");
  delay(1000);
  bluetooth.println("C,000666604534");
  Serial.println("sent out connection signal");
  delay(10000);
}


void BluetoothClass::sendReceiveData(int speed, int direction)
{
  if (bluetooth.available()) // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    Serial.print((char)bluetooth.read());

    // read data to memory
  }
  if (speed == 0) {
    if (Serial.available()) // If stuff was typed in the serial monitor
    {
      // Send any characters the Serial monitor prints to the bluetooth
      bluetooth.print((char)Serial.read());
    } else {
      if (zeroSpeed == false) {
        Serial.println("   S0 D90");
        bluetooth.println("   S0 D90");
        zeroSpeed = true;
      }
    }
  } else {
    zeroSpeed = false;
    if (prevSpeed == speed && prevDirection == direction) {
      // do nothing
    } else {
      String stringSpeed = "S" + String(speed);
      String stringDirection = "D" + String(direction);
      String combined = "   " + stringSpeed + " " + stringDirection + "   ";
      Serial.println(combined);
      bluetooth.println(combined);
      prevSpeed = speed;
      prevDirection = direction;
    }
  }
  delay(500); // don't need to overload RB1
  // and loop forever and ever!
}



