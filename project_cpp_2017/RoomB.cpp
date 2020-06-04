#include "RoomB.h"
#include "RoomA.h"
#include "Booking.h"
#include "Hotel.h"
#include <iostream>


RoomB::RoomB(){
    int roomID=(Room::roomID);  // ������������� ��� ����� ������ ��� ������� ��������
}                               // ���� ��� ���������� ��� ������������. ������� � ������� �� ��������� ���� ���
                                // �� ���� ���������� ������������ ��� ��� ������������ ����� ����� � Room�
                                // ����� �������� ��� Room�.



void RoomB::setDayDiscount(double discount){ // ���������� ���� ���� ��������� ������ dayDiscount
     dayDiscount=discount;                   // ������ �������� � ������� ��� �����
}

double RoomB::getDayDiscount(){              // ���������� ��� ������� ��� �����
     return dayDiscount;
}

//���������� (��������� �������)
double RoomB::pricing() {
   double finalPrice;
    int counter=0;
   for (int i=0;i<30;i++){
     if (roomAvail[i]==NULL){
        counter++;
     }
   }
   if (counter==30){ // �� ��� ������� ��� ������� ����� �������
     finalPrice=0.0;
   }
   else{
   finalPrice=getDayPrice();
   if (roomAvail[0]==NULL){     // �� � ���� '0' ��� ������ �������������� ����� ����
	  for(int x=1;x<30;x++){    // ��� ���� ���� ��� ������ ��������������
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
			 double expenseB=getDayPrice(); // ������ ���� ��� �����
			 for (int j=1;j<(roomAvail[x]->getStayDuration());j++){
			     expenseB=expenseB-getDayDiscount(); // ���� ��� ����� ���� ��� �������
                if (expenseB>(getDayPrice()/2.0)){   // �� � ���� ��� ����� ���� ��� ������� ��� ����� ���������
                                                     // ��� �� ���� ��� ������� ����� ��� �����
                    finalPrice=finalPrice+expenseB;
                }
                else{
                    finalPrice=finalPrice+(getDayPrice()/2.0);
                }
			 }
		}
      }
	}
    else { // ���������� �� ��� ������ ����������� ���� ����� RoomA
       double expenseB=getDayPrice();
       for (int j=1;j<(roomAvail[0]->getStayDuration());j++){
			     expenseB=expenseB-getDayDiscount();
                if (expenseB>(getDayPrice()/2.0)){
                    finalPrice=finalPrice+expenseB;
                }
                else{
                    finalPrice=finalPrice+(getDayPrice()/2.0);
                }
       }
       for(int x=(roomAvail[0]->getStayDuration());x<30;x++){
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
             double expenseB=getDayPrice();
			 for (int j=1;j<(roomAvail[x]->getStayDuration());j++){
			     expenseB=expenseB-getDayDiscount();
                if (expenseB>(getDayPrice()/2.0)){
                    finalPrice=finalPrice+expenseB;
                }
                else{
                    finalPrice=finalPrice+(getDayPrice()/2.0);
                }
		}
       }
    }
}
}
return finalPrice;
}

//������� �������� (���������� �������)
bool RoomB::bCancellation(){

	return false;
}
