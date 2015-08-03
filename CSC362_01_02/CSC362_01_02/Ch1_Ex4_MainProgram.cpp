#include "TestHarness.h"
#include "PersonType.h"

using  namespace std;

int main() {
	TestResult tr;
	TestRegistry::runAllTests(tr);

	return 0;
}