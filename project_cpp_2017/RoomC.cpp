#include "RoomC.h"
#include "Booking.h"
#include "Hotel.h"
#include <iostream>
RoomC::RoomC(){
	int roomID=(Room::roomID);  // Εξασφαλίζουμε την σωστή αύξηση του κωδικού δωματίου
}                               // κατά την δημιουργία του αντικειμένου. Θέλουμε ο κωδικός να αυξάνεται κατά ένα
                                // σε κάθε δημιουργία αντικειμένου και όχι περισσότερες φορές καθώς η RoomC
                                // είναι υποκλάση της Room.



void RoomC::setMinPerson(int person){ // Ανατίθεται τιμή στην μεταβλητή κλάσης minPerson
   minPerson=person;                  // δηλαδή ορίζεται ο ελάχιστος αριθμός ατόμων
}

int RoomC::getMinPerson() {           // Επιστρέφει τον ελάχιστο αριθμό ατόμων
    return minPerson;
}

void RoomC::setMinDays(int days){    // Ανατίθεται τιμή στην μεταβλητή κλάσης minDays
    minDays=days;                    // δηλαδή ορίζεται ο ελάχιστος αριθμός ημερών
}
int RoomC::getMinDays() {              // Επιστρέφει τον ελάχιστο αριθμό ημερών
    return minDays;
}

// Προσθήκη Κράτησης (Υπερκάλυψη μεθόδου)
bool RoomC::bAddition(Booking* ptrBooking){
	bool flag;
	int counter=0;
	// Επιπλέον έλεγχος για το αν τηρούνται τα όρια σχετικά με τον ελάχιστο αριθμό ατόμων και ημερών
	// Ίδια λειτουγία με την bAddition της Room κατά τα άλλα
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
