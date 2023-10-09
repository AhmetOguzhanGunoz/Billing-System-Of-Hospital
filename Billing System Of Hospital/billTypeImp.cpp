#include <iostream>
#include <string>
#include "billType.h"

using namespace std;

//default constructor
billType::billType()
{
	float PharmacyCharges;
	float DoctorsFees;
	float RoomCharges;
	int patientID;
}

void billType::setBill(float P_Ch, float D_Fee, float R_Ch, float pID)
{
	PharmacyCharges = P_Ch;
	DoctorsFees = D_Fee;
	RoomCharges = R_Ch;
	patientID = pID;
}

void billType::printBill() const
{
	cout << "Pharmacy Charges: " << PharmacyCharges << "Lira" << endl;
	cout << "    Room Charges: " << RoomCharges << "Lira" << endl;
	cout << "   Doctor's Fees: " << DoctorsFees << "Lira" << endl;
	cout << "________________________________________________________________" << endl;
	cout << "   Total Charges: " << PharmacyCharges + RoomCharges + DoctorsFees << "Lira" << endl;
}

int billType::getPharmacy() const
{
	return PharmacyCharges;
}

int billType::getRoomCh() const
{
	return RoomCharges;
}

int billType::getDocCh() const
{
	return DoctorsFees;
}