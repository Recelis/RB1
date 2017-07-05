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

int * Navigation::detectedObject() {
  int objects[5] = {0, 0, 0, 0, 0}; // used for
  int* objectPointer = objects;
  // Scale Everything to 100cm except for down
  if (rightSensor > 100) {
    rightSensor = 100;
    objects[0] = 1;
  }
  if (leftSensor > 100) {
    leftSensor = 100;
    objects[1] = 1;
  }
  if (frontSensor > 100) {
    frontSensor = 100;
    objects[2] = 1;
  }
  if (backSensor > 100) {
    backSensor = 100;
    objects[3] = 1;
  }
  if (downSensor < 13 || downSensor > 18) {
    objects[4] = 1;
  }
  return objectPointer;
}

// Serial.print("Range of Right is: ");
//    Serial.println(*(readings+1));
//    Serial.print("Range of Back is: ");
//    Serial.println(*(readings+2));
//    Serial.print("Range of Left is: ");
//    Serial.println(*(readings+3));
//    Serial.print("Range of Front is: ");
//    Serial.println(*(readings+4));
//    Serial.print("Range of Down is: ");
//    Serial.println(*(readings+5));

int* Navigation::vectorFields(int* data, int* ultrasonicReadings)
{
  
  rightSensor = *(ultrasonicReadings + 1);
  backSensor = *(ultrasonicReadings + 2);
  leftSensor = *(ultrasonicReadings + 3);
  frontSensor = *(ultrasonicReadings + 4);
  downSensor = *(ultrasonicReadings + 5);


  int * objects;
  objects = detectedObject();
  Serial.print("US Right: ");
  Serial.println(rightSensor);
  Serial.print("US Back: ");
  Serial.println(backSensor);
  Serial.print("US Left: ");
  Serial.println(leftSensor);
  Serial.print("US Front: ");
  Serial.println(frontSensor);
  Serial.print("US Down: ");
  Serial.println(downSensor);
  // Calculate direction of field0

  // calculate magnitudes of three vectors
  int v0 = leftSensor;
  int v1 = frontSensor;
  int v2 = rightSensor;

  // calculate x and y components
  vector0x = (cos(120 * PI / 180) * (v0 - 100))/100*21; // scale to 21cm 
  vector0y = sin(120 * PI / 180) * (v0 - 100);

  vector1x = 0;
  vector1y = sin(90 * PI / 360) * (v1 - 100);

  vector2x = (cos(60 * PI / 360) * (v2 - 100))/100*21; // scale to 21cm
  vector2y = sin(60 * PI / 360) * (v2 - 100);

  // original
  vorgX = *data * cos(*(data + 1) * PI / 360);
  vorgY = *data * sin(*(data + 1) * PI / 360);
  //
  xdirection = vector0x + vector1x + vector2x + vorgX;
  ydirection = 21+(vector0y + vector1y + vector2y)/272*42 + vorgY;

  int direction = atan2(ydirection, xdirection)/PI*180;
  int spin = *(data + 2);
  Serial.print("xdirection ");
  Serial.println(xdirection);
  Serial.print("ydirection ");
  Serial.println(ydirection);
  int vectoredData [3];
  vectoredData[0] = 21;
  vectoredData[1] = direction;
  vectoredData[2] = spin;


  int *returnPointer;
  returnPointer = vectoredData;

  Serial.println(*(returnPointer));
  Serial.println(*(returnPointer + 1));
  Serial.println(*(returnPointer + 2));
  return returnPointer;
}
