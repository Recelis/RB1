#include "Test.h"

// Test Kinematics


Test::Test() {
  count = 0;
  direct = 0;
}

int * Test::spin() {
  static int data[3];
  if (count < 50) {
    data[0] = 0;
    data[1] = 0;
    data[2] = 135;
  } else {
    data[0] = 0;
    data[1] = 0;
    data[2] = -135;
    if (count > 100) count = 0;
  }
  count++;
  Serial.println(data[2]);
  return data;
}

int * Test::forwardAndBackward() {
  static int data[4];
  if (count < 50) {
    data[0] = 0;
    data[1] = 21;
    data[2] = 90;
    data[3] = 0;
  } else {
    data[0] = 0;
    data[1] = 21;
    data[2] = 270;
    data[3] = 0;
    if (count > 100) count = 0;
  }
  count++;
  Serial.println(data[2]);
  delay(100);
  return data;
}

int * Test::kinematics() {
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

int* Test::ultrasonics() {
  testSensor.SensorsSetup();
  int * ultrasonicReadings;
  ultrasonicReadings = *testSensor.ultrasonicOutputs();
  return ultrasonicReadings;
}

int Test::compass() {
  int heading = testSensor.compass();
  Serial.print("heading is: ");
  Serial.println(heading);
  return heading;
}

int * Test::navigation(int * commandValues) {
  // assume that computer is sending these values to RB1
  int data[4];
    data[0] = *(commandValues);
    data[1] = *(commandValues + 1);
    data[2] = *(commandValues + 2);
    data[3] = *(commandValues + 3);
    Serial.print("data[2]:");
    Serial.println(data[2]);
    int * pointerToData;
    pointerToData = data;
//  data[1] = 21;
//  data[2] = 90;
//  data[3] = 0;
  int * readings;
  readings = *testSensor.ultrasonicOutputs();

  int * vdata;
  vdata = testNavigation.vectorFields(pointerToData, readings);

  return vdata;
}

// Serial Prints

//  Serial.print("Range of Right is: ");
//  Serial.println(*(ultrasonicReadings + 1));
//  Serial.print("Range of Back is: ");
//  Serial.println(*(ultrasonicReadings + 2));
//  Serial.print("Range of Left is: ");
//  Serial.println(*(ultrasonicReadings + 3));
//  Serial.print("Range of Front is: ");
//  Serial.println(*(ultrasonicReadings + 4));
//  Serial.print("Range of Down is: ");
//  Serial.println(*(ultrasonicReadings + 5));

//    Serial.print("Range of Right is: ");
//  Serial.println(*(readings + 2));
//  Serial.print("Range of Back is: ");
//  Serial.println(*(readings + 3));
//  Serial.print("Range of Left is: ");
//  Serial.println(*(readings + 4));
//  Serial.print("Range of Front is: ");
//  Serial.println(*(readings + 5));
//  Serial.print("Range of Down is: ");
//  Serial.println(*(readings + 6));


//  Serial.println(*(vdata));
//  Serial.println(*(vdata+1));
//  Serial.println(*(vdata + 2));
//  Serial.println(*(vdata + 3));



