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
  
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  
}

void BluetoothClass::connectToRB1()
{
  bluetooth.print("$");
  bluetooth.print("$");
  bluetooth.print("$");
  delay(100);
  bluetooth.println("C,000666604534");
  Serial.println("sent out connection signal");
  delay(1000);
}


void BluetoothClass::sendReceiveData()
{
  if (bluetooth.available()) // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    Serial.print((char)bluetooth.read());
  }
  if (Serial.available()) // If stuff was typed in the serial monitor
  {
    // Send any characters the Serial monitor prints to the bluetooth
    bluetooth.print((char)Serial.read());
  }
  // and loop forever and ever!
}



