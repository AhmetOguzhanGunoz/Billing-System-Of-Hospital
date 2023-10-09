#ifndef H_patientType
#define H_patientType

#include <string>
#include "personType.h"
#include "doctorType.h"
#include "dateType.h"

using namespace std;

class patientType: public doctorType
{
private:
	personType name;            //variable to store patient's first name and last name.
	int patientID;              //variable to store patient's ID.
	int patientAge;             //variable to store patient's age.
	dateType DateOfBirth;       //variable to store patient's date of birth.
	dateType AdmitDate;         //variable to store patient's admit date to the hospital.
	dateType DischargeDate;     //variable to store patient's discharge date from the hospital.
	doctorType Doctor;     //variable to store the doctor's speciality.
public:
	patientType(); //default constructor
	               //The private members of patientType class are initialized.
	               //Postcondition: name; patientID; patientAge; DateOfBirth; AdmitDate; DischargeDate; Doctor;              
	                       
	void setpatientInfo(personType name,int pID, int pAge, dateType DOfBirth, dateType A_Date, dateType D_Date, doctorType doc);
	//Function to set private members according to the parameters.
	//Postcondition: name = Name1; patientID = pID; patientAge = pAge; DateOfBirth = DOfBirth; AdmitDate = A_Date;
	//               DischargeDate = D_Date; Doctor = doc;

	void printpatientInfo() const;
	//Function to print patient info in the form
	//Patient
	//Attending Doctor and his/her speciality
	//Admit Date
	//Discharge Date

	int getPatientID() const;
	//Function to return the patient's ID.
	//Postcondition: The value of the data member patientID is returned.

	int getPatientAge() const;
	//Function to return the patient's age.
	//Postcondition: The value of the data member patientAge is returned.

	dateType getDateOfBirth() const;
	//Function to return the patient's date of birht.
	//Postcondition: The value of the data member DateOfBirth is returned.

	dateType getAdmitDate() const;
	//Function to return the patient's admitting date.
	//Postcondition: The value of the data member AdmitDate is returned.

	dateType getDischargeDate() const;
	//Function to return the patient's discharging date.
	//Postcondition: The value of the data member DischargeDate is returned.

	doctorType getDoctor() const;
    //Function to return the patient's attending doctor's name and speciality.
	//Postcondition: The value of the data member xSpeciality is returned.

};

#endif