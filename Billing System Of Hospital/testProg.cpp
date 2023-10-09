#include <iostream>
#include <string>

#include "personType.h"
#include "doctorType.h"
#include "patientType.h"
#include "billType.h"
#include "dateType.h"
#include <clocale>
#include <fcntl.h>

using namespace std;

int checkDate(int month, int day, int year);

int main()
{
	std::setlocale(LC_ALL, "Turkish");
	billType bill;
	personType name;
	doctorType doctor;
	dateType DOBirth, a_date, d_date;
	patientType patient;
	int pID, pAge, m, d, y, m1, d1, y1, m2, d2, y2;
	float RoomCharge = 199.90, PharmacyCharge = 100.50, DoctorsFee;
	string first, last, first_, last_, speciality;
	string controlstring = "";
	int controlcounter = 0;
	string Specialities[20] = {
						  "Allergy and immunology",
						  "Anesthesiology",
						  "Dermatology",
						  "Diagnostic radiology",
						  "Emergency medicine",
						  "Family medicine",
						  "Internal medicine",
						  "Medical genetics",
						  "Neurology",
						  "Nuclear medicine",
						  "Obstetrics and gynecology",
						  "Ophthalmology",
						  "Pathology",
						  "Pediatrics",
						  "Physical medicine and rehabilitation",
						  "Preventive medicine",
						  "Psychiatry",
						  "Radiation oncology",
						  "Surgery",
						  "Urology" };

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter patient's ID(type quit for exit): ";
		getline(cin,controlstring);

		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if ((!isdigit(controlstring[controlint]) && controlstring[controlint] != '\0') || isspace(controlstring[controlint]))
				{
					cout << "You entered non digit character.\n";
					controlcounter = 0;
					break;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	pID = stoi(controlstring.c_str());
	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter patient's age(type quit for exit): ";
		getline(cin, controlstring);
		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else 
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if ((!isdigit(controlstring[controlint]) && controlstring[controlint] != '\0') || isspace(controlstring[controlint]))
				{
					cout << "You entered non digit character.\n";
					controlcounter = 0;
					break;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	pAge = stoi(controlstring.c_str());
	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter patient's date of birth in the form (mm-dd-yyyy)(type quit for exit): ";
		getline(cin, controlstring);

		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else if (controlstring.length() != 10)
		{
			cout << "You entered non allowed format input.\n";
			controlcounter = 0;
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if (!(controlint == 2) && !(controlint == 5))
				{
					if ((!isdigit(controlstring[controlint]) && controlstring[controlint] != '\0') || isspace(controlstring[controlint]))
					{
						cout << "You entered non allowed format input.\n";
						controlcounter = 0;
						break;
					}
					else
					{
						controlcounter = 1;
					}
				}
				else if (controlstring[controlint] != '-')
				{
					cout << "You entered non allowed format input.\n";
					controlcounter = 0;
					break;
				}
			}

			if (controlcounter == 1)
			{
				m = stoi(controlstring.substr(0, 2).c_str());
				d = stoi(controlstring.substr(3, 2).c_str());
				y = stoi(controlstring.substr(6, 4).c_str());

				if (checkDate(m, d, y))
				{
					cout << "You entered non allowed format input.\n";
					controlcounter = 0;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter patient's first name(type quit for exit): ";
		getline(cin, controlstring);
		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else if (controlstring[controlstring.length() - 1] == ' ')
		{
			cout << "You entered white space at end.\n";
			controlcounter = 0;
		}
		else if (controlstring[0] == ' ')
		{
			cout << "You entered white space at start.\n";
			controlcounter = 0;
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if (isspace(controlstring[controlint]))
				{
					for (int controlintws = controlint + 1; controlintws < controlstring.length(); controlintws++)
					{
						if (isspace(controlstring[controlintws]))
						{
							cout << "You entered two times space character.\n";
							controlcounter = 0;
							break;
						}
					}

					if (controlcounter == 0)
						break;
				}
				else if (!isalpha(controlstring[controlint]) && controlstring[controlint] != '\0')
				{
					printf("You entered non alphabetic character.\n");
					controlcounter = 0;
					break;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	first = controlstring;
	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter patient's last name(type quit for exit): ";
		getline(cin, controlstring);
		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else if (controlstring[controlstring.length() - 1] == ' ')
		{
			cout << "You entered white space at end.\n";
			controlcounter = 0;
		}
		else if (controlstring[0] == ' ')
		{
			cout << "You entered white space at start.\n";
			controlcounter = 0;
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if ((!isalpha(controlstring[controlint]) && controlstring[controlint] != '\0') || isspace(controlstring[controlint]))
				{
					cout << "You entered non alphabetic character.\n";
					controlcounter = 0;
					break;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	last = controlstring;
	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter doctor's first name(type quit for exit): ";
		getline(cin, controlstring);
		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else if (controlstring[controlstring.length() - 1] == ' ')
		{
			cout << "You entered white space at end.\n";
			controlcounter = 0;
		}
		else if (controlstring[0] == ' ')
		{
			cout << "You entered white space at start.\n";
			controlcounter = 0;
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if (isspace(controlstring[controlint]))
				{
					for (int controlintws = controlint + 1; controlintws < controlstring.length(); controlintws++)
					{
						if (isspace(controlstring[controlintws]))
						{
							cout << "You entered two times space character.\n";
							controlcounter = 0;
							break;
						}
					}

					if (controlcounter == 0)
						break;
				}
				else if (!isalpha(controlstring[controlint]) && controlstring[controlint] != '\0')
				{
					printf("You entered non alphabetic character.\n");
					controlcounter = 0;
					break;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	first_ = controlstring;
	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter doctor's last name(type quit for exit): ";
		getline(cin, controlstring);
		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else if (controlstring[controlstring.length() - 1] == ' ')
		{
			cout << "You entered white space at end.\n";
			controlcounter = 0;
		}
		else if (controlstring[0] == ' ')
		{
			cout << "You entered white space at start.\n";
			controlcounter = 0;
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if ((!isalpha(controlstring[controlint]) && controlstring[controlint] != '\0') || isspace(controlstring[controlint]))
				{
					printf("You entered non alphabetic character.\n");
					controlcounter = 0;
					break;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	last_ = controlstring;
	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		for (int specialityint = 0; specialityint < 20; specialityint++)
		{
			cout << specialityint << " for " << Specialities[specialityint] << "\n";
		}

		cout << "Choose doctor's speciality(type quit for exit): \n";

		getline(cin, controlstring);
		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if ((!isdigit(controlstring[controlint]) && controlstring[controlint] != '\0') || isspace(controlstring[controlint]))
				{
					cout << "You entered non digit character.\n";
					controlcounter = 0;
					break;
				}
				else
				{
					controlcounter = 1;
				}
			}

			if (controlcounter == 1 && (atoi(controlstring.c_str()) > 19 || atoi(controlstring.c_str()) < 0))
			{
				cout << "Please enter number related with listed specialities.\n";
				controlcounter = 0;
			}
			else
			{
				switch (atoi(controlstring.c_str()))  //Doctor Fees will be initialize as variable like array and stoi index will match corresponding speciality.
				{
				case 0:  DoctorsFee = 400.75; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 1:  DoctorsFee = 200.50; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 2:  DoctorsFee = 333.33; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 3:  DoctorsFee = 250.45; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 4:  DoctorsFee = 300.50; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 5:  DoctorsFee = 200.00; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 6:  DoctorsFee = 500.00; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 7:  DoctorsFee = 555.55; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 8:  DoctorsFee = 600.00; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 9:  DoctorsFee = 777.77; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 10: DoctorsFee = 150.00; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 11: DoctorsFee = 200.00; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 12: DoctorsFee = 270.15; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 13: DoctorsFee = 450.49; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 14: DoctorsFee = 222.21; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 15: DoctorsFee = 296.69; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 16: DoctorsFee = 222.22; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 17: DoctorsFee = 800.80; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 18: DoctorsFee = 888.88; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				case 19: DoctorsFee = 500.75; cout << "Doctors fee of " << Specialities[stoi(controlstring.c_str())] << " is " << DoctorsFee << "\n"; break;
				default:break;
				}
			}
		}
	}

	speciality = Specialities[stoi(controlstring.c_str())];
	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter the patient's admit date in the form(mm-dd-yyyy)(type quit for exit): ";
		getline(cin, controlstring);

		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else if (controlstring.length() != 10)
		{
			cout << "You entered non allowed format input.\n";
			controlcounter = 0;
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if (!(controlint == 2) && !(controlint == 5))
				{
					if ((!isdigit(controlstring[controlint]) && controlstring[controlint] != '\0') || isspace(controlstring[controlint]))
					{
						cout << "You entered non allowed format input.\n";
						controlcounter = 0;
						break;
					}
					else
					{
						controlcounter = 1;
					}
				}
				else if (controlstring[controlint] != '-')
				{
					cout << "You entered non allowed format input.\n";
					break;
				}
			}

			if (controlcounter == 1)
			{
				m1 = stoi(controlstring.substr(0, 2).c_str());
				d1 = stoi(controlstring.substr(3, 2).c_str());
				y1 = stoi(controlstring.substr(6, 4).c_str());

				if (checkDate(m1, d1, y1))
				{
					cout << "You entered non allowed format input.\n";
					controlcounter = 0;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	controlstring = "";
	controlcounter = 0;
	cout << "" << endl;

	while (controlstring.length() == 0 || controlcounter == 0)
	{
		cout << "Enter the patient's discharge date in the form(mm-dd-yyyy)(type quit for exit): ";
		getline(cin, controlstring);

		if (controlstring == "quit")
		{
			system("pause");
			exit(EXIT_FAILURE);
		}
		else if (controlstring.length() != 10)
		{
			cout << "You entered non allowed format input.\n";
			controlcounter = 0;
		}
		else
		{
			for (int controlint = 0; controlint < controlstring.length(); controlint++)//Input Check
			{
				if (!(controlint == 2) && !(controlint == 5))
				{
					if ((!isdigit(controlstring[controlint]) && controlstring[controlint] != '\0') || isspace(controlstring[controlint]))
					{
						cout << "You entered non allowed format input.\n";
						controlcounter = 0;
						break;
					}
					else
					{
						controlcounter = 1;
					}
				}
				else if (controlstring[controlint] != '-')
				{
					cout << "You entered non allowed format input.\n";
					controlcounter = 0;
					break;
				}
			}

			if (controlcounter == 1)
			{
				m2 = stoi(controlstring.substr(0, 2).c_str());
				d2 = stoi(controlstring.substr(3, 2).c_str());
				y2 = stoi(controlstring.substr(6, 4).c_str());

				if (checkDate(m2, d2, y2))
				{
					cout << "You entered non allowed format input.\n";
					controlcounter = 0;
				}
				else if ((y2 < y1) || (y2 == y1 && m2 < m1) || (y2 == y1 && m2 == m1 && d2 < d1))
				{
					cout << "Discharge date cannot be older than admit date.\n";
					controlcounter = 0;
				}
				else
				{
					controlcounter = 1;
				}
			}
		}
	}

	name.setName(first,last);

	doctor.setDoctor(first_,last_,speciality);

	DOBirth.setDate(m,d,y);

	a_date.setDate(m1,d1,y1);

	d_date.setDate(m2,d2,y2);

	patient.setpatientInfo(name, pID, pAge, DOBirth, a_date, d_date, doctor);

	cout << "" << endl;

	patient.printpatientInfo();

	d1 = (m1 * 30) + d1 + (y1 * 365);
	d2 = (m2 * 30) + d2 + (y2 * 365);

	d2 = d2 - d1;
	
	if (d2 == 0)
	{
		bill.setBill((PharmacyCharge* 1), (DoctorsFee* 1), (RoomCharge* 0), pID);
	}
	else
	{
		bill.setBill((PharmacyCharge* d2), (DoctorsFee* d2), (RoomCharge* d2), pID);
	}

	bill.printBill();

	system("pause");

	return 0;
}

int checkDate(int month, int day, int year)
{
	int status = 0;

	if ((month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12) && (day > 31 || day < 1))
	{
		status = 1;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1))
	{
		status = 1;
	}
	else if ((month == 2) && (year % 4 == 0) && (day > 29 || day < 1))
	{
		status = 1;
	}
	else if ((month == 2) && (year % 4 != 0) && (day > 28 || day < 1))
	{
		status = 1;
	}
	else if ((year < 1900) || (year > 2024))
	{
		status = 1;
	}
	if ((month < 1) || (month > 12))
	{
		status = 1;
	}
	return status;
};