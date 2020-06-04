#ifndef BOOKING_H
#define BOOKING_H
#include <string>

using namespace std;

class Room;
class Hotel;

class Booking {
 friend class Hotel;
  private:
    unsigned int bookingID;
    static unsigned int bookingNum;
	string clientName;
	int arrival;
	int stayDuration;
	int people;
    Room* room;
 public:
     Booking();
     ~Booking();
     void roomAssignment(Room* ptrRoom);

     //setters
     void setClientName(string clName);
     void setArrival(int arrivalDay);
     void setStayDuration(int days);
     void setPeople(int visitors);
     //getters
     string getClientName();
     int getArrival();
     int getStayDuration();
     int getPeople();
     int getBookingCode();



};
#endif
