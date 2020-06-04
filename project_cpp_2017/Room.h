#ifndef ROOM_H
#define ROOM_H
#include <string>
#include<vector>
class Booking;
class Hotel;
using namespace std;
class Room {
  friend class Hotel;
 protected:
    unsigned int roomID;
	static unsigned int roomNum;
	Booking* roomAvail[30]= {};
	Hotel* ptrHotel;
	Room* deikths;
	vector<Hotel*>hotels; // Vector με δείκτες προς αντικείμενα Hotel
	int roomCapacity;
 private:


	double pricePerson;

 public:
        Room();
       ~Room();
       virtual bool bAddition(Booking* ptrBooking);
       virtual double pricing();
       virtual bool bCancellation(int arithmos);
       virtual float occupancy();

       //setters
       void setCapacity(int capacity);
       void setPricePerson(double priceIndividual);
       //getters
       int getCapacity();
       double getPricePerson();
       int getRoomCode();     // επιστρέφει τον κωδικό δωματίου


       void hotelAddition(Hotel* ptrHotel1);
};
#endif
