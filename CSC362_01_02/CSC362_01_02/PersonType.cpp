#include "PersonType.h"


PersonType::PersonType() {
	_firstName = "";
	_middleName = "";
	_lastName = "";

}
PersonType::PersonType(string first, string middle, string last) {
	_firstName = first;
	_middleName = middle;
	_lastName = last;

}

void PersonType::print() const {
	cout << _firstName << " " << _middleName << " " << _lastName << endl;

}

void PersonType::setName(string first, string middle, string last) {
	_firstName = first;
	_middleName = middle;
	_lastName = last;

}

void PersonType::setLastName(string last) {
	_lastName = last;
}

void PersonType::setMiddleName(string middle) {
	_middleName = middle;
}

void PersonType::setFirstName(string first) {
	_firstName = first;
}

bool PersonType::isFirstName(string first) const {
	if (_firstName == first) {
		return true;
	}
	else {
		return false;
	}
}

bool PersonType::isLastName(string last) const {
	if (_lastName == last) {
		return true;
	}
	else {
		return false;
	}
}

string PersonType::getFirstName() const {
	return _firstName;
}

string PersonType::getMiddleName() const {
	return _middleName;
}
string PersonType::getLastName() const {
	return _lastName;
}





PersonType::~PersonType() {
	_firstName = " ";
	_middleName = " ";
	_lastName = " ";
}
