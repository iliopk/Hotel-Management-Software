#include "RoomE.h"
#include "Booking.h"
#include "Hotel.h"

RoomE::RoomE(){
	int roomID=(Room::roomID); // Εξασφαλίζουμε την σωστή αύξηση του κωδικού δωματίου
}                               // κατά την δημιουργία του αντικειμένου. Θέλουμε ο κωδικός να αυξάνεται κατά ένα
                                // σε κάθε δημιουργία αντικειμένου και όχι περισσότερες φορές καθώς η RoomE
                                // είναι υποκλάση της Room.


void RoomE::setFoititis(bool Foititis){ // Ανατίθεται τιμή στην μεταβλητή κλάσης foititis
    foititis=Foititis;                  // δηλαδή ορίζεται αν ο πελάτης είναι φοιτητής ή όχι
}
void RoomE::setPrice(double cost){      // Ανατίθεται τιμή στην μεταβλητή κλάσης dayCost
    dayCost=cost;                       // δηλαδή ορίζεται η τιμή ανά ημέρα
}
bool RoomE::getFoititis(){              // Επιστρέφεται η τιμή της μεταβλητής foititis
    return foititis;
}
double RoomE::getPrice(){                // Επιστρέφεται η τιμή ανά ημέρα
    return dayCost;
}

//Τιμολόγηση (Υπερκάλυψη μεθόδου)
double RoomE::pricing() {
   double expenseE=0.0;
	if (roomAvail[0]==NULL){
	  for(int x=1;x<30;x++){
        if ((roomAvail[x]!=NULL)&&(roomAvail[x]!=roomAvail[x-1])){
           for (int j=1;j<(roomAvail[x]->getStayDuration());j++){
             if ((getFoititis())==true){                      // Αν ο πελάτης είναι φοιτητής
                     expenseE=expenseE + getPrice()*0.5;      // έχει 50% έκπτωση ανά ημέρα
		    }
		    else {
                 expenseE= expenseE+ getPrice();              // Διαφορετικά το κόστος υπολογίζεται μόνο βάσει
                 }                                            // της τιμής ανά ημέρα
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
