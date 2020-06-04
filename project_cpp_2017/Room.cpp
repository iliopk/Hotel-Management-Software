#include "Booking.h"
#include "Room.h"
#include "Hotel.h"
#include <iostream>

unsigned int Room::roomNum=1; // ������������ ������� ��������

Room::Room(){

	roomID=roomNum++;   // �� ���� ���������� ������������ Room � ������� �������� ��������� ���� 1
}

Room::~Room(){
}

//setters
void Room::setCapacity(int capacity){ // ���������� ���� ���� ��������� ������ roomCapacity
	roomCapacity=capacity;            // ������ �������� � ������������ ��� ��������
}

void Room::setPricePerson(double priceIndividual){  // ���������� ���� ���� ��������� ������ pricePerson
	pricePerson=priceIndividual;                    // ������ �������� � ���� ��� �����
}

//getters

int Room::getRoomCode(){        // ���������� ��� ������ ��������
	return roomID;
}

int Room::getCapacity(){        // ���������� ��� ������������
	return roomCapacity;
}

double Room::getPricePerson(){  // ���������� ��� ���� ��� �����
	return pricePerson;
}

// �������� ��������
bool Room::bAddition(Booking* ptrBooking){
	bool flag;
	int c;
	int counter=0;
	if ((ptrBooking->getPeople())<=getCapacity()){  // ������ ��������� �� ��������� ��� ������� ������������

		// ������� �� �� ������� ����� ��������� ��� ��� ��� �������� ��� ��������

		for(int x=(ptrBooking->getArrival());x<((ptrBooking->getStayDuration())+(ptrBooking->getArrival()));x++){
			if (roomAvail[x-1]==NULL) {
				 counter++;
			}
        }

        // �� ����� ���������

        if (counter==(ptrBooking->getStayDuration())){
             flag=true;

             // ���������� ���� ���������� ������ ��� ������ �������������� � �������

             for(int x=(ptrBooking->getArrival());x<((ptrBooking->getStayDuration())+(ptrBooking->getArrival()));x++){
                roomAvail[x-1]=ptrBooking;
                 c=getRoomCode(); // ����������� � ������� ��� �������� ��� �� ����� �������� � ������� bAddition
                vector<Hotel*>::iterator it;

                // ����������� ��� ����� ����������� ��� �� ������������ �������

	            for(it=hotels.begin(); it!=hotels.end(); ++it){
                    it=hotels.begin();               // ������ ������� ���� ��� ���������� ��� ������������ ���������.
                    deikths=(*it)->roomRetrieval(c);    // ������������ ��� ������ ��� ���������� � ������� ��������
                                                        // �������� ��� ������ ��� ������ ����������
	            }
                ptrBooking->roomAssignment(deikths);    // ��� �� ����� ��� ������ ��� ������ ������� ��� ������
                                                        // ��� ������ Booking ���� ���� �� ���������� � ���������-�������
                                                        // ��� 'room'.
             }
        }
        else{
            flag=false;
        }
	}
	else{
        flag=false;
	}

	return flag;
}

// ����������
double Room::pricing(){
	double expense=0.0;
	for(int x=0;x<30;x++){          // ��� ���� ���� ��� ������ ��������������
		if (roomAvail[x]!=NULL){    // �� ������� �������
			 expense=expense +((roomAvail[x]->getPeople())*getPricePerson());
		}
		else{
			expense=expense+0.0;
		}
	}
	return expense;
}

// ������� ��������
bool Room::bCancellation(int arithmos){

		for(int x=0;x<30;x++){          // ��� ���� ���� ��� ������ ��������������
           if (roomAvail[x]!=NULL){     // �� ������� �������
			if ((roomAvail[x]->getBookingCode())==arithmos){
				roomAvail[x]=NULL;
			}
		  }
		}
	return true;
}

// ���������
float Room::occupancy(){
	float counter=0.0;
	for (int x=0;x<=29;x++){
		if (roomAvail[x]!=NULL){  // ��������� ����� ������ ��� ������ �������������� ����� �������������
			counter++;
		}
	}
	float sum=(counter*100.0)/30.0;
	return sum;
}

// ������� ��� ��� �������� ����������� �� �������
// ������� ��� ������ ������ ���� ����������� ���������� ��� ��������� ��� ������ ��� ����� �����������
void Room::hotelAddition(Hotel* ptrHotel1){
	hotels.push_back(ptrHotel1);
}

