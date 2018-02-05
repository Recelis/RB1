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
  Controlpanel.runCode(); 	
}

