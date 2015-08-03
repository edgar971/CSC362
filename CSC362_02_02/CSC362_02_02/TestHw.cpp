#include <iostream>
#include <string>
#include "DateType.h"
#include "TestHarness.h"
using namespace std;

SimpleString StringFrom(const string& value)
{
	return SimpleString(value.c_str());
}

TEST(DateType, initialTest1)
{
	DateType date1(3, 15, 2010);
	CHECK_EQUAL("3-15-2010", date1.getDate());
}

TEST(DateType, initialTest2)
{
	DateType date2(25, 34, 2010);
	CHECK_EQUAL("1-1-2010", date2.getDate());
}

TEST(DateType, initialTest3)
{
	DateType date3(3, 30, 2011);
	CHECK_EQUAL("3-30-2011", date3.getDate());
}

TEST(DateType, initialTest4)
{
	DateType date4;
	int m, d, y;
	m = 4;
	d = 15;
	y = 2012;
	date4.setDate(m, d, y);
	CHECK_EQUAL("4-15-2012", date4.getDate());
}

TEST(DateType, initialTest5)
{
	DateType date5;
	int m, d, y;
	m = 4;
	d = 15;
	y = 2012;
	date5.setDate(m, d, y);
	bool TRUE = 1;
	LONGS_EQUAL(TRUE, date5.isLeapYear());

}

TEST(DateType, initialTest6)
{
	DateType date6;
	int m, d, y;
	m = 4;
	d = 15;
	y = 2013;
	date6.setDate(m, d, y);
	bool FALSE = 0;
	LONGS_EQUAL(FALSE, date6.isLeapYear());
}


