//Implementation file Date
#include <iostream>
#include "DateType.h"

using namespace std;

void DateType::setDate(int month, int day, int year) {
	if (month <= 12 && month > 0) {
		dMonth = month;
	}
	else {
		dMonth = 1;
	}
	if (day <= 31 && day > 0) {
		dDay = day;
	}
	else {
		dDay = 1;
	}

	if (year > 0) {
		dYear = year;
	}
	else {
		dYear = 1 ;
	}
}

string DateType::getDate() {
	return to_string(dMonth) + '-' + to_string(dDay) + '-' + to_string(dYear);

}

void DateType::printDate() const {
	cout << dMonth << "-" << dDay << "-" << dYear << endl;
}

DateType::DateType(int month, int day, int year) {

	setDate(month, day, year);

}

bool DateType::isLeapYear() {
	if (dYear % 4 == 0 && dYear % 100 != 0) {
		return true;
	}
	else if (dYear % 4 == 0 && dYear % 100 == 0 && dYear % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}