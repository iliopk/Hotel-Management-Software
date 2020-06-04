#ifndef ROOMB_H
#define ROOMB_H
#include "RoomA.h"

class RoomB: public RoomA
{
 private:
    double dayDiscount;

 public:
       RoomB();
       ~RoomB(){}
    double pricing();
    bool bCancellation();
    void setDayDiscount(double discount);
    double getDayDiscount();
};
#endif
