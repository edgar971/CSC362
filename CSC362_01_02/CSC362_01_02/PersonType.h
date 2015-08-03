#ifndef PERSONTYPE_H
#define PERSONTYPE_H
#include <string>
#include <iostream>

using namespace std;

class PersonType {
	private: 
		string _firstName;
		string _middleName;
		string _lastName;
	public:
		PersonType();
		PersonType(string first, string midde, string last);
		void print() const;
		void setName(string first, string midde, string last);
		void setLastName(string last);
		void setFirstName(string first);
		void setMiddleName(string middle);
		bool isLastName(string last) const;
		bool isFirstName(string last) const ;
		string getFirstName() const;
		string getMiddleName() const;
		string getLastName() const;




		~PersonType();
};

#endif 