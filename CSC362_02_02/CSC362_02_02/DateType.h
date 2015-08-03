#ifndef DateType_H
#define DateType_H
#include <string>
#include <iostream>
using namespace std;

class DateType
{
public:
	void setDate(int month, int day, int year);
	//Function to set the Date
	//Data members dMonth, dDay, and dYear are set 
	//according to the parameters
	//Postcondition: dMonth = month; dDay = day;
	//    dYear = year

	string getDate();
	//Function to return the Date as a string in mm-dd-yyyy format


	bool isLeapYear();
	//Function to check if a year is a leap year
	//Return true if a year is a leap year, false otherwise

	void printDate() const;
	//Function to output the Date in the form mm-dd-yyyy.

	DateType(int month = 1, int day = 1, int year = 1900);
	//Constructor to set the Date
	//Data members dMonth, dDay, and dYear are set 
	//according to the parameters
	//Postcondition: dMonth = month; dDay = day; 
	//    dYear = year
	//If no values are specified, the default values are 
	//used to initialize the data members.

private:
	int dMonth;	//variable to store month
	int dDay;   //variable to store day
	int dYear;  //variable to store year
};

#endif