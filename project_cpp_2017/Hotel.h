#ifndef HOTEL_H
#define HOTEL_H
#include <list>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
class Room;
class Booking;

class Hotel {
    friend class Room;
    friend class Booking;
	private:
	  string hotelName;
	  list<Room*> rooms;        // Λίστα με δείκτες προς αντικείμενα Room
	  list<Booking*> bookings;  // Λίστα με δείκτες προς αντικείμενα Booking
      vector<Booking*> vectorBooking; // Vector με δείκτες προς αντικείμενα Booking


	public:
		Hotel(){
		}

		~Hotel(){
		}

		void setHotelName(string hName);
		string getHotelName();
		void rAddition(Room* ptrRoom1);
		Room* roomRetrieval(int rNumber);
		Booking* bookingRetrieval(int bNumber);
		bool bookingToRoomAdd (Booking* pointerBooking, int rNumber1);
		int bookingAdd(Booking* pointerBooking1);
		bool bookingCancellation(int bNumber1);
		double profitEstimation(int roomNumber);
		double profitEstimation();
		void bookingSchedule();
		void PrintBookingInfo();
		void randomBookingCancellation();
        void PrintRoomInfo();
        void PrintIncomeInfo();

};

#endif
