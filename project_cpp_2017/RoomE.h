#ifndef ROOME_H
#define ROOME_H
#include "Room.h"
class RoomE: public Room {
 private:
    bool foititis;
    double dayCost;

 public:
    RoomE();
    ~RoomE(){}
   double pricing();
   void setFoititis(bool Foititis);
   void setPrice(double cost);
   bool getFoititis();
   double getPrice();
};
#endif

