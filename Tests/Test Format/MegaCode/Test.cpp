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

  int* Test::ultrasonics(){
    testSensor.SensorsSetup();
    int * ultrasonicReadings;
    ultrasonicReadings = *testSensor.ultrasonicOutputs();    
    Serial.print("Range of Right is: ");
    Serial.println(*(ultrasonicReadings+1));
    Serial.print("Range of Back is: ");
    Serial.println(*(ultrasonicReadings+2));
    Serial.print("Range of Left is: ");
    Serial.println(*(ultrasonicReadings+3));
    Serial.print("Range of Front is: ");
    Serial.println(*(ultrasonicReadings+4));
    Serial.print("Range of Down is: ");
    Serial.println(*(ultrasonicReadings+5));
   return ultrasonicReadings;
  }

  void Test::compass(){
    int heading = testSensor.compass();
    Serial.print("heading is: ");
    Serial.println(heading);
  }

  int * Test::navigation(){
    // assume that computer is sending these values to RB1
    int data[3];
    data[0] = 21;
    data[1] = 90;
    data[2] = 0;
    
    int * readings;
    readings= *testSensor.ultrasonicOutputs();
    int * vdata;
    vdata = testNavigation.vectorFields(data,readings);

    Serial.println(*(vdata));
    Serial.println(*(vdata+1));
    Serial.println(*(vdata+2));
  }

//      Serial.print("Range of Right is: ");
//    Serial.println(*(readings+1));
//    Serial.print("Range of Back is: ");
//    Serial.println(*(readings+2));
//    Serial.print("Range of Left is: ");
//    Serial.println(*(readings+3));
//    Serial.print("Range of Front is: ");
//    Serial.println(*(readings+4));
//    Serial.print("Range of Down is: ");
//    Serial.println(*(readings+5));

