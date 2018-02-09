/*
 ObjReads is a library for converting the ultrasonic sensor data into object points, it uses the ObjPoint
 class to list points
*/
    
#ifndef ObjReads_h
#define ObjReads_h

#define DEFAULTDIFFMAG 30
#define DEFAULTDIFFANG 90

#include "Arduino.h"
#include "ObjPoint.h"
#include "Sensors.h"
#include "math.h"

class ObjReads{
    public:
        ObjReads();
        ~ObjReads();
        void processData(long* ultrasonics);
    private:
        void splitPersonIntoXY();
        void fillPoints(long* ultrasonics);
        void screenPoints(int ii);
        int calcPerson(int ii);
        void updatePerson(int ii);
        Sensors SensorData;
        ObjPoint FL;
        ObjPoint F;
        ObjPoint FR;
        ObjPoint BR;
        ObjPoint B;
        ObjPoint BL;
        ObjPoint Person;
        double PersonX;
        double PersonY;
        ObjPoint sixrants[6] {F, FR, BR, FL, BL, B};
        bool personDetected = false;
        double defaultDiff[2] = {DEFAULTDIFFMAG,DEFAULTDIFFANG};
};

#endif;
