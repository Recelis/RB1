/*
  Ultrasonic.cpp - Library for HC-SR04 Ultrasonic Ranging Module.library

  Created by ITead studio. Apr 20, 2010.
  iteadstudio.com
*/

#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int TP, int EP)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
}

long Ultrasonic::Timing()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH);
  return duration;
}

int Ultrasonic::Ranging(int sys)
{
  Timing();
//  Serial.println("************");
//  Serial.println(duration);
  distacne_cm = (int)duration /29.4 / 2 ;
  distance_inc = duration / 74 / 2;
//  Serial.println(distacne_cm);
  if (sys)
  return distacne_cm;
  else
  return distance_inc;
}
