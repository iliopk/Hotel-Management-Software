#include "Hotel.h"
#include "Room.h"
#include "Booking.h"
#include <iostream>
#include <iomanip> // ��� �� setw. �������� �� ������� ��� ������ ��� �� ���������� �� ������������.

using namespace std;


void Hotel::setHotelName(string hName){
	hotelName=hName;  // �������� ���� ���� ��������� ������ hotelName, ���� �������� �� ����� �����������.
}


string Hotel::getHotelName(){
	return hotelName; // ���������� ��� ���� ��� hotelName.
}

// �������� ��������
// �������� �� ������ ������ ���� ����������� Room.
void Hotel::rAddition(Room* ptrRoom1){
	rooms.push_back(ptrRoom1); // � ������� ����������� ���� ����� rooms.
}

// �������� �������� ��� ������
Room* Hotel::roomRetrieval(int rNumber){
	list<Room*>::iterator it;
    bool flag=false;
    int temp;
	for(it=rooms.begin(); it!=rooms.end(); ++it){ // ��������� �� ����� rooms
        temp=(*it)->getRoomCode();   // �� ���� ��������� ���������� ��� ������ ��������.
		if (rNumber==temp){          // ������� �� ������� ������� �������� ������� �� �� ������ ��� ������ ���� ������.
			flag=true;               // �� ������� ��������� � ��������� ������� ��� � ������� ���������� ������ ���� ��
            break;                   // ����������� ������� ��� ������ � ������� ������� �� �� ������.
		}
		else{
			continue;
		}
	}
	if (flag==true){
        return *it;
	}
	else{
        return NULL;               // ����������� ���� ���������� �������� � �����, � ������� ��������� ������������� NULL.
	}
}

// �������� �������� ��� ������
// ���� ���������� �� ��� ������ '�������� �������� ��� ������'.
// ��� ����������� � ����� bookings.
Booking* Hotel::bookingRetrieval(int bNumber){
	list<Booking*>::iterator iter;
    bool flag=false;
    int temp;
	for(iter=bookings.begin(); iter!=bookings.end(); ++iter){
		temp=(*iter)->getBookingCode();
		if (temp==bNumber){
            flag=true;
            break;
		}
		else{
			continue;
		}
	}
	if (flag==true){
        return *iter;
	}
	else{
        return NULL;
	}
}

// �������� �������� �� �������
bool Hotel::bookingToRoomAdd (Booking* pointerBooking, int rNumber1){
    Room* myptr=roomRetrieval(rNumber1); // �������� � �������� �������� ��� ������ ��� �� ���������� ��� ������������
    bool result;                         // ���� ������ myptr.
    if (myptr!=NULL){                    // �� ������� ������� �� ������ rNumber1
        bool myflag = (myptr->bAddition(pointerBooking)); // �������� � �������� �������� ��� ������ �������
        if (myflag==true){                                // �� ���� �������� � �������� ��������,
            bookings.push_back(pointerBooking);           // � ������� ����������� ��� ��� ����� bookings
            result=true;                                  // ��� � ������� ���������� true.
            cout << "successfull addition!" << endl;
        }
        else{
            cout << "addition was unsuccessfull"<<endl;
            result=false;
        }
    }
    else {
        cout<<endl;
        cout << "Auto to dwmatio den uparxei!" << endl;
        result=false;
    }
    return result;
}

// �������� ��������
int Hotel::bookingAdd (Booking* pointerBooking1){
    list<Room*>::iterator it;
    int kwdikos;
    for(it=rooms.begin(); it!=rooms.end(); ++it){ // ����������� � ����� ��������
        bool value=(*it)->bAddition(pointerBooking1); // ��� ���� ����������� ������� �������� � �������� �������� ���
                                                      // ������ ������� �� ������ ��� ������ ���� ����������� Booking
        if (value==true){                             // �� � �������� ���� ��������
            kwdikos=((*it)->getRoomCode());           // ������������ � ������� �������� ��� ����� ���������� � �������
            bookings.push_back(pointerBooking1);      // ��� � ������� ����������� ��� ��� ����� ���������
            cout << "Successfull Addition On Room "<< kwdikos << endl;
            break;
        }
        else{
            kwdikos=0;
            cout << "Addition Was Unsuccessfull For Room"<<" "<<((*it)->getRoomCode())<<"."<<"Let's Try Again!"<<endl;
        }
    }
    return kwdikos;
}

// ������� ��������
bool Hotel::bookingCancellation(int bNumber1){
    bool value1;
    bool apotelesma=false;
    int listSize=bookings.size(); // A����������� �� ������� ��� ������ bookings
    list<Booking*>::iterator IT;
    list<Booking*>::iterator iter1;
    Booking* mybooking=bookingRetrieval(bNumber1); // �������� � �������� �������� ��� ������ �� ������ ��� ������
                                                   // ��� �������� ��� ������ ��� ������ ��� ���� ������� ��������.
    list<Room*>::iterator it;
    for(it=rooms.begin(); it!=rooms.end(); ++it){   // ����������� � ����� ��������
            if (apotelesma==true){
                break;          // �� ��������� ��� ���� ��� ����� � �������
            }
             // ��� ���� ���� ��� ������ ��������������
            for (int i=0;i<30;i++){
                         // �� ������� ������� ��� � ������� ��� ������� �� �� ������
                         if ((((*it)->roomAvail[i])!=NULL) &&  (((*it)->roomAvail[i])->getBookingCode())==bNumber1){
                             // ������ ��� ������� �������� ��� ������ Room
                             value1=(*it)->bCancellation(bNumber1);
                              // �� � ������� ���� �������� ��� ������ ����� ������ ������� ��� ����� ���������
                              if ((value1==true)&& (listSize>0)){
                                 // �������� ��� ������� ��� �� ����� ���������
                                 bookings.remove(mybooking);
                                 // ������������ �� ��� ������� ��� ������
                                 int size1=bookings.size();
                                 // �� ������� ������� ��� ������� ��� ������ ���� ��� ���� ��� ��� ��������
                                 if (listSize!=size1){
                                    cout<<"Cancellation Successfull!"<<endl;
                                    apotelesma=true;
                                    break; // ������� ��� ��� ����������� for
                                 }
                                 // �� ��� ������� ������� ��� �������
                                 else{
                                    apotelesma=false;
                                    cout<<"something went wrong!!!!!"<<endl;
                                 }
                             }
                             else{
                                 cout<<"something went wrong"<<endl;
                                 apotelesma=false;
                             }
                         }
            }
            // �� ���� �������� � ������� ������� ��� ��� ��� ��������� for
            if(apotelesma==true){
                    break;
            }
 }
 // �� ����� ��������� �� ����������� ��� ��� ������� ������� �� ��� ������������ �������
 if (apotelesma==false){
    cout <<"Cancellation Failed!"<<" "<<"Booking"<<" "<<bNumber1<<" "<<"Doesn't Exist!"<<endl;
 }

 return apotelesma;
}

 // ����������� ������ �� ������
 double Hotel::profitEstimation(int roomNumber){
    list<Room*>::iterator it;
    double timi=0.0;
	for(it=rooms.begin(); it!=rooms.end(); ++it){ // ����������� � ����� ��� ��������
        int dwmatio=((*it)->getRoomCode());       // ������������ � ���. �������� ��� ���� �������
		if (roomNumber==dwmatio){                 // �� ������ ������� �� ������ ��� �� �� ������ �������� � �������
             timi=((*it)->pricing());             // ����������� ��� �� ������������ ���� ��������
		}
	}
	return timi;
 }

 // ����������� ������ ����� ������
 double Hotel::profitEstimation(){
    list<Room*>::iterator it;
    double totalCost=0.0;
	for(it=rooms.begin(); it!=rooms.end(); ++it){
        totalCost=totalCost+((*it)->pricing());   // ������������ �� �������� ������ ��� ��������
	}
	return totalCost;
 }

 // ����� ���������
 void Hotel::bookingSchedule(){
      list<Room*>::iterator it;
      int myNumber;
      string sign;
      cout <<"Room ";
      for (int x=1;x<=30;x++){
        cout<<x << " ";          // ����������� ���� ���� ��� ������ ��������������
       }
      for(it=rooms.begin(); it!=rooms.end(); ++it){ // ��� ���� ������� ��� ������ ��������
          myNumber=(*it)->getRoomCode();            // ������������ � ������� ��������
          cout << "\n"<<"   "<<myNumber << "    ";
          for (int i=0;i<30;i++){                   // ��� ���� ���� ��� ������ ��������������
              if (((*it)->roomAvail[i])!=NULL){     // �� �� ������ ���� ��� ������ ������� �������
                sign= "*";
              }
              else {
                sign= "_";
              }
              cout << sign << " ";
          }
      }
 }



// ������� ��� ��� �������� ��� ����������� ��� ��������� ��� ��� ������� 4 ��� �� �����
// �������� ���� ��� ��� main
 void Hotel::PrintBookingInfo(){
      list<Room*>::iterator it;
      int myRNumber[1000]={}; // ������� ��� ����������� ��� ����������� ��� ��������
                               // ��� ���� ���� ��� ������ ��������������
      int myBNumber[1000]={};
      string name[1000];
      cout << setw(15)<< left << "Booking ID"
            << setw(15)<< left << "Client Name"
            << setw(4) << "Room ID" <<endl;

      for(it=rooms.begin(); it!=rooms.end(); ++it){ // ��� ��� �� ������� ��� ������ ��������
          int myNum=(*it)->getRoomCode(); // ���������� ��� ������ ��������
          if (((*it)->roomAvail[0])!=NULL){  // �� ������� ������� ��� ���� ����� ��� ������ ��������������
               myBNumber[0]=(((*it)->roomAvail[0])->getBookingCode()); // ���������� ��� �����������
               name[0]=(((*it)->roomAvail[0])->getClientName());
               myRNumber[0]= myNum;
               cout << setw(15)<< left << myBNumber[0]             // ������ ��� �����������
                    << setw(15)<< left << name[0]
                    << setw(4) << myRNumber[0] <<endl;
          }
          for (int i=1;i<=29;i++){        // ��� ���� ���� ��� ������ �������������� ��� �� ���� 1
              if (((*it)->roomAvail[i])!=NULL){  // �� ������� �������
                myBNumber[i]=(((*it)->roomAvail[i])->getBookingCode()); // ���������� �����������
                name[i]=(((*it)->roomAvail[i])->getClientName());
                   myRNumber[i]= myNum;
                    if(myBNumber[i]!=myBNumber[i-1]){                // ������
                     cout << setw(15)<< left << myBNumber[i]
                          << setw(15)<< left << name[i]
                          << setw(4) << myRNumber[i] <<endl;
                    }
              }
          }

      }
 }

// ������� ��� ��� �������� ��� ����������� ��� �������� ��� ��� ������� 5 ��� �� �����
// �������� ���� ��� ��� main
 void Hotel::PrintRoomInfo(){
     cout << setw(15)<< left << "Kwdikos"
             << setw(15)<< left << "Plhrothta"
             << setw(4) << "Esoda" <<endl;
     list<Room*>::iterator it;
    for(it=rooms.begin(); it!=rooms.end(); ++it){ // ��� ���� ������� ��� ������ ����������
        int myNum=(*it)->getRoomCode();           // ������
        float occ=(*it)->occupancy();             // ���������
        double esoda=(*it)->pricing();            // ����������
        cout << setw(15) << left << myNum
             << setw(15) << left << occ
             << setw(4) << esoda <<endl;;
    }
 }

// ������� ��� ��� ������� ���� ������� ��������.
// �������� ���� ��� ��� main
 void Hotel::randomBookingCancellation(){
     // ���������� vector �� �� �������� ��� ������ bookings
     vector<Booking*> vectorBooking (bookings.begin(),bookings.end());
     int value;
     if ((vectorBooking.size())!=0){
        vector<Booking*>::iterator randomIt = vectorBooking.begin();
        // ������� ���� ������� ��������� ��� ��� vector
        advance(randomIt, rand()%vectorBooking.size());
       // ���������� ��� ������� �������� ��� ������������ ������� ��� ���������� ������
        value=(*randomIt)->getBookingCode();
        // �������� � ������� �������� ��� ��� ������� �� id=value
        bookingCancellation(value);
        cout<<"Booking "<<value<<" Doesn't exist Anymore!"<<endl;
     }
     else {
        cout<<"den uparxei krathsh gia tyxaia akyrwsh!!!"<<endl;
     }
 }

// ������� ��� ��� �������� ����������� ������� �� �� ����� ��� ����������� � ������������� ��������
// ��� ��� ������� 7 ��� �� �����
// �������� ���� ��� ��� main
 void Hotel::PrintIncomeInfo(){
    string answer;
    int number;
    double kostos;
    cout<<"Do you wish to see info about a specific room?"<<endl;
    cout<<"Please type 'yes' or 'no' for an answer!"<<endl;
    cin>>answer;
    if (answer=="yes"){
            cout<<"plese insert room id!"<<endl; // �� � ������� ����� ������ ������ �������� ��������
                                                 // � ������� ����������� ������ �� ������
            cin>>number;
            kostos=profitEstimation(number);
            cout<<"Ta esoda toy dwmatiou "<<number<<" einai: "<<kostos<<endl;
    }
    else if (answer=="no"){                     // ����������� �������� � ������� ����������� ������ ����� ������
            kostos=profitEstimation();
            cout<<"Ta esoda olwn twn dwmatiwn einai: "<<kostos<<endl;
    }
    else{
            cout<<"Wrong answer!"<<endl;
            PrintIncomeInfo();
    }
 }
