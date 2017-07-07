/*
  switch.cpp - Library for bluetooth
  Created by Jacky M. Lui 6 July 2017.
*/

#include "Switch.h"


void Switch::setupPins()
{
  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);
  pinMode(led, OUTPUT);
  vrxRead = 500;
  vryRead = 500;
}

void Switch::readPins()
{
  vrxRead = analogRead(vrx);
  vryRead = analogRead(vry);
  Serial.println(1024-vrxRead);
  Serial.println(vryRead-500); 
}

int Switch::calculateDirection(){
  if ((abs(500-vryRead) < 50) && abs(500-vrxRead) < 50){
    digitalWrite(led,LOW);
    return 90;
  }
  else {
    digitalWrite(led,HIGH);
    double out = atan2(vryRead-500,1024-vrx) * 180 / PI;
    return (int) out;
  }
}





