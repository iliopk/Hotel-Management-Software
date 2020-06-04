#include "RoomA.h"
#include "Booking.h"
#include "Hotel.h"
#include <iostream>

RoomA::RoomA(){
    int roomID=(Room::roomID);  // ������������� ��� ����� ������ ��� ������� ��������
}                               // ���� ��� ���������� ��� ������������. ������� � ������� �� ��������� ���� ���
                                // �� ���� ���������� ������������ ��� ��� ������������ ����� ����� � RoomA
                                // ����� �������� ��� Room.

// ����������(���������� �������)
double RoomA::pricing() {
	double expenseA=0.0;
	if (roomAvail[0]==NULL){   // �� � ���� '0' ��� ������ �������������� ����� �����
	  for(int x=1;x<30;x++){   // ��������� �� ������ ��� ��� ��������� ����� ��� ����
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
			 expenseA= expenseA+((roomAvail[x]->getStayDuration())*getDayPrice());
		}
      }
	}
    else {
       expenseA= (roomAvail[0]->getStayDuration())*getDayPrice(); // ����������� ������� �������� ��� ������ ���
                                                                  // �� ���� '0' ��� ������ ��������������
       for(int x=(roomAvail[0]->getStayDuration());x<30;x++){     // ����������� ��� ��� ��������� �����
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
			 expenseA= expenseA + ((roomAvail[x]->getStayDuration())*getDayPrice());
		}
       }
    }
    return expenseA;
}

void RoomA::setDayPrice(double dPrice){ // ���������� ���� ���� ��������� ������ dayPrice
    dayPrice=dPrice;                    // ������ �������� � ���� ��� �����
}

double RoomA::getDayPrice(){            // ���������� ��� ���� ��� �����
    return dayPrice;
}
