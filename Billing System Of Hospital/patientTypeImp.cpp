#include <iostream>
#include <string> 

#include "patientType.h"

using namespace std;

//default constructor
patientType::patientType()
{
	personType name;
	doctorType Doctor;
	dateType DateOfBirth;
	dateType AdmitDate;
	dateType DischargeDate;
	int patientID;
	int patientAge;
	
}

void patientType::setpatientInfo(personType Name1,int pID, int pAge, dateType DOfBirth, dateType A_Date, dateType D_Date, doctorType doc)
{
	name = Name1;
	patientID = pID;
	patientAge = pAge;
	DateOfBirth = DOfBirth;
	AdmitDate = A_Date;
	DischargeDate = D_Date;
	Doctor = doc;
}

void patientType::printpatientInfo() const
{
	cout << "Patient: ";
	name.print();
		 cout << endl;

	cout << "Attending Doctor: ";
	Doctor.print();

	cout << "Admit Date(dd-mm-yyyy): ";
	     AdmitDate.printDate();

	cout << "Discharge Date(dd-mm-yyyy): ";
	DischargeDate.printDate();

	cout << "Patient Id: " << patientID << endl;
	
	cout << "Patient Age: " << patientAge << endl;

	cout << "" << endl;



}

int patientType::getPatientID() const
{
	return patientID;
}

int patientType::getPatientAge() const
{
	return patientAge;
}

dateType patientType::getDateOfBirth() const
{
	return DateOfBirth;
}

dateType patientType::getAdmitDate() const
{
	return AdmitDate;
}

dateType patientType::getDischargeDate() const
{
	return DischargeDate;
}

doctorType patientType::getDoctor() const
{
	return Doctor;
}