/*
 ObjPoint is a class for manipulating distance, direction data
*/

#ifndef ObjPoint_h
#define ObjPoint_h

class ObjPoint{
    public:
        ObjPoint();
        ~ObjPoint();
        void set(double dist, double direct);
        double* get() const; 
    private:
        double distance;
        double direction;
        double* retPtr = new double[2];
};

#endif;