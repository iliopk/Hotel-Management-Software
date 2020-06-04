#include "RoomB.h"
#include "RoomA.h"
#include "Booking.h"
#include "Hotel.h"
#include <iostream>


RoomB::RoomB(){
    int roomID=(Room::roomID);  // Εξασφαλίζουμε την σωστή αύξηση του κωδικού δωματίου
}                               // κατά την δημιουργία του αντικειμένου. Θέλουμε ο κωδικός να αυξάνεται κατά ένα
                                // σε κάθε δημιουργία αντικειμένου και όχι περισσότερες φορές καθώς η RoomΒ
                                // είναι υποκλάση της RoomΑ.



void RoomB::setDayDiscount(double discount){ // Ανατίθεται τιμή στην μεταβλητή κλάσης dayDiscount
     dayDiscount=discount;                   // δηλαδή ορίζεται η έκπτωση ανά ημέρα
}

double RoomB::getDayDiscount(){              // Επιστρέφει την έκπτωση ανά ημέρα
     return dayDiscount;
}

//Τιμολόγηση (Υπεκάλυψη μεθόδου)
double RoomB::pricing() {
   double finalPrice;
    int counter=0;
   for (int i=0;i<30;i++){
     if (roomAvail[i]==NULL){
        counter++;
     }
   }
   if (counter==30){ // Αν στο δωμάτιο δεν υπάρχει καμία κράτηση
     finalPrice=0.0;
   }
   else{
   finalPrice=getDayPrice();
   if (roomAvail[0]==NULL){     // Αν η θέση '0' του πίνακα διαθεσιμότητας είναι κενή
	  for(int x=1;x<30;x++){    // Για κάθε μέρα του πίνακα διαθεσιμότητας
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
			 double expenseB=getDayPrice(); // αρχική τιμή ανά ημέρα
			 for (int j=1;j<(roomAvail[x]->getStayDuration());j++){
			     expenseB=expenseB-getDayDiscount(); // τιμή ανά ημέρα μετά την έκπτωση
                if (expenseB>(getDayPrice()/2.0)){   // αν η τιμή ανά ημέρα μετά την έκπτωση δεν είναι μικρότερη
                                                     // από το μισό της αρχικής τιμής ανά ημέρα
                    finalPrice=finalPrice+expenseB;
                }
                else{
                    finalPrice=finalPrice+(getDayPrice()/2.0);
                }
			 }
		}
      }
	}
    else { // Αντίστοιχα με την μέθοδο τιμολόγησης στην κλάση RoomA
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

//Ακύρωση Κράτησης (Υπερκάλυψη μεθόδου)
bool RoomB::bCancellation(){

	return false;
}
