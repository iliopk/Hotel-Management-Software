#include <iostream>
#include <string>
#include "Room.h"
#include "Booking.h"
#include "Hotel.h"
#include "RoomA.h"
#include "RoomB.h"
#include "RoomC.h"
#include "RoomD.h"
#include "RoomE.h"
#include <stdlib.h>
#include <list>
#include "time.h"
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

char generator(){
    static const char randomStr[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    int strLength = sizeof(randomStr) - 1;
    return randomStr[rand() % strLength];
    }

int main()
{
    int times = 30;          // ����� ����� �� ����� � ���������.
    int maxCapacity = 15;    // �� ���� ��� �������� �������������.
    int dateRange = 10;      // ���� ����� ����� ����� ������� ��� �� ��� ���������� � ������ ��� ������������.
    int durationRange = 10;  // ���� ����� ����� ����� ������� ��� �� ��� ���������� � ������ ��� ������������.
    int option;              // ������� ��� �� �����������. ���������� ��� ������� ��� ������ ��� �� �����.
    string answer1;
    string ans;
    bool bookingResult;
    int arrivalDay;           // ���������� ��� ����� ������ ��� �� ����� ��� ��� ������.
    int StayDuration;         // ���������� ��� �������� ��������� ��� �� ����� ��� ��� ������.
    string pelatis;           // ���������� �� ����� ������ ��� �� ����� ��� ��� ������.
    int atoma;                // ���������� ��� ������ ������ ��� �� ������� ��� ������� ��� �� ����� ��� ��� ������.
    unsigned int RId;         // ���������� ��� ������ �������� ��� �� ����� ��� ��� ������.
    unsigned int BId;         // ���������� ��� ������ �������� ��� �� ����� ��� ��� ������.


    Hotel Afroditi1;          // ���������� ������������ ��� ������ Hotel
    Hotel* afr=&Afroditi1;    // ���������� ������ ���� �� ����������� Hotel ��� �������������

    // ���������� ������������ ��� ������ Room ��� ������� ������� ��� ����������� ����.
    // �������������� ��� ����������� ��� ���� ���� �������� ��� �������� ������� ����� ���� ���������� ������.

    Room Dwmatio1;
    Room* ptr1=&Dwmatio1;
    Dwmatio1.setCapacity(5);
    Dwmatio1.setPricePerson(10);

    Room Dwmatio2;
    Room* ptr2=&Dwmatio2;
    Dwmatio2.setCapacity(8);
    Dwmatio2.setPricePerson(20);

    RoomA DwmatioA1;
    RoomA* ptrA1=&DwmatioA1;
    DwmatioA1.setCapacity(3);
    DwmatioA1.setPricePerson(30);
    DwmatioA1.setDayPrice(32);

    RoomA DwmatioA2;
    RoomA* ptrA2=&DwmatioA2;
    DwmatioA2.setCapacity(4);
    DwmatioA2.setPricePerson(40);
    DwmatioA2.setDayPrice(40);

    RoomB DwmatioB1;
    RoomB* ptrB1=&DwmatioB1;
    DwmatioB1.setCapacity(5);
    DwmatioB1.setPricePerson(50);
    DwmatioB1.setDayDiscount(3);
    DwmatioB1.setDayPrice(40);

    RoomB DwmatioB2;
    RoomB* ptrB2=&DwmatioB2;
    DwmatioB2.setCapacity(2);
    DwmatioB2.setPricePerson(10);
    DwmatioB2.setDayDiscount(3);
    DwmatioB2.setDayPrice(40);

    RoomC DwmatioC1;
    RoomC* ptrC1=&DwmatioC1;
    DwmatioC1.setCapacity(6);
    DwmatioC1.setPricePerson(60);
    DwmatioC1.setMinPerson(1);
    DwmatioC1.setMinDays(1);

    RoomC DwmatioC2;
    RoomC* ptrC2=&DwmatioC2;
    DwmatioC2.setCapacity(7);
    DwmatioC2.setPricePerson(70);
    DwmatioC2.setMinPerson(1);
    DwmatioC2.setMinDays(1);

    RoomD DwmatioD1;
    RoomD* ptrD1=&DwmatioD1;
    DwmatioD1.setCapacity(8);
    DwmatioD1.setPricePerson(80);

    RoomD DwmatioD2;
    RoomD* ptrD2=&DwmatioD2;
    DwmatioD2.setCapacity(9);
    DwmatioD2.setPricePerson(90);

    RoomE DwmatioE1;
    RoomE* ptrE1=&DwmatioE1;
    DwmatioE1.setCapacity(10);
    DwmatioE1.setPricePerson(91);
    DwmatioE1.setPrice(92);
    DwmatioE1.setFoititis(true);

    RoomE DwmatioE2;
    RoomE* ptrE2=&DwmatioE2;
    DwmatioE2.setCapacity(11);
    DwmatioE2.setPricePerson(92);
    DwmatioE2.setPrice(92);
    DwmatioE1.setFoititis(false);

    // �� ����������� Hotel ��� ������������� ����������� ���� vector "hotels" ��� ���� �������.

    Dwmatio1.hotelAddition(afr);
    Dwmatio2.hotelAddition(afr);
    DwmatioA1.hotelAddition(afr);
    DwmatioA2.hotelAddition(afr);
    DwmatioB1.hotelAddition(afr);
    DwmatioB2.hotelAddition(afr);
    DwmatioC1.hotelAddition(afr);
    DwmatioC2.hotelAddition(afr);
    DwmatioD1.hotelAddition(afr);
    DwmatioD2.hotelAddition(afr);
    DwmatioE1.hotelAddition(afr);
    DwmatioE2.hotelAddition(afr);

    // �� ����������� ������� ������������ ��� ����� �������� ��� �����������

    Afroditi1.rAddition(ptr1);
    Afroditi1.rAddition(ptr2);
    Afroditi1.rAddition(ptrA1);
    Afroditi1.rAddition(ptrA2);
    Afroditi1.rAddition(ptrB1);
    Afroditi1.rAddition(ptrB2);
    Afroditi1.rAddition(ptrC1);
    Afroditi1.rAddition(ptrC2);
    Afroditi1.rAddition(ptrD1);
    Afroditi1.rAddition(ptrD2);
    Afroditi1.rAddition(ptrE1);
    Afroditi1.rAddition(ptrE2);

    for(int v=1;v<=times;v++){        // ������ � ���� ����������.

    string a;
    srand(time(0));                   // ��� �� ������� � rand ������������ ����� ���� ����.

    for(int y=0; y < 8; y++)
    {
        a +=generator();              // ������������� ������ string ��� �� ����� ������.
    }

    // �������� ������� ����� ���� ���������� 'imerominia', 'paramoni', 'episkeptes' ��� �� ��������������� ��������
    // ��� �� ������ ���� �� ���������� ��� ������ Booking. O� ������� ����� �������� ��� ��� ������ 1.

    int imerominia =rand() % dateRange + 1;
    int paramoni=rand() % durationRange + 1;
    int episkeptes=rand() % maxCapacity + 1;

    // ���������������� ������� ���� �� ��� ��������� �� �������� ���� ����.

    while((paramoni+imerominia)-1>30){
        int paramoni=rand() % durationRange + 1;
        int imerominia=rand() % dateRange + 1;
    }

    // ������������� ��� ������ ����������� Booking ��� ��� ���������� �������. �������� ����� ���� ����������
    // ��� ������ Booking ��� �� ����������� Booking ��� ����� �������������.

    Booking* Bpointer = new Booking() ;
    Bpointer->setClientName(a);
    Bpointer->setArrival(imerominia);
    Bpointer->setStayDuration(paramoni);
    Bpointer->setPeople(episkeptes);
    Afroditi1.bookingAdd(Bpointer);   // � ������� ����������� ��� ����� ��������� ��� �����������.

    // ���������������� ������� �������� �� ���������� 25%.

    if (rand() %100 < 25){
        Afroditi1.randomBookingCancellation();
    }

    // ����������� �� ����� �������� ���� ������.

    cout << "OPTIONS:" <<endl;
    cout << "1.  Continue With Next Loop" <<endl;
    cout << "2.  Booking Addition" <<endl;
    cout << "3.  Booking Cancellation" <<endl;
    cout << "4.  Show Booking Info" <<endl;
    cout << "5.  Show Room Info" <<endl;
    cout << "6.  Show Booking Schedule" <<endl;
    cout << "7.  Show Earnings" <<endl;
    cout << "8.  Termination" <<endl;
    cout << endl;
    cout << "Please choose one of the available options!" <<endl;
    cout << "You can choose by typing the corresponding number!" <<endl;
    cout <<endl;

    cin >> option;       // ������� ��� �� ������������. � ������� �������� ��� ��� ��� ���������� ��������� ��� �����.

    if (option==1){      // ������� ���������.
        continue;
    }
    else if (option==2){ // �������� ��������.
        cout<<"Please insert name!"<<endl;
        cin>>pelatis;
        cout<<"Please insert arrival date!"<<endl;
        cin>>arrivalDay;
        cout<<"Please insert stay duration!"<<endl;
        cin>>StayDuration;
        while(((arrivalDay+StayDuration)-1)>30){    // ������� ��� �� ��� ��������� �� �������� ���� ����
            cout<<"Your reservation cannot exceed 30 days! Please try again!"<<endl;
            cout<<"Insert arrival date!!"<<endl;
            cin>>arrivalDay;
            cout<<"Insert stay duration!"<<endl;
            cin>>StayDuration;
        }
        cout<<"Please insert visitors number!"<<endl;
        cin>>atoma;
        while (atoma>maxCapacity){                // ������� ��� �� ��� ��������� �� ���� ��� �������� �������������
        	cout<<"Too many visitors for one room!"<<endl;
        	cout<<"Insert visitors number!"<<endl;
        	cin>>atoma;
		}

        // ������������� ������� �� �� �������� ��� ���� �������������� � �������.

        Booking* pointer = new Booking() ;
        pointer->setClientName(pelatis);
        pointer->setArrival(arrivalDay);
        pointer->setStayDuration(StayDuration);
        pointer->setPeople(atoma);

        cout<<"Do you wish to book a specific room?"<<endl;
        cout<<"Please type 'yes' or 'no' for an answer!"<<endl;
        cin>>answer1;
        if (answer1=="yes"){

                // �� � ������� ����� �� ������� ������������ �������, ����� ������ ��������
                // ��� �������� � ������� �������� �������� �� �������.

                cout<<"Please insert room id!"<<endl;
                cin>>RId;
                bookingResult=Afroditi1.bookingToRoomAdd(pointer,RId);

               // �� �� ������� �� ��� ������������ ������ ��� ������� � ��� ����� ���������,
               // ������� ��� ������ � ���������� �� ���������������.

                if (bookingResult==false){
                    cout<<"It looks like room "<<RId<<" is unavailable! Do you wish to try booking a different room?"<<endl;
                    cout<<"Please type 'yes' or 'no' for an answer!"<<endl;
                    cin>>ans;
                    if(ans=="yes"){
                        cout<<"Please press enter and choose again option 2!"<<endl;
                        cout<<endl;
                    }
                    else{
                        cout<<"Bye bye"<<endl;
                    }
                }
        }
        else if (answer1=="no"){

                // �� � ������� ��� ����� �� ������� ������������ ������� �������� � ������� �������� ��������.

              Afroditi1.bookingAdd(pointer);
        }
    }
    else if (option==3){  // ������� ��������.
        cout << "Please Insert Booking ID!"<<endl;
        cin >> BId;
        Afroditi1.bookingCancellation(BId);
    }
    else if (option==4){  // ������� ���������.
        Afroditi1.PrintBookingInfo();
    }
    else if(option==5){   // ������� ��������.
        Afroditi1.PrintRoomInfo();
    }
    else if(option==6){   // ������� ������ ���������.
        Afroditi1.bookingSchedule();
        cout << endl;
    }
    else if(option==7){   // ������� ������.
        Afroditi1.PrintIncomeInfo();
    }
    else if(option==8){   // ������ ��� ��� ���������.
            break;
    }
    else {
        cout << "Wrong Choice. Try Again!"<<endl;
        cout << endl;
        continue;
    }
}                        //��������� � ���� ����������.
    return 0;
    //system("pause");
}
