/*
    ObjReads.cpp - Jacky Lui
    Converts ultrasonic readings into actual object point data
*/

#include "ObjReads.h"

ObjReads::ObjReads(){
    pinMode(13, OUTPUT);
}

void ObjReads::processData(long* ultrasonicData){
    fillPoints(ultrasonicData);
    for (int ii =0; ii < 6; ii++){
        screenPoints(ii);
        calcPerson(ii);
    }
}

void ObjReads::screenPoints(int ii){
        if (sixrants[ii].get()[0] > 100){
            sixrants[ii].set(0,0);
        }
        Serial.println(sixrants[ii].get()[1]);
}

void ObjReads::fillPoints(long* ultrasonicData){
    sixrants[0].set(ultrasonicData[0],90);
    sixrants[1].set(ultrasonicData[1],135);
    sixrants[2].set(ultrasonicData[2],180);
    sixrants[3].set(ultrasonicData[3],45);
    sixrants[4].set(ultrasonicData[4],325);
    sixrants[5].set(ultrasonicData[5],270);
}

void ObjReads::calcPerson(int ii){
    if (sixrants[ii].get()[0] <= 4 && sixrants[ii].get()[0] >= 2){
        if (personDetected == false){
        
        // ignore 0, because that might be an error in ultrasonic sensors. 
            Person.set(sixrants[ii].get()[0], sixrants[ii].get()[0]); 
            digitalWrite(13, HIGH);
            personDetected = true;
        } else{
            digitalWrite(13, LOW);
            personDetected = false;
        }
    }   
}

ObjReads::~ObjReads(){

}
