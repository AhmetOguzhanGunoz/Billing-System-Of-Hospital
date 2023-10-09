#include <iostream>
#include <string> 
#include "doctorType.h"

using namespace std;

void doctorType::print() const
{
	name.print();
	cout << " " << dSpeciality << endl;
}

void doctorType::setDoctor(string first, string last, string speciality)
{
	name.setName(first,last);
	dSpeciality = speciality;
}

string doctorType::getSpeciality() const
{
	return dSpeciality;
}

//constructor
doctorType::doctorType(string first, string last, string speciality): name(first, last)
{
	dSpeciality = speciality;
}