#include "RoomA.h"
#include "Booking.h"
#include "Hotel.h"
#include <iostream>

RoomA::RoomA(){
    int roomID=(Room::roomID);  // Εξασφαλίζουμε την σωστή αύξηση του κωδικού δωματίου
}                               // κατά την δημιουργία του αντικειμένου. Θέλουμε ο κωδικός να αυξάνεται κατά ένα
                                // σε κάθε δημιουργία αντικειμένου και όχι περισσότερες φορές καθώς η RoomA
                                // είναι υποκλάση της Room.

// Τιμολόγηση(Υπερκάλυψη μεθόδου)
double RoomA::pricing() {
	double expenseA=0.0;
	if (roomAvail[0]==NULL){   // Αν η θέση '0' του πίνακα διαθεσιμότητας είναι άδεια
	  for(int x=1;x<30;x++){   // Υπολόγισε το κόστος για τις υπόλοιπες μέρες του μήνα
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
			 expenseA= expenseA+((roomAvail[x]->getStayDuration())*getDayPrice());
		}
      }
	}
    else {
       expenseA= (roomAvail[0]->getStayDuration())*getDayPrice(); // Υπολογισμός κόστους κράτησης που ξεκινά από
                                                                  // τη θέση '0' του πίνακα διαθεσιμότητας
       for(int x=(roomAvail[0]->getStayDuration());x<30;x++){     // Υπολογισμός για τις υπόλοιπες μέρες
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
			 expenseA= expenseA + ((roomAvail[x]->getStayDuration())*getDayPrice());
		}
       }
    }
    return expenseA;
}

void RoomA::setDayPrice(double dPrice){ // Ανατίθεται τιμή στην μεταβλητή κλάσης dayPrice
    dayPrice=dPrice;                    // δηλαδή ορίζεται η τιμή ανά ημέρα
}

double RoomA::getDayPrice(){            // Επιστρέφει την τιμή ανά ημέρα
    return dayPrice;
}
