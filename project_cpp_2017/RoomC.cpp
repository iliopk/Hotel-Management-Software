#include "RoomC.h"
#include "Booking.h"
#include "Hotel.h"
#include <iostream>
RoomC::RoomC(){
	int roomID=(Room::roomID);  // ������������� ��� ����� ������ ��� ������� ��������
}                               // ���� ��� ���������� ��� ������������. ������� � ������� �� ��������� ���� ���
                                // �� ���� ���������� ������������ ��� ��� ������������ ����� ����� � RoomC
                                // ����� �������� ��� Room.



void RoomC::setMinPerson(int person){ // ���������� ���� ���� ��������� ������ minPerson
   minPerson=person;                  // ������ �������� � ��������� ������� ������
}

int RoomC::getMinPerson() {           // ���������� ��� �������� ������ ������
    return minPerson;
}

void RoomC::setMinDays(int days){    // ���������� ���� ���� ��������� ������ minDays
    minDays=days;                    // ������ �������� � ��������� ������� ������
}
int RoomC::getMinDays() {              // ���������� ��� �������� ������ ������
    return minDays;
}

// �������� �������� (���������� �������)
bool RoomC::bAddition(Booking* ptrBooking){
	bool flag;
	int counter=0;
	// �������� ������� ��� �� �� ��������� �� ���� ������� �� ��� �������� ������ ������ ��� ������
	// ���� ��������� �� ��� bAddition ��� Room ���� �� ����
	if (((ptrBooking->getPeople())<=getCapacity())&&((ptrBooking->getPeople())>=getMinPerson())&&((ptrBooking->getStayDuration())>=getMinDays())){
		for(int x=(ptrBooking->getArrival());x<((ptrBooking->getStayDuration())+(ptrBooking->getArrival()));x++){
			if (roomAvail[x-1]==NULL) {
				 counter++;
			}
        }
        if (counter==(ptrBooking->getStayDuration())){
             flag=true;
             for(int x=(ptrBooking->getArrival());x<((ptrBooking->getStayDuration())+(ptrBooking->getArrival()));x++){
                roomAvail[x-1]=ptrBooking;
                int c=getRoomCode();
                vector<Hotel*>::iterator it;
	            for(it=hotels.begin(); it!=hotels.end(); ++it){
                    deikths=(*it)->roomRetrieval(c);
	            }
                ptrBooking->roomAssignment(deikths);
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
