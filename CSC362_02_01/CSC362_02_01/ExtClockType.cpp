#include <iostream>
#include "ExtClockType.h"
using namespace std;


void ExtClockType::setTime(int hours, int minutes, int seconds, zoneType tZone) {
	ClockType::setTime(hours, minutes, seconds);
	timeZone = tZone;
}

void ExtClockType::printTime() const {
	ClockType::printTime();
	cout << " Timezone: "  << timeZone << endl;
	
}

void ExtClockType::getTime(int& hours, int& minutes, int& seconds, int& tZone) const {
	ClockType::getTime(hours, minutes, seconds);
	tZone = timeZone;
}
//i had to add this one because there is a test for it on the assignment
ExtClockType::ExtClockType(int hours, int minutes, int seconds, zoneType tZone):ClockType(hours, minutes, seconds) {
	timeZone = tZone;
}

ExtClockType::ExtClockType() :ClockType(0, 0, 0) {
	timeZone = EST;
}






