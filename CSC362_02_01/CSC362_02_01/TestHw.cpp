#include "TestHarness.h"
#include "ClockType.h"
#include "ExtClockType.h"
#include <string>
using namespace std;

SimpleString StringFrom(const string& value)
{
	return SimpleString(value.c_str());
}
TEST(ClockType, initialTest)
{
	ClockType time1(5, 10, 34);
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	time1.getTime(hours, minutes, seconds);
	LONGS_EQUAL(5, hours);
	LONGS_EQUAL(10, minutes);
	LONGS_EQUAL(34, seconds);


}

TEST(ClockType, loadConstructorTest)
{
	ClockType time1;
	time1.setTime(12, 10, 34);
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	time1.getTime(hours, minutes, seconds);
	LONGS_EQUAL(12, hours);
	LONGS_EQUAL(10, minutes);
	LONGS_EQUAL(34, seconds);

}

TEST(ClockType, logicalIncrementTest)
{


	ClockType time1(9, 10, 34);
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	time1.getTime(hours, minutes, seconds);
	LONGS_EQUAL(9, hours);
	LONGS_EQUAL(10, minutes);
	LONGS_EQUAL(34, seconds);
	time1.incrementHours();
	time1.incrementSeconds();
	time1.getTime(hours, minutes, seconds);
	LONGS_EQUAL(10, hours);
	LONGS_EQUAL(10, minutes);
	LONGS_EQUAL(35, seconds);

}

TEST(ExtClockType, initialTest)
{
	//I had to add the constructor that will take 4 arguments, it was not on the assignment
	ExtClockType time1(5, 10, 34, ExtClockType::zoneType::MST);
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	int tZone;
	time1.getTime(hours, minutes, seconds, tZone);
	LONGS_EQUAL(5, hours);
	LONGS_EQUAL(10, minutes);
	LONGS_EQUAL(34, seconds);
	LONGS_EQUAL(2, tZone);

}

TEST(ExtClockType, loadConstructorTest)
{
	ExtClockType time1;
	time1.setTime(12, 10, 34, ExtClockType::zoneType::CST);
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	int tZone;
	time1.getTime(hours, minutes, seconds, tZone);
	LONGS_EQUAL(12, hours);
	LONGS_EQUAL(10, minutes);
	LONGS_EQUAL(34, seconds);
	LONGS_EQUAL(1, tZone);
}