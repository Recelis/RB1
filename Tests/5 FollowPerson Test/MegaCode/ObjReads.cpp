/*
    ObjReads.cpp - Jacky Lui
    Converts ultrasonic readings into actual object point data
*/

#include "ObjReads.h"
#define PI 3.14159265
#define DETECTEDPERSON 1 

ObjReads::ObjReads(){
    pinMode(13, OUTPUT);
    PersonX = -1;
    PersonY = -1;

}

void ObjReads::processData(long* ultrasonicData){
    fillPoints(ultrasonicData);
    splitPersonIntoXY();
    for (int ii =0; ii < 6; ii++){
        screenPoints(ii);
        int detected = calcPerson(ii);
        if (detected == DETECTEDPERSON) break;
        updatePerson(ii);
    }
    defaultDiff[0] = DEFAULTDIFFMAG;
    defaultDiff[1] = DEFAULTDIFFANG; // set back to default
}

void ObjReads::splitPersonIntoXY(){
    if (Person.get()[0] == -1 || Person.get()[1] == -1) {
        
    }   else{
        double magnitude = Person.get()[0];
        double angle = Person.get()[1] *PI/180; // convert to radians for trig operations
        // convert to horizontal and vertical components of ultrasonic
        double PersonY = sin(angle)*magnitude;
        double PersonX = cos(angle)*magnitude;
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
    sixrants[2].set(ultrasonicData[2],225);
    sixrants[3].set(ultrasonicData[3],45);
    sixrants[4].set(ultrasonicData[4],315);
    sixrants[5].set(ultrasonicData[5],270);
}

int ObjReads::calcPerson(int ii){
    if (sixrants[ii].get()[0] <= 4 && sixrants[ii].get()[0] >= 2){
        if (personDetected == false){
        
        // ignore 0, because that might be an error in ultrasonic sensors. 
            Person.set(sixrants[ii].get()[0], sixrants[ii].get()[0]); 
            digitalWrite(13, HIGH);
            personDetected = true;
            return DETECTEDPERSON;
        } else{
            digitalWrite(13, LOW);
            personDetected = false;
            Person.set(-1,-1);
        }
    }
    return 0;   
}

void ObjReads::updatePerson(int ii){
    if (personDetected == true){
        // calculate vector difference 
        double magnitude = sixrants[ii].get()[0];
        double angle = sixrants[ii].get()[1] *PI/180; // convert to radians for trig operations
        // convert to horizontal and vertical components of ultrasonic
        double yUltra = sin(angle)*magnitude;
        double xUltra = cos(angle)*magnitude;
        // diff against Person
        double xDiff = PersonX - xUltra;
        double yDiff = PersonY - yUltra;
        // convert back to polar coordinates
        double diffMag = abs(sqrt(yDiff*yDiff + xDiff*xDiff));
        double diffAngle = abs(atan2(yDiff,xDiff)) *180/PI;
        Serial.print("diffMag: ");
        Serial.println(diffMag);
        Serial.print("diffAngle: ");
        Serial.println(diffAngle);
        // set new defaults
        if (diffAngle < defaultDiff[1]){
            if (diffMag < defaultDiff[0]){
                defaultDiff[0] = diffMag;
                defaultDiff[1] = diffAngle; 
                // set Person to new angle
                Person.set(magnitude, angle*180/PI);
            } 
        }
    }
}

ObjReads::~ObjReads(){

}
