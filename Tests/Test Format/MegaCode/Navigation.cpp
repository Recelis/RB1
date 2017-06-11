/* 
  Navigation.cpp - Class for the vector fields navigation
  Created by Jacky M. Lui 10 June 2017.
  Works within the BUDDY system
*/


#include "Navigation.h"

Navigation::Navigation(){
  
}

int * Navigation::detectedObject(){
  int objects[5] = {0,0,0,0,0}; // used for 
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
  return objects;
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

int* Navigation::vectorFields(int* data,int* ultrasonicReadings)
{  
    int * vectoredData;
    rightSensor = *(ultrasonicReadings+1);
    backSensor = *(ultrasonicReadings+2);
    leftSensor = *(ultrasonicReadings+3);
    frontSensor = *(ultrasonicReadings+4);
    downSensor = *(ultrasonicReadings+5);
    
    int * objects;
    objects = detectedObject();
    // Calculate direction of field
    xdirection = rightSensor - leftSensor;
    ydirection = frontSensor - backSensor;



    vectoredData = data;
    return vectoredData;
    // Implement Vector Fields
//    prevrobspeed = robspeed;
//    prevrobdirection = robdirection;
//    prevrobspin = robspin;  
//  
//  // Vector Fields values
//  
//      
//
//      Serial.print("US Right: ");
//      Serial.println(Rightsensor);
//      Serial.print("US Back: ");
//      Serial.println(Backsensor);
//      Serial.print("US Left: ");
//      Serial.println(Leftsensor);
//      Serial.print("US Front: ");
//      Serial.println(Frontsensor);
//      Serial.print("US Down: ");
//      Serial.println(Downsensor);  
//
//
//      // Convert this into an angle, make sure atan2 does not equal infinity
//      if (xdirection == 0)
//      {
//        if (ydirection > 0) robdirection = 180;
//        if (ydirection < 0) robdirection = -180;
//        else robdirection = prevrobdirection;
//      }
//      else
//      {
//        robdirection = atan2((double)ydirection,(double)xdirection); 
//
// 
//        //Convert to degrees
//        robdirection = robdirection * 180/PI;
//        Serial.print("    robirection now ");
//        Serial.println(robdirection); 
//        int bufferdirection = robdirection; // used so that robdirection won't be confused in if statements.
//        // Convert to Angular Space of Robot
//        if (bufferdirection < 90 && bufferdirection >= 0) robdirection = 90-robdirection; 
//        if (bufferdirection <= 180 && bufferdirection >= 90) robdirection = 360 - (robdirection - 90);
//        if (bufferdirection < 0 && bufferdirection >= -180) robdirection = -robdirection + 90;
//        
//        if (robdirection == 360) robdirection = 0;
//      }
//        robspeed = 21;
//      robspin = (int)robdirection;
//      
//    Serial.print("Speed: ");
//    Serial.print(robspeed);
//    Serial.print(" Direction: ");
//    Serial.print(robdirection);
//    SerialTransEleven.println("hello is it me you're looking for?");
//    SerialTransEleven.println(robdirection);
//    Serial.print(" Spin: ");
//    Serial.println(robspin);
  }
