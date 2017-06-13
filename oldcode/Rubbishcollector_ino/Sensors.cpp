/* 
  Sensors.cpp - Class for inputting the sensor data for RC-1.
  Created by Jacky M. Lui 27 December 2016.
  Works within the BUDDY system
*/


#include "Sensors.h"
#define IR_F 10
#define IR_R 9
#define IR_B 12
#define IR_L 11 

void Sensors::SensorsSetup()
{
  bluetoothTx = 11;
  bluetoothRx = 12;
  bluetooth.begin(115200); // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("Bluetooth is running");
  Rightrange = -1;
  Backrange = -1;
  Leftrange = -1;
  Frontrange = -1;
  Downrange = -1;
  static long UltrasonicOutputs[5];
  for (int ii = 0; ii < 5; ii++)
  {
    UltrasonicOutputs[ii] = -1;
  }
  //// Configure Pins
  pinMode(IR_F, INPUT);
  pinMode(IR_R, INPUT);
  pinMode(IR_B, INPUT);
  pinMode(IR_L, INPUT);
  // Turn on Pullup resistors
  digitalWrite(IR_F, HIGH);
  digitalWrite(IR_R, HIGH);
  digitalWrite(IR_B, HIGH);
  digitalWrite(IR_L, HIGH);

  int IRvalues[4];
  for (int ii = 0; ii < 4; ii++)
  {
    IRvalues[ii] = 1;
  }
}

int * Sensors::IR_Beacon()
{
  IRvalues[0] = digitalRead(IR_F);
  IRvalues[1] = digitalRead(IR_R);
  IRvalues[2] = digitalRead(IR_B);
  IRvalues[3] = digitalRead(IR_L);
  return IRvalues;
}

void Sensors::BluetoothCon()
{
  if(bluetooth.available()) // If the bluetooth sent any characters
  {
    //Send any characters the bluetooth prints to the serial monitor
    Serial.print((char)bluetooth.read());
    digitalWrite(13, LOW);
    Serial.print("bluetooth received");
    bluetooth.print("bluetooth received");
  }
  if(Serial.available())
  {
    // Send any characters the Serial monitor prints to the bluetooth
    bluetooth.print((char)Serial.read());
    digitalWrite(13, LOW);
    Serial.println("Serial Received");
  }
}

void Sensors::UltrasonicCon()
{
   Rightrange = ultrasonic_R.Ranging(CM);
   Backrange = ultrasonic_B.Ranging(CM);   
   Leftrange = ultrasonic_L.Ranging(CM);   
   Frontrange = ultrasonic_F.Ranging(CM);
   Downrange = ultrasonic_D.Ranging(CM);  
}

long * Sensors::UltrasonicOutputs()
{
//   Serial.print("Range of Right is: ");
//   Serial.println(Rightrange);
//   Serial.print("Range of Back is: ");
//   Serial.println(Backrange);
//   Serial.print("Range of Left is: ");
//   Serial.println(Leftrange);
//   Serial.print("Range of Front is: ");
//   Serial.println(Frontrange);
//   Serial.print("Range of Down is: ");
//   Serial.println(UltrasonicReturn[4]);
   UltrasonicReturn[0] = Rightrange;
   UltrasonicReturn[1] = Backrange;
   UltrasonicReturn[2] = Leftrange;
   UltrasonicReturn[3] = Frontrange;
   UltrasonicReturn[4] = Downrange;
   return UltrasonicReturn;
}



