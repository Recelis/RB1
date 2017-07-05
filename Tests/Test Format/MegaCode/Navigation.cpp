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
}


int* Navigation::vectorFields(int* data, int* ultrasonicReadings)
{

  rightSensor = *(ultrasonicReadings + 1);
  backSensor = *(ultrasonicReadings + 2);
  leftSensor = *(ultrasonicReadings + 3);
  frontSensor = *(ultrasonicReadings + 4);
  downSensor = *(ultrasonicReadings + 5);

  int deepRight = rightSensor;
  int deepBack = backSensor;
  int deepLeft = leftSensor;
  int deepFront = frontSensor;
  int deepDown = downSensor;

  // Scale Everything to 100cm except for down
  if (deepRight > 100) {
    deepRight = 100;
  }
  if (deepBack > 100) {
    deepBack = 100;
  }
  if (deepLeft > 100) {
    deepLeft = 100;
  }
  if (deepFront > 100) {
    deepFront = 100;
  }


  // Calculate direction of field0

  // calculate magnitudes of three vectors
  int v0 = deepLeft;
  int v1 = deepFront;
  int v2 = deepRight;

  // calculate x and y components
  vector0x = (cos(120 * PI / 180) * (v0 - 100)) / 100 * 21; // scale to 21cm
  vector0y = sin(120 * PI / 180) * (v0 - 100);

  vector1x = 0;
  vector1y = sin(90 * PI / 360) * (v1 - 100);

  vector2x = (cos(60 * PI / 360) * (v2 - 100)) / 100 * 21; // scale to 21cm
  vector2y = sin(60 * PI / 360) * (v2 - 100);

  // original
  vorgX = *data * cos(*(data + 1) * PI / 180);
  vorgY = *data * sin(*(data + 1) * PI / 180);
  //

  xdirection = vector0x + vector1x + vector2x + vorgX;
  ydirection = 21 + (vector0y + vector1y + vector2y) / 272 * 42 + vorgY;

  int direction = atan2(ydirection, xdirection) / PI * 180;
  int spin = *(data + 2);
  Serial.print("xdirection ");
  Serial.println(xdirection);
  Serial.print("ydirection ");
  Serial.println(ydirection);
  int vectoredData [4];
  vectoredData[0] = 1; // placeholder value
  vectoredData[1] = 21;
  vectoredData[2] = direction;
  vectoredData[3] = spin;


  int *returnPointer;
  returnPointer = vectoredData;

  Serial.println(*(returnPointer+1));
  Serial.println(*(returnPointer + 2));
  Serial.println(*(returnPointer + 3));
  return returnPointer;
}

//  Serial.print("US Right: ");
//  Serial.println(deepRight);
//  Serial.print("US Back: ");
//  Serial.println(deepBack);
//  Serial.print("US Left: ");
//  Serial.println(deepLeft);
//  Serial.print("US Front: ");
//  Serial.println(deepFront);
//  Serial.print("US Down: ");
//  Serial.println(deepDown);


