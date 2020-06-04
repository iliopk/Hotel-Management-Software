#include "Booking.h"
#include "Room.h"
#include "Hotel.h"

unsigned int Booking::bookingNum=1; // Αρχικοποίηση του κωδικού κράτησης


Booking::Booking(){

	bookingID=bookingNum++;  // Με κάθε δημιουργία αντικειμένου Booking ο κωδικός κράτησης αυξάνεται κατά 1
}

Booking::~Booking(){
}

void Booking::roomAssignment(Room* ptrRoom){  // Η μεταβλητή-δείκτης room της κλάσης Booking εξισώνεται με τον δείκτη
                                              // προς αντικείμενο Room
	room=ptrRoom;                             // που δίνεται σαν όρισμα κατά την κλήση της μεθόδου
}

//getters

int Booking::getBookingCode(){    // Επιστρέφει τον κωδικό κράτησης
	return bookingID;
}

int Booking::getArrival(){       // Επιστρέφει την ημέρα άφιξης
	return arrival;
}

string Booking::getClientName(){  // Επστρέφει το όνομα πελάτη
	return clientName;
}

int Booking::getStayDuration(){   // Επιστρέφει την διάρκεια παραμονής
	return stayDuration;
}

int Booking::getPeople(){         // Επιστρέφει τον αριθμό των ατόμων που θα μείνουν στο δωμάτιο
	return people;
}


// setters

void Booking::setArrival(int arrivalDay){ // Ανατίθεται τιμή στην μεταβλητή κλάσης arrival
	arrival=arrivalDay;                   // δηλαδή ορίζεται η ημέρα άφιξης
}
void Booking::setClientName(string clName){ // Ανατίθεται τιμή στην μεταβλητή κλάσης clientName
	clientName=clName;                      // δηλαδή ορίζεται το όνομα πελάτη
}
void Booking::setStayDuration(int days){    // Ανατίθεται τιμή στην μεταβλητή κλάσης stayDuration
	stayDuration=days;                      // δηλαδή ορίζεται η διάρκεια παραμονής
}
void Booking::setPeople(int visitors){      // Ανατίθεται τιμή στην μεταβλητή κλάσης people
	people=visitors;                        // δηλαδή ορίζεται ο αριθμός των ατόμων που θα μείνουν στο δωμάτιο
}






