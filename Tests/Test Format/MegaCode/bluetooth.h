/*
  bluetooth.h - Library for bluesmirf bluetooth Module.
  Created by Jacky, Jul 6, 2017.
*/


#ifndef bluetooth_h
#define bluetooth_h

class bluetooth
{
  public:
    bluetooth();
    long Timing();
    long Ranging(int sys);

    private:
    int Trig_pin;
    int Echo_pin;
    long  duration,distacne_cm,distance_inc;
    
};

#endif
