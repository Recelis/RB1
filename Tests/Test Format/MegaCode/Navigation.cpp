/*
  Navigation.cpp - Class for the vector fields navigation
  Created by Jacky M. Lui 10 June 2017.
  
  downSensor is now middleLeftSensor
  backSensor is now middleRightSensor
  
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
  rightSensor = *(ultrasonicReadings + 0);
  middleRightSensor = *(ultrasonicReadings + 1);
  leftSensor = *(ultrasonicReadings + 2);
  frontSensor = *(ultrasonicReadings + 3);
  middleLeftSensor = *(ultrasonicReadings + 4);

  int deepRight = rightSensor;
  int middleRight = middleRightSensor;
  int deepLeft = leftSensor;
  int deepFront = frontSensor;
  int middleLeft = middleLeftSensor;

  // Scale Everything to 50cm except for down, and include possible no reading
  if (deepRight > 50 || deepRight <= 0) {
    deepRight = 50;
  }
  if (middleRight > 50 || middleRight <= 0) {
    middleRight = 50;
  }
  if (deepLeft > 50 || deepLeft <= 0) {
    deepLeft = 50;
  }
  if (deepFront > 50 || deepFront <= 0) {
    deepFront = 50;
  }
  if (middleLeft > 50 || middleLeft <= 0){
    middleLeft = 50;
  }
  

  Serial.print("right");
  Serial.println(deepRight);
  Serial.print("middleRight");
  Serial.println(middleRight);
  Serial.print("front");
  Serial.println(deepFront);
  Serial.print("middleLeft");
  Serial.println(middleLeft);
  Serial.print("left");
  Serial.println(deepLeft);
  // Calculate direction of field0

  // calculate magnitudes of three vectors
  int v0 = deepLeft;
  int v1 = middleLeft;
  int v2 = deepFront;
  int v3 = middleRight;
  int v4 = deepRight;

  // calculate x and y components
  vector0x = (cos(150 * PI / 180) * (v0 - 50))/ 50 * 21; // scale to 21cm
  vector0y = sin(150 * PI / 180) * (v0 - 50);

  vector1x = (cos(120 * PI / 180) * (v0 - 50))/ 50 * 21; // scale to 21cm
  vector1y = sin(120 * PI / 180) * (v0 - 50);

  vector2x = 0;
  vector2y = sin(90 * PI / 180) * (v1 - 50);

  vector3x = (cos(60 * PI / 180) * (v2 - 50))/ 50 * 21; // scale to 21cm  
  vector3y = sin(60 * PI / 180) * (v2 - 50);
  
  vector4x = (cos(30 * PI / 180) * (v2 - 50))/ 50 * 21; // scale to 21cm  
  vector4y = sin(30 * PI / 180) * (v2 - 50);

  // original
  
  vorgX = remoteSpeed * cos(remoteDirection * PI / 180);
  vorgY = remoteSpeed * sin(remoteDirection * PI / 180);
  //
  Serial.print("remotespeed");
  Serial.println(remoteSpeed);
  Serial.print("remoteDirection");
  Serial.println(remoteDirection);
//  
//  Serial.print("vorgX");
//  Serial.println(vorgX);
//  Serial.print("vorgY");
//  Serial.println(vorgY);
  xdirection = vector0x + vector1x + vector2x + vector3x + vector4x +vorgX;
  ydirection = 21+(vector0y +vector1y+  vector2y + vector3y) / 120 *42 + vorgY; // scaled denominator slightly smaller so that remote cannot override sensor instincts
//    Serial.print("xdirection ");
//  Serial.println(xdirection);
//  Serial.print("ydirection ");
//  Serial.println(ydirection);

  String x = String(vector0x) + " " + String(vector2x);
  Serial.println(x);
  int direction = atan2(ydirection, xdirection) / PI * 180;

  int vectoredData [4];
  if (notCrisis){
    vectoredData[0] = 1; // placeholder value
    vectoredData[1] = *(data+1);
    vectoredData[2] = direction;
    vectoredData[3] = -direction;  
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



