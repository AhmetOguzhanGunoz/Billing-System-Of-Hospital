#ifndef H_billType
#define H_billType

#include "doctorType.h"
#include <string>

using namespace std;

class billType
{
private:

	float PharmacyCharges; //variable to store pharmacy charges.
	float DoctorsFees; //variable to store doctor's fees.
	float RoomCharges; //variable to store room charges.
	int patientID; //variable to store the patient's ID.

public:

	billType();//default constructor
	           //The private members of billType class are initialized.
	           //Postcondition: PharmacyCharges; DoctorsFees; RoomCharges; patientID;

	void setBill(float P_Ch, float D_Fee, float R_Ch, float pID);
	//Function to set PharmacyCharges, DoctorsFees, RoomCharges and patientID according to the parameters.
	//Postcondition: PharmacyCharges = P_Ch; DoctorsFees = D_Fee; RoomCharges = R_Ch; patientID = pID;

	void printBill() const;
	//Function to output the pharmacy charges, doctor's fees and room charges in the form
	//Pharmacy Charges
	//Room Charges
	//Doctor's Fees

	int getPharmacy() const;
	//Function to return the pharmacy charges.
	//Postcondition:The value of the data member PharmacyCharges is returned.

	int getRoomCh() const;
	//Function to return the room charges.
    //Postcondition: The value of the data member RoomCharges is returned.

	int getDocCh() const;
	//Function to return the doctor's fees.
    //Postcondition: The value of the data member DoctorsFees is returned.

};

#endif