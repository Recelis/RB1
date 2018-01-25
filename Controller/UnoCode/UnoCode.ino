#include <SoftwareSerial.h>  

int bluetoothTx = 50;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 51;  // RX-I pin of bluetooth mate, Arduino D3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

#include "BluetoothClass.h"
#include "Switch.h"
BluetoothClass mybluetooth;
Switch mySwitch;
bool ON = true;
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
  int rea = mySwitch.readPush();
  if (rea){
    ON = !ON;
    mybluetooth.sendReceiveData(speed, direction, ON);
    delay(1000); // debounce button
  } else{
    mybluetooth.sendReceiveData(speed, direction, ON); 
  }
}


