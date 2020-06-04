#include "Hotel.h"
#include "Room.h"
#include "Booking.h"
#include <iostream>
#include <iomanip> // Για το setw. Ορίζεται το μέγεθος του πεδίου που θα εκτυπωθούν τα αποτελέσματα.

using namespace std;


void Hotel::setHotelName(string hName){
	hotelName=hName;  // Αναθέτει τιμή στην μεταβλητή κλάσης hotelName, έτσι ορίζεται το όνομα ξενοδοχείου.
}


string Hotel::getHotelName(){
	return hotelName; // Επιστρέφει την τιμή του hotelName.
}

// Προσθήκη Κράτησης
// Καλείται με όρισμα δείκτη προς αντικείμενο Room.
void Hotel::rAddition(Room* ptrRoom1){
	rooms.push_back(ptrRoom1); // Ο δείκτης προστίθεται στην λίστα rooms.
}

// Ανάκτηση Δωματίου Από Κωδικό
Room* Hotel::roomRetrieval(int rNumber){
	list<Room*>::iterator it;
    bool flag=false;
    int temp;
	for(it=rooms.begin(); it!=rooms.end(); ++it){ // Διατρέχει τη λίστα rooms
        temp=(*it)->getRoomCode();   // Σε κάθε επανάληψη αποθηκεύει τον κωδικό δωματίου.
		if (rNumber==temp){          // Ελέγχει αν κάποιος κωδικός δωματίου ισούται με το όρισμα που δόθηκε στην μέθοδο.
			flag=true;               // Αν υπάρξει ταίριασμα η επανάληψη σταματά και η μέθοδος επιστρέφει δείκτη προς το
            break;                   // αντικείμενο δωμάτιο του οποίου ο κωδικός ισούται με το όρισμα.
		}
		else{
			continue;
		}
	}
	if (flag==true){
        return *it;
	}
	else{
        return NULL;               // Διαφορετικά αφού διατρεχτεί ολόκληρη η λίστα, η μέθοδος τελειώνει επιστρέφοντας NULL.
	}
}

// Ανάκτηση Κράτησης Από Κωδικό
// Ίδια λειτουργία με την μέθοδο 'Ανάκτηση Δωματίου Από Κωδικό'.
// Εδώ διατρέχεται η λίστα bookings.
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

// Προσθήκη Κράτησης Σε Δωμάτιο
bool Hotel::bookingToRoomAdd (Booking* pointerBooking, int rNumber1){
    Room* myptr=roomRetrieval(rNumber1); // Καλείται η Ανάκτηση Δωματίου Από Κωδικό και το αποτελεσμά της αποθηκεύεται
    bool result;                         // στον δείκτη myptr.
    if (myptr!=NULL){                    // Αν υπάρχει δωμάτιο με κωδικό rNumber1
        bool myflag = (myptr->bAddition(pointerBooking)); // καλείται η Προσθήκη Κράτησης της κλάσης Δωμάτιο
        if (myflag==true){                                // Αν ήταν επιτυχής η προσθήκη κράτησης,
            bookings.push_back(pointerBooking);           // η κράτηση προστίθεται και στη λίστα bookings
            result=true;                                  // και η μέθοδος επιστρέφει true.
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

// Προσθήκη Κράτησης
int Hotel::bookingAdd (Booking* pointerBooking1){
    list<Room*>::iterator it;
    int kwdikos;
    for(it=rooms.begin(); it!=rooms.end(); ++it){ // Διατρέχεται η λίστα δωματίων
        bool value=(*it)->bAddition(pointerBooking1); // Για κάθε αντικείμενο δωμάτιο καλείται η Προσθήκη Κράτησης της
                                                      // κλάσης Δωμάτιο με όρισμα ένα δείκτη προς αντίκείμενο Booking
        if (value==true){                             // Αν η προσθήκη ήταν επιτυχής
            kwdikos=((*it)->getRoomCode());           // αποθηκεύεται ο κωδικος δωματίου στο οποίο προστέθηκε η κράτηση
            bookings.push_back(pointerBooking1);      // και η κράτηση προστίθεται και στη λίστα κρατήσεων
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

// Ακύρωση Κράτησης
bool Hotel::bookingCancellation(int bNumber1){
    bool value1;
    bool apotelesma=false;
    int listSize=bookings.size(); // Aποθηκεύεται το μέγεθος της λίστας bookings
    list<Booking*>::iterator IT;
    list<Booking*>::iterator iter1;
    Booking* mybooking=bookingRetrieval(bNumber1); // Καλείται η Ανάκτηση Κράτησης Από Κωδικό με όρισμα τον κωδικό
                                                   // της κράτησης που δόθηκε σαν όρισμα και στην Ακύρωση Κράτησης.
    list<Room*>::iterator it;
    for(it=rooms.begin(); it!=rooms.end(); ++it){   // Διατρέχεται η λίστα δωματίων
            if (apotelesma==true){
                break;          // Σε περίπτωση που έχει ήδη γίνει η ακύρωση
            }
             // Για κάθε θέση του πίνακα διαθεσιμότητας
            for (int i=0;i<30;i++){
                         // Αν υπάρχει κράτηση και ο κωδικός της ισούται με το όρισμα
                         if ((((*it)->roomAvail[i])!=NULL) &&  (((*it)->roomAvail[i])->getBookingCode())==bNumber1){
                             // Κάλεσε την Ακύρωση Κράτησης της κλάσης Room
                             value1=(*it)->bCancellation(bNumber1);
                              // Αν η ακύρωση ήταν επιτυχής και υπήρχε όντως κάποια κράτηση στη λίστα κρατήσεων
                              if ((value1==true)&& (listSize>0)){
                                 // Αφαίρεσε την κράτηση από τη λίστα κρατήσεων
                                 bookings.remove(mybooking);
                                 // Αποθήκευεται το νέο μέγεθος της λίστας
                                 int size1=bookings.size();
                                 // Αν υπάρχει διαφορά στο μέγεθος της λίστας πριν και μετά από την αφαίρεση
                                 if (listSize!=size1){
                                    cout<<"Cancellation Successfull!"<<endl;
                                    apotelesma=true;
                                    break; // Βγαίνει από την εμφωλευμένη for
                                 }
                                 // Αν δεν υπάρχει διαφορά στο μέγεθος
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
            // Αν ήταν επιτυχής η ακύρωση βγαίνει και από την εξωτερική for
            if(apotelesma==true){
                    break;
            }
 }
 // Αν έχουν τελείωσει οι επαναλήψεις και δεν υπάρχει δωμάτιο με την συγκεκριμένη κράτηση
 if (apotelesma==false){
    cout <<"Cancellation Failed!"<<" "<<"Booking"<<" "<<bNumber1<<" "<<"Doesn't Exist!"<<endl;
 }

 return apotelesma;
}

 // Υπολογισμός Εσόδων με όρισμα
 double Hotel::profitEstimation(int roomNumber){
    list<Room*>::iterator it;
    double timi=0.0;
	for(it=rooms.begin(); it!=rooms.end(); ++it){ // Διατρέχεται η λίστα των δωματίων
        int dwmatio=((*it)->getRoomCode());       // Αποθηκεύεται ο κωδ. δωματίου για κάθε δωμάτιο
		if (roomNumber==dwmatio){                 // Αν βρεθεί δωμάτιο με κωδικό ίσο με το όρισμα καλείται η μέθοδος
             timi=((*it)->pricing());             // τιμολόγησης για το συγκεκριμένο τύπο δωματίου
		}
	}
	return timi;
 }

 // Υπολογισμός Εσόδων χωρίς όρισμα
 double Hotel::profitEstimation(){
    list<Room*>::iterator it;
    double totalCost=0.0;
	for(it=rooms.begin(); it!=rooms.end(); ++it){
        totalCost=totalCost+((*it)->pricing());   // υπολογίζεται το συνολικό κόστος των δωματίων
	}
	return totalCost;
 }

 // Πλάνο Κρατήσεων
 void Hotel::bookingSchedule(){
      list<Room*>::iterator it;
      int myNumber;
      string sign;
      cout <<"Room ";
      for (int x=1;x<=30;x++){
        cout<<x << " ";          // Εμφανίζεται κάθε μέρα του πίνακα διαθεσιμότητας
       }
      for(it=rooms.begin(); it!=rooms.end(); ++it){ // Για κάθε δωμάτιο της λίστας δωματίων
          myNumber=(*it)->getRoomCode();            // Αποθηκεύεται ο κωδικός δωματίου
          cout << "\n"<<"   "<<myNumber << "    ";
          for (int i=0;i<30;i++){                   // Για κάθε μέρα του πίνακα διαθεσιμότητας
              if (((*it)->roomAvail[i])!=NULL){     // Αν σε κάποια θέση του πίνακα υπάρχει κράτηση
                sign= "*";
              }
              else {
                sign= "_";
              }
              cout << sign << " ";
          }
      }
 }



// Μέθοδος για την εκτύπωση των πληροφοριών των κρατήσεων για την επιλογή 4 από το μενού
// Καλείται μόνο από την main
 void Hotel::PrintBookingInfo(){
      list<Room*>::iterator it;
      int myRNumber[1000]={}; // Πίνακες που αποθηκεύουν τις πληροφορίες των δωματίων
                               // για κάθε μέρα του πίνακα διαθεσιμότητας
      int myBNumber[1000]={};
      string name[1000];
      cout << setw(15)<< left << "Booking ID"
            << setw(15)<< left << "Client Name"
            << setw(4) << "Room ID" <<endl;

      for(it=rooms.begin(); it!=rooms.end(); ++it){ // Για όλα τα δωμάτια της λίστας δωματίων
          int myNum=(*it)->getRoomCode(); // Αποθήκευσε τον κωδικό δωματίου
          if (((*it)->roomAvail[0])!=NULL){  // Αν υπάρχει κράτηση στη θέση μηδέν του πίνακα διαθεσιμότητας
               myBNumber[0]=(((*it)->roomAvail[0])->getBookingCode()); // Αποθήκευσε τις πληροφορίες
               name[0]=(((*it)->roomAvail[0])->getClientName());
               myRNumber[0]= myNum;
               cout << setw(15)<< left << myBNumber[0]             // Τύπωσε τις πληροφορίες
                    << setw(15)<< left << name[0]
                    << setw(4) << myRNumber[0] <<endl;
          }
          for (int i=1;i<=29;i++){        // Για κάθε μέρα του πίνακα διαθεσιμότητας από τη θέση 1
              if (((*it)->roomAvail[i])!=NULL){  // Αν υπάρχει κράτηση
                myBNumber[i]=(((*it)->roomAvail[i])->getBookingCode()); // Αποθήκευσε πληροφορίες
                name[i]=(((*it)->roomAvail[i])->getClientName());
                   myRNumber[i]= myNum;
                    if(myBNumber[i]!=myBNumber[i-1]){                // Τύπωσε
                     cout << setw(15)<< left << myBNumber[i]
                          << setw(15)<< left << name[i]
                          << setw(4) << myRNumber[i] <<endl;
                    }
              }
          }

      }
 }

// Μέθοδος για την εκτύπωση των πληροφοριών των δωματίων για την επιλογή 5 από το μενού
// Καλείται μόνο από την main
 void Hotel::PrintRoomInfo(){
     cout << setw(15)<< left << "Kwdikos"
             << setw(15)<< left << "Plhrothta"
             << setw(4) << "Esoda" <<endl;
     list<Room*>::iterator it;
    for(it=rooms.begin(); it!=rooms.end(); ++it){ // Για κάθε δωμάτιο της λίστας αποθήκευσε
        int myNum=(*it)->getRoomCode();           // κωδικό
        float occ=(*it)->occupancy();             // πληρότητα
        double esoda=(*it)->pricing();            // τιμολόγηση
        cout << setw(15) << left << myNum
             << setw(15) << left << occ
             << setw(4) << esoda <<endl;;
    }
 }

// Μέθοδος για την ακύρωση μιας τυχαίας κράτησης.
// Καλείται μόνο από την main
 void Hotel::randomBookingCancellation(){
     // Δημιουργία vector με τα στοιχεία της λίστας bookings
     vector<Booking*> vectorBooking (bookings.begin(),bookings.end());
     int value;
     if ((vectorBooking.size())!=0){
        vector<Booking*>::iterator randomIt = vectorBooking.begin();
        // Επιλογή ενός τυχαίου στοιχείου από τον vector
        advance(randomIt, rand()%vectorBooking.size());
       // Αποθήκευση του κωδικού κράτησης του αντικειμένου κράτηση που επιλέχθηκε τυχαία
        value=(*randomIt)->getBookingCode();
        // Καλείται η Ακύρωση Κράτησης για την κράτηση με id=value
        bookingCancellation(value);
        cout<<"Booking "<<value<<" Doesn't exist Anymore!"<<endl;
     }
     else {
        cout<<"den uparxei krathsh gia tyxaia akyrwsh!!!"<<endl;
     }
 }

// Μέθοδος για την εκτύπωση πληροφοριών σχετικά με τα έσοδα του ξενοδοχείου ή συγκεκριμένου δωματίου
// για την επιλογή 7 από το μενού
// Καλείται μόνο από την main
 void Hotel::PrintIncomeInfo(){
    string answer;
    int number;
    double kostos;
    cout<<"Do you wish to see info about a specific room?"<<endl;
    cout<<"Please type 'yes' or 'no' for an answer!"<<endl;
    cin>>answer;
    if (answer=="yes"){
            cout<<"plese insert room id!"<<endl; // Αν ο χρήστης δώσει όρισμα κωδικό δωματίου καλείται
                                                 // η μέθοδος Υπολογισμός Εσόδων με όρισμα
            cin>>number;
            kostos=profitEstimation(number);
            cout<<"Ta esoda toy dwmatiou "<<number<<" einai: "<<kostos<<endl;
    }
    else if (answer=="no"){                     // Διαφορετικά καλείται η μέθοδος Υπολογισμός Εσόδων χωρίς όρισμα
            kostos=profitEstimation();
            cout<<"Ta esoda olwn twn dwmatiwn einai: "<<kostos<<endl;
    }
    else{
            cout<<"Wrong answer!"<<endl;
            PrintIncomeInfo();
    }
 }
