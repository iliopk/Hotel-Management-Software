#ifndef ROOMA_H
#define ROOMA_H
#include "Room.h"
class RoomA: public Room
{
 protected:
    double dayPrice;

 public:
       RoomA();
       ~RoomA(){}
    double pricing();
    void setDayPrice(double dPrice);
    double getDayPrice();
};
#endif
