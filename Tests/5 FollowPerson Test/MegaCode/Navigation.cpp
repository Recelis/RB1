/*
    Navigation CPP helps run code and 

*/
#import "Navigation.h"

Navigation::Navigation(){
    SensorData.SensorsSetup();
    KinematicsDriver.setup();
}

void Navigation::decideAction(){
    long* ultrasonicReadings = SensorData.returnUltrasonics();
    printData(ultrasonicReadings);
    Objects.processData(long* ultrasonicData);
    if (Objects.getPersonDetected() == true){
        Serialptinln("person detected");
    };
}

void Navigation::printData(long* ultrasonicReadings){
    Serial.println("*");
    Serial.println("***********************************************************************New RunCode Loop*******************************************************************");
    for (int ii =0; ii < 6; ++ii){
      String message = "Range of " + ultrasonicOrient[ii] + " is: "; // not sure why first value is printed out as two boxes
      Serial.print(message);
      Serial.println(*(ultrasonicReadings+ii));
    }
  }

  Navigation::~Navigation(){

  }