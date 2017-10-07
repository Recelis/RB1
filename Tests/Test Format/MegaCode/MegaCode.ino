#include <SoftwareSerial.h>
#include <ctype.h>
#include "Control.h"





Control Controlpanel;


void setup()
{
  Controlpanel.Controlsetup();
}

void loop()
{
  int on = Controlpanel.runCode(); 	
  if (on){
    Controlpanel.KinematicsController();
    Controlpanel.MotorController();
  }
}

