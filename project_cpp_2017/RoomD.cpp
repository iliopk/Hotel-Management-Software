#include"RoomD.h"
//#include "Room.h"
#include "Booking.h"
#include "Hotel.h"
RoomD::RoomD(){
	int roomID=(Room::roomID);  // ������������� ��� ����� ������ ��� ������� ��������
}                               // ���� ��� ���������� ��� ������������. ������� � ������� �� ��������� ���� ���
                                // �� ���� ���������� ������������ ��� ��� ������������ ����� ����� � RoomD
                                // ����� �������� ��� Room.

// ��������� (���������� �������)
float RoomD::occupancy(){
	float counter=0.0;
	for (int x=0;x<=29;x++){
		if (roomAvail[x]!=NULL){
			counter++;
		}
	}
	float sum=(counter*100.0)/30.0;
	// �� � ��������� ��� �������� ����� ���������� ��� 70% ��������� ������
	if (sum>70.0){
		cout<<"Attention! In high demand!"<<endl;
	}
	return sum;
}
