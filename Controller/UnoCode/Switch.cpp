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
  pinMode(sw, INPUT);
  vrxRead = 500;
  vryRead = 500;
}

void Switch::readPins()
{
  vrxRead = analogRead(vrx);
  vryRead = analogRead(vry);
}

int Switch::getSpeed() {
  if ((abs(500 - vryRead) < 50) && abs(500 - vrxRead) < 50) {
    digitalWrite(led, LOW);
    return 0;
  } else {
    digitalWrite(led, HIGH);
    return 21;
  }

}

int Switch::calculateDirection() {
  double out = atan2(vryRead - 500, vrxRead - 500) * 180 / PI;
  return (int) out;
}

int Switch::readPush(){
  int button = 0;
  button = digitalRead(sw);
  return button;
}

//  Serial.println("*******************");
//  Serial.println(vrxRead - 500);
//  Serial.println(vryRead - 500);




