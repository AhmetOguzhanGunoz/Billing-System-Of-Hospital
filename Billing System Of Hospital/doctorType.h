#ifndef H_doctorType
#define H_doctorType

#include <string>
#include "personType.h"

using namespace std;

class doctorType: public personType
{
public:
	void print() const;
	 //Function to output the first name , last name , doctor's speciality
     //in the form firstName lastName dSpeciality

	void setDoctor(string first, string last, string speciality);
	//Function to set firstName, lastName and doctor's speciality according 
    //to the parameters.
    //Postcondition: firstName = first; lastName = last; dSpeciality = speciality;

	string getSpeciality() const;
	 //Function to return the doctor's speciality.
     //Postcondition: The value of the data member dSpeciality;
	 //               is returned.

	doctorType(string first = "", string last = "",string speciality = "");
	 //constructor
     //Sets firstName, lastName and dSpeciality according to the parameters.
     //The default values of the parameters are empty strings.
     //Postcondition: firstName = first; lastName = last; dSpeciality = speciality;

private:
	personType name; //variable to store the doctor's name and surname.
	string dSpeciality; //variable to store the doctor's speciality
};

#endif