#include <iostream>
#include <string>
#include "RomanType.h"
#include "TestHarness.h"

using namespace std;

SimpleString StringFrom(const string& value) {
	return SimpleString(value.c_str());
}

TEST(RomanType, initialTest) {
	RomanType roman;

	LONGS_EQUAL(1, roman.getRomanToDecimal());
	LONGS_EQUAL(1000, roman.convertRomanToDecimal("M"));
	LONGS_EQUAL(500, roman.convertRomanToDecimal("D"));
	LONGS_EQUAL(100, roman.convertRomanToDecimal("C"));
	LONGS_EQUAL(50, roman.convertRomanToDecimal("L"));
	LONGS_EQUAL(5, roman.convertRomanToDecimal("V"));
	LONGS_EQUAL(1, roman.convertRomanToDecimal("I"));
	CHECK_EQUAL("I", roman.getRoman());


}

TEST(RomanType, testGetterSetter) {
	RomanType roman;
	roman.setRoman("VI");
	LONGS_EQUAL(6, roman.getRomanToDecimal());
	CHECK_EQUAL("VI", roman.getRoman());
}

TEST(RomanType, testComplexNumbers) {
	RomanType roman("XXI");
	LONGS_EQUAL(21, roman.getRomanToDecimal());
	LONGS_EQUAL(36, roman.convertRomanToDecimal("XXXVI"));
	LONGS_EQUAL(1114, roman.convertRomanToDecimal("MCXIV"));
	LONGS_EQUAL(359, roman.convertRomanToDecimal("CCCLIX"));
	LONGS_EQUAL(1666, roman.convertRomanToDecimal("MDCLXVI"));
	CHECK_EQUAL("XXI", roman.getRoman());

}


