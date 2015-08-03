#ifndef H_ExtClockType
#define H_ExtClockType
#include "ClockType.h"
class ExtClockType: public ClockType {
	public:
		enum zoneType { EST, CST, MST, PST, EDT, CDT, MDT, PDT };
		void setTime(int hours, int minutes, int seconds, zoneType tZone);
		void printTime() const;
		void getTime(int& hours, int& minutes, int& seconds, int& tZone) const;
		//i had to add this one because there is a test for it on the assignment
		ExtClockType(int hours, int minutes, int seconds, zoneType tZone);
		ExtClockType();

	private:
		zoneType timeZone;

};

#endif //H_ExtClockType