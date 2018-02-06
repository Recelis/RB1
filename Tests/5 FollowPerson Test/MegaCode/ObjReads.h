/*
 ObjReads is a library for converting the ultrasonic sensor data into object points, it uses the ObjPoint
 class to list points
*/
    
#ifndef ObjReads_h
#define ObjReads_h

#include "Arduino.h"
#include "ObjPoint.h"
#include "Sensors.h"

class ObjReads{
    public:
        ObjReads();
        ~ObjReads();
        void processData(long* ultrasonics);
    private:
        void fillPoints(long* ultrasonics);
        void screenPoints();
        void calcPerson();
        Sensors SensorData;
        ObjPoint FL;
        ObjPoint F;
        ObjPoint FR;
        ObjPoint BR;
        ObjPoint B;
        ObjPoint BL;
        ObjPoint Person;
        ObjPoint sixrants[6] {F, FR, BR, FL, BL, B};
};

#endif;
