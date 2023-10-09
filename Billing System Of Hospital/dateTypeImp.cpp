#include <iostream>
#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year)
{
	dMonth = month;
	dDay = day;
	dYear = year;
}

int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

void dateType::printDate() const
{
	cout << dDay << "-" << dMonth << "-" << dYear << endl;
}

dateType::dateType(int month, int day, int year)
{
	month = 1;
	day = 1;
	year = 1990;
}