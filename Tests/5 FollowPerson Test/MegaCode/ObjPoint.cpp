/*
 ObjPoint.cpp - Jacky Lui
 

*/

#include "ObjPoint.h"

ObjPoint::ObjPoint(){

}

void ObjPoint::set(double dist, double direct){
    distance = dist;
    direction = direct;
}

double* ObjPoint::get() const{
    retPtr[0] = distance;
    retPtr[1] = direction;
    return retPtr;
}

ObjPoint::~ObjPoint(){
    delete retPtr;
    retPtr = nullptr;
}