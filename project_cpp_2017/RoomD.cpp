#include"RoomD.h"
//#include "Room.h"
#include "Booking.h"
#include "Hotel.h"
RoomD::RoomD(){
	int roomID=(Room::roomID);  // Εξασφαλίζουμε την σωστή αύξηση του κωδικού δωματίου
}                               // κατά την δημιουργία του αντικειμένου. Θέλουμε ο κωδικός να αυξάνεται κατά ένα
                                // σε κάθε δημιουργία αντικειμένου και όχι περισσότερες φορές καθώς η RoomD
                                // είναι υποκλάση της Room.

// Πληρότητα (Υπερκάλυψη μεθόδου)
float RoomD::occupancy(){
	float counter=0.0;
	for (int x=0;x<=29;x++){
		if (roomAvail[x]!=NULL){
			counter++;
		}
	}
	float sum=(counter*100.0)/30.0;
	// Αν η πληρότητα του δωματίου είναι μεγαλύτερη από 70% εμφανίζει μήνυμα
	if (sum>70.0){
		cout<<"Attention! In high demand!"<<endl;
	}
	return sum;
}
