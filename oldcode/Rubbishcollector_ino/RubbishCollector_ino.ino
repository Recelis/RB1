/* 
	RubbishCollector_ino.ino - Code for running Freetronics Eleven
	Created by Jacky M. Lui 7 November 2015
	Workes within the BUDDY system
*/

#include "AltSoftSerial.h"
#include "UnoControl.h"

UnoControl UnoControlpanel;


void setup()
{
  // bluetooth.print("$");
  // bluetooth.print("$");
  // bluetooth.print("$"); // Enter command mode
  UnoControlpanel.UnoControlsetup();
  UnoControlpanel.Light(1);
  delay(100); // short delay, wait for the Mate to send back CMD
  delay(100); // short delay, wait for the Mate to send back CMD
//   bluetooth.print("U,9600,N"); // Temporarily change the baudrate to 9600, no parity
//   bluetooth.begin(9600); //Start bluetooth serial at 9600
}

void loop()
{
  UnoControlpanel.Interface();
}

