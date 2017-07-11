/*
  Navigation.cpp - Class for the vector fields navigation
  Created by Jacky M. Lui 10 June 2017.
  Works within the BUDDY system
*/


#include "Navigation.h"

Navigation::Navigation() {
  vector0x = 0;
  vector0y = 0;

  vector1x = 0;
  vector1y = 0;

  vector2x = 0;
  vector2y = 0;

  vorgX = 0;
  vorgY = 0;

  xdirection = 0;
  ydirection = 0;
  notCrisis = true;
}


int* Navigation::vectorFields(int* data, int* ultrasonicReadings)
{

  double remoteSpeed = *(data+1);
  double remoteDirection = *(data+2);
  rightSensor = *(ultrasonicReadings + 2);
  backSensor = *(ultrasonicReadings + 3);
  leftSensor = *(ultrasonicReadings + 4);
  frontSensor = *(ultrasonicReadings + 5);
  downSensor = *(ultrasonicReadings + 6);

  int deepRight = rightSensor;
  int deepBack = backSensor;
  int deepLeft = leftSensor;
  int deepFront = frontSensor;
  int deepDown = downSensor;

  // Scale Everything to 50cm except for down, and include possible no reading
  if (deepRight > 50 || deepRight == 0) {
    deepRight = 50;
  }
  if (deepBack > 50 || deepBack == 0) {
    deepBack = 50;
  }
  if (deepLeft > 50 || deepLeft == 0) {
    deepLeft = 50;
  }
  if (deepFront > 50 || deepFront == 0) {
    deepFront = 50;
  }
  if (deepDown > 16){
    Serial.println("FAAAAAAAAAAAAAAAAAAAAAAAALLLLLLLLLLLLLLLLLLLIIIIIIIIIIIIIIIIIINNNNNNNNNNNNNNNNGGGGGGGGGGGGGG");
    notCrisis = false;
  } else{
    notCrisis = true;
  }
  
  Serial.print("right");
  Serial.println(deepRight);
  Serial.print("left");
  Serial.println(deepLeft);
  Serial.print("front");
  Serial.println(deepFront);
  Serial.print("DOWN");
  Serial.println(deepDown);
  // Calculate direction of field0

  // calculate magnitudes of three vectors
  int v0 = deepLeft;
  int v1 = deepFront;
  int v2 = deepRight;

  // calculate x and y components
  vector0x = (cos(120 * PI / 180) * (v0 - 50))/ 50 * 21; // scale to 21cm
  vector0y = sin(120 * PI / 180) * (v0 - 50);

  vector1x = 0;
  vector1y = sin(90 * PI / 180) * (v1 - 50);

  vector2x = (cos(60 * PI / 180) * (v2 - 50))/ 50 * 21; // scale to 21cm  
  vector2y = sin(60 * PI / 180) * (v2 - 50);

  // original
  
  vorgX = remoteSpeed * cos(remoteDirection * PI / 180);
  vorgY = remoteSpeed * sin(remoteDirection * PI / 180);
  //
  Serial.print("remotespeed");
  Serial.println(remoteSpeed);
  Serial.print("remoteDirection");
  Serial.println(remoteDirection);
  
  Serial.print("vorgX");
  Serial.println(vorgX);
  Serial.print("vorgY");
  Serial.println(vorgY);
  xdirection = vector0x + vector1x + vector2x + vorgX;
  ydirection = 21+(vector0y +vector1y+  vector2y) / 120 * 42 + vorgY; // scaled denominator slightly smaller so that remote cannot override sensor instincts
    Serial.print("xdirection ");
  Serial.println(xdirection);
  Serial.print("ydirection ");
  Serial.println(ydirection);

  String x = String(vector0x) + " " + String(vector2x);
//  Serial.println(x);
  int direction = atan2(ydirection, xdirection) / PI * 180;
  int spin = *(data + 3);

  int vectoredData [4];
  if (notCrisis){
    vectoredData[0] = 1; // placeholder value
    vectoredData[1] = *(data+1);
    vectoredData[2] = direction;
    vectoredData[3] = spin;  
  } else{
    vectoredData[0] = 1; // placeholder value
    vectoredData[1] = *(data+1);
    vectoredData[2] = -90;
    vectoredData[3] = spin;  
  }
  
//  Serial.println(*(data+1));
//  Serial.println(*(data + 2));
//  Serial.println(*(data + 3));
  int *returnPointer;
  returnPointer = vectoredData;
//  Serial.println(*(returnPointer+1));
//  Serial.println(*(returnPointer + 2));
//  Serial.println(*(returnPointer + 3));
  return returnPointer;
}




//    Serial.print("US Right: ");
//  Serial.println(deepRight);
//  Serial.print("US Back: ");
//  Serial.println(deepBack);
//  Serial.print("US Left: ");
//  Serial.println(deepLeft);
//  Serial.print("US Front: ");
//  Serial.println(deepFront);
//  Serial.print("US Down: ");
//  Serial.println(deepDown);



