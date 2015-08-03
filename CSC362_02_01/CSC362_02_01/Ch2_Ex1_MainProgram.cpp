#include "TestHarness.h"
#include "ExtClockType.h"

using namespace std;

int main() {
	TestResult tr;
	TestRegistry::runAllTests(tr);
	return 0;

}