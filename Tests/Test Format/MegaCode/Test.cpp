#include "Test.h"

// Test Kinematics
  

  Test::Test(){
    count = 0;
    direct = 0;
  }

  int * Test::spin(){
    int data[3];
    if (count < 50){
      data[0] = 0;
      data[1] = 0;
      data[2] = 135; 
    } else{
      data[0] = 0;
      data[1] = 0;
      data[2] = -135; 
      if (count > 100) count = 0;
    }
    count++;
    Serial.println(data[2]);
    return data;
  }

  int * Test::forwardAndBackward(){
     int data[3];
    if (count < 50){
      data[0] = 21;
      data[1] = 90;
      data[2] = 0; 
    } else{
      data[0] = 21;
      data[1] = 270;
      data[2] = 0; 
      if (count > 100) count = 0;
    }
    count++;
    Serial.println(data[2]);
    return data;
  }

  int * Test::kinematics(){
    int data[3];
    delay(5000);
    direct += 90;
    if (direct >= 360) direct = 0;
    data[0] = 21;
    data[1] = direct;
    data[2] = 0;
    Serial.print("direction ");
    Serial.println(direct);
    return data;
  }

