#include "TestHarness.h"
#include "ArrayListType.h"
using namespace std;
int main()
{
	TestResult tr;
	TestRegistry::runAllTests(tr);
	return 0;
}