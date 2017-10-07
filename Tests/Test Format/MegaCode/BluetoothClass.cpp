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
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  Serial.println("setup");
  index = 0;
  receivedFlag = false;
}

bool BluetoothClass::lockSend(bool locked){
  if (locked) {
    bluetooth.print('L');
//    Serial.println("Locked");
    return true;
  }
  else {
    bluetooth.print('O');
//    Serial.println("Open");
    return false;
  }
}

char* BluetoothClass::sendReceiveData()
{
  if (Serial.available()) // If stuff was typed in the serial monitor, which wouldn't happen
  {
    // Send any characters the Serial monitor prints to the bluetooth
    bluetooth.print((char)Serial.read());

  }
  if (bluetooth.available()) // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    char inputChar = (char)bluetooth.read();
    Serial.print(inputChar);

    myBuffer[index] = inputChar;
    index++;
    if (inputChar == '\n') {
      strncpy(output, myBuffer, 20);
      index = 0;
      for (int ii = 0; ii < 20; ii++) {
        myBuffer[ii] = "";
        //        Serial.print(output[ii]);
        receivedFlag = true; // set flag true so that only when full signal sent through, runs others
      }
    } else {
      receivedFlag = false;
      for (int ii = 0; ii < 20; ii++) {
        output[ii] = "";
      }
    }
  } else {
    receivedFlag = false;
  }

  char* point;
  point = output;
  return point;
  // and loop forever and ever!
}

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


//int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
//int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3
//
//SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
//
//void setup()
//{
//  Serial.begin(9600);  // Begin the serial monitor at 9600bps
//
//  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
//  bluetooth.print("$");  // Print three times individually
//  bluetooth.print("$");
//  bluetooth.print("$");  // Enter command mode
//  delay(100);  // Short delay, wait for the Mate to send back CMD
//  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
//  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
//  bluetooth.begin(9600);  // Start bluetooth serial at 9600
//}
//
//void loop()
//{
//
//}

