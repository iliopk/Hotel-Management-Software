#ifndef ROOMD_H
#define ROOMD_H
#include "Room.h"
#include <iostream>

using namespace std;

class RoomD: public Room {

 public:
    RoomD();
    ~RoomD(){}
    float occupancy();
};
#endif
