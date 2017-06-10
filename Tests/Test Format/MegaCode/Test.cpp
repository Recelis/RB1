#include "Test.h"

// Test Kinematics
  

  Test::Test(){
    direct = 0;
  }

  int * Test::spin(){
    
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

