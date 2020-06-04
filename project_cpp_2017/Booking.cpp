#include "Booking.h"
#include "Room.h"
#include "Hotel.h"

unsigned int Booking::bookingNum=1; // ������������ ��� ������� ��������


Booking::Booking(){

	bookingID=bookingNum++;  // �� ���� ���������� ������������ Booking � ������� �������� ��������� ���� 1
}

Booking::~Booking(){
}

void Booking::roomAssignment(Room* ptrRoom){  // � ���������-������� room ��� ������ Booking ���������� �� ��� ������
                                              // ���� ����������� Room
	room=ptrRoom;                             // ��� ������� ��� ������ ���� ��� ����� ��� �������
}

//getters

int Booking::getBookingCode(){    // ���������� ��� ������ ��������
	return bookingID;
}

int Booking::getArrival(){       // ���������� ��� ����� ������
	return arrival;
}

string Booking::getClientName(){  // ��������� �� ����� ������
	return clientName;
}

int Booking::getStayDuration(){   // ���������� ��� �������� ���������
	return stayDuration;
}

int Booking::getPeople(){         // ���������� ��� ������ ��� ������ ��� �� ������� ��� �������
	return people;
}


// setters

void Booking::setArrival(int arrivalDay){ // ���������� ���� ���� ��������� ������ arrival
	arrival=arrivalDay;                   // ������ �������� � ����� ������
}
void Booking::setClientName(string clName){ // ���������� ���� ���� ��������� ������ clientName
	clientName=clName;                      // ������ �������� �� ����� ������
}
void Booking::setStayDuration(int days){    // ���������� ���� ���� ��������� ������ stayDuration
	stayDuration=days;                      // ������ �������� � �������� ���������
}
void Booking::setPeople(int visitors){      // ���������� ���� ���� ��������� ������ people
	people=visitors;                        // ������ �������� � ������� ��� ������ ��� �� ������� ��� �������
}






