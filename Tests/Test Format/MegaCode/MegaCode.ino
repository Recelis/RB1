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
  Controlpanel.runTests(); 	
  Controlpanel.KinematicsController();
  Controlpanel.MotorController();
}

