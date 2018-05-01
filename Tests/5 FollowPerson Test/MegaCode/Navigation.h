#ifndef Navigation_h
#define Navigation_h

#import "arduino.h"
#include "ObjReads.h"
#include "Kinematics.h"

class Navigation{
    public:
        Navigation();
        ~Navigation();
    private:
        void decideAction();
        void printData(long * ultrasonicReadings); 
        Sensors SensorData;
        ObjReads Objects;
        Kinematics KinematicsDriver;
        String ultrasonicOrient[6] {"F", "FR", "BR", "FL", "BL", "B"};
};

#endif 