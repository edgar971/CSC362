#include "TestHarness.h"
#include "PersonType.h"

using namespace std;

SimpleString StringFrom(const string& value) {
	return SimpleString(value.c_str());
}

TEST(PersonType, initialTest) {
	PersonType person;
	person.setLastName("Smith");
	person.setFirstName("Mary");

	CHECK_EQUAL("Smith", person.getLastName());
	CHECK_EQUAL("Mary", person.getFirstName());


}

TEST(PersonType, loadConstructorTest)
{
	PersonType person("Mary", "Joe", "Smith");
	CHECK_EQUAL("Smith", person.getLastName());
	CHECK_EQUAL("Mary", person.getFirstName());
	CHECK_EQUAL("Joe", person.getMiddleName());
}


TEST(PersonType, logicalNameTest)
{
	PersonType person;
	person.setLastName("Smith");
	person.setFirstName("Mary");
	LONGS_EQUAL(1, person.isLastName("Smith"));
	LONGS_EQUAL(1, person.isFirstName("Mary"));
}