#ifndef ROMANTYPE_H
#define ROMANTYPE_H

#include <string>

using namespace std;

class RomanType {
	private: 
		string _romanNum;
		int _decimalNum;
	
	public:
		RomanType();
		~RomanType();
		RomanType(string romanNum);

		void setRoman(string romanNum);
		string getRoman() const;
		int getRomanToDecimal() const;
		int convertRomanToDecimal(string romanNum);




	
};

#endif 

