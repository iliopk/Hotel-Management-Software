#include "RoomE.h"
#include "Booking.h"
#include "Hotel.h"

RoomE::RoomE(){
	int roomID=(Room::roomID); // ������������� ��� ����� ������ ��� ������� ��������
}                               // ���� ��� ���������� ��� ������������. ������� � ������� �� ��������� ���� ���
                                // �� ���� ���������� ������������ ��� ��� ������������ ����� ����� � RoomE
                                // ����� �������� ��� Room.


void RoomE::setFoititis(bool Foititis){ // ���������� ���� ���� ��������� ������ foititis
    foititis=Foititis;                  // ������ �������� �� � ������� ����� �������� � ���
}
void RoomE::setPrice(double cost){      // ���������� ���� ���� ��������� ������ dayCost
    dayCost=cost;                       // ������ �������� � ���� ��� �����
}
bool RoomE::getFoititis(){              // ������������ � ���� ��� ���������� foititis
    return foititis;
}
double RoomE::getPrice(){                // ������������ � ���� ��� �����
    return dayCost;
}

//���������� (���������� �������)
double RoomE::pricing() {
   double expenseE=0.0;
	if (roomAvail[0]==NULL){
	  for(int x=1;x<30;x++){
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
           for (int j=1;j<(roomAvail[x]->getStayDuration());j++){
             if ((getFoititis())==true){                      // �� � ������� ����� ��������
                     expenseE=expenseE + getPrice()*0.5;      // ���� 50% ������� ��� �����
		    }
		    else {
                 expenseE= expenseE+ getPrice();              // ����������� �� ������ ������������ ���� �����
                 }                                            // ��� ����� ��� �����
           }
       }
	 }
	}
    else {
       for (int j=1;j<(roomAvail[0]->getStayDuration());j++){
        if ((getFoititis())==true){
                     expenseE=expenseE + getPrice()*0.5;
        }
        else {
                 expenseE= expenseE+ getPrice();
        }
       }
       for(int x=(roomAvail[0]->getStayDuration());x<30;x++){
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
			if ((getFoititis())==true){
                     expenseE=expenseE + getPrice()*0.5;
            }
            else {
                 expenseE= expenseE+ getPrice();
            }
		}
       }
   }



 return expenseE;
}
