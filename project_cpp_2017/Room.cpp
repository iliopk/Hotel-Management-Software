#include "Booking.h"
#include "Room.h"
#include "Hotel.h"
#include <iostream>

unsigned int Room::roomNum=1; // Αρχικοποίηση κωδικού Δωματίου

Room::Room(){

	roomID=roomNum++;   // Με κάθε δημιουργία αντικειμένου Room ο κωδικός Δωματίου αυξάνεται κατά 1
}

Room::~Room(){
}

//setters
void Room::setCapacity(int capacity){ // Ανατίθεται τιμή στην μεταβλητή κλάσης roomCapacity
	roomCapacity=capacity;            // δηλαδή ορίζεται η χωριτικότητα του δωματίου
}

void Room::setPricePerson(double priceIndividual){  // Ανατίθεται τιμή στην μεταβλητή κλάσης pricePerson
	pricePerson=priceIndividual;                    // δηλαδή ορίζεται η τιμή ανά άτομο
}

//getters

int Room::getRoomCode(){        // Επιστρέφει τον κωδικό δωματίου
	return roomID;
}

int Room::getCapacity(){        // Επιστρέφει την χωρητικότητα
	return roomCapacity;
}

double Room::getPricePerson(){  // Επιστρέφει την τιμή ανά άτομο
	return pricePerson;
}

// Προσθήκη Κράτησης
bool Room::bAddition(Booking* ptrBooking){
	bool flag;
	int c;
	int counter=0;
	if ((ptrBooking->getPeople())<=getCapacity()){  // Αρχικά ελέγχουμε αν ξεπερνάμε την μέγιστη χωρητικότητα

		// Έλεγχος αν το δωμάτιο είναι διαθέσιμο για όλη την διάρκεια της κράτησης

		for(int x=(ptrBooking->getArrival());x<((ptrBooking->getStayDuration())+(ptrBooking->getArrival()));x++){
			if (roomAvail[x-1]==NULL) {
				 counter++;
			}
        }

        // Αν είναι διαθέσιμο

        if (counter==(ptrBooking->getStayDuration())){
             flag=true;

             // Ανατίθεται στις κατάλληλες θέσεις του πίνακα διαθεσιμότητας η κράτηση

             for(int x=(ptrBooking->getArrival());x<((ptrBooking->getStayDuration())+(ptrBooking->getArrival()));x++){
                roomAvail[x-1]=ptrBooking;
                 c=getRoomCode(); // Αποθηκεύται ο κωδικός του δωματίου για το οποίο καλείται η μέθοδος bAddition
                vector<Hotel*>::iterator it;

                // Διατρέχουμε την λίστα ξενοδοχείων για το συγκεκριμένο δωμάτιο

	            for(it=hotels.begin(); it!=hotels.end(); ++it){
                    it=hotels.begin();               // επειδή υπάρχει μόνο ένα ξενοδοχείο στη συγκεκριμένη περίπτωση.
                    deikths=(*it)->roomRetrieval(c);    // Αποθηκεύουμε τον δείκτη που επιστρέφει η μέθοδος ανάκτηση
                                                        // δωματίου από κωδικό της κλάσης ξενοδοχείο
	            }
                ptrBooking->roomAssignment(deikths);    // και με αυτόν τον δείκτη σαν όρισμα καλούμε την μέθοδο
                                                        // της κλάσης Booking έτσι ώστε να ενημερωθεί η μεταβλητή-δείκτης
                                                        // της 'room'.
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

// Τιμολόγηση
double Room::pricing(){
	double expense=0.0;
	for(int x=0;x<30;x++){          // Για κάθε μέρα του πίνακα διαθεσιμότητας
		if (roomAvail[x]!=NULL){    // Αν υπάρχει κράτηση
			 expense=expense +((roomAvail[x]->getPeople())*getPricePerson());
		}
		else{
			expense=expense+0.0;
		}
	}
	return expense;
}

// Ακύρωση Κράτησης
bool Room::bCancellation(int arithmos){

		for(int x=0;x<30;x++){          // Για κάθε μέρα του πίνακα διαθεσιμότητας
           if (roomAvail[x]!=NULL){     // Αν υπάρχει κράτηση
			if ((roomAvail[x]->getBookingCode())==arithmos){
				roomAvail[x]=NULL;
			}
		  }
		}
	return true;
}

// Πληρότητα
float Room::occupancy(){
	float counter=0.0;
	for (int x=0;x<=29;x++){
		if (roomAvail[x]!=NULL){  // Έλεγχεται πόσες θέσεις του πίνακα διαθεσιμότητας είναι κατειλημμένες
			counter++;
		}
	}
	float sum=(counter*100.0)/30.0;
	return sum;
}

// Μέθοδος για την προσθήκη ξενοδοχείου σε δωμάτιο
// Δέχεται σαν όρισμα δείκτη προς αντικείμενο ξενοδοχείο και προσθέτει τον δείκτη στη λίστα ξενοδοχείων
void Room::hotelAddition(Hotel* ptrHotel1){
	hotels.push_back(ptrHotel1);
}

