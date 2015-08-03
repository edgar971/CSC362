#include <iostream>
#include <string>
#include "RomanType.h"
#include <map>

RomanType::RomanType() {
	_romanNum = "I";
	_decimalNum = 1;
}

RomanType::~RomanType() {

}

RomanType::RomanType(string romanNum) {
	_romanNum = romanNum;
	_decimalNum = convertRomanToDecimal(romanNum);
}

int RomanType::getRomanToDecimal() const {
	return _decimalNum;
}

string RomanType::getRoman() const {
	return _romanNum;
}

void RomanType::setRoman(string romanNum) {
	_romanNum = romanNum;
	convertRomanToDecimal(romanNum);
	
}

int RomanType::convertRomanToDecimal(string romanNum) {
	//not sure if there is an easier way to do this
	map<char, int> roman;
	roman['M'] = 1000;
	roman['D'] = 500;
	roman['C'] = 100;
	roman['L'] = 50;
	roman['X'] = 10;
	roman['V'] = 5;
	roman['I'] = 1;
	int sum = 0;
 	for (int i = 0; i < romanNum.length() - 1; ++i)
	{
		if (roman[romanNum[i]] < roman[romanNum[i + 1]])
			sum -= roman[romanNum[i]];
		else
			sum += roman[romanNum[i]];
	}
	sum += roman[romanNum[romanNum.size() - 1]];
 

	_decimalNum = sum;
	return sum;
}