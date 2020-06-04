#ifndef ROOMC_H
#define ROOMC_H
#include "Room.h"

class RoomC: public Room {
 private:
    int minPerson;
    int minDays;

 public:
    RoomC();
    ~RoomC(){}
    bool bAddition(Booking* ptrBooking);
    void setMinPerson(int person);
    int getMinPerson();
    void setMinDays(int days);
    int getMinDays();
};
#endif
