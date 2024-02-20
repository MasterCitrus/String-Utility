#include "String.h"
#include <iostream>

//Constructors + destructors

//Default constructor.
String::String() : _str{ nullptr } {
	_str = new char[1];
	_str[0] = '\0';
}

//Single parameter constructor.
String::String(const char* str) {
	size_t length = strlen(str);
	if (str == nullptr) {
		_str = new char[1];
		_str[0] = '\0';
	}

	else {
		_str = new char[length + 1];

		strncpy(_str, str, length);

		_str[length] = '\0';
	}
}

//Copy constructor.
String::String(const String& other) {
	_str = new char[other.Length() + 1];

	for (int i = 0; i < other.Length(); i++) {
		_str[i] = other._str[i];
	}

	_str[String::Length()] = '\0';
}

//Destructor
String::~String() {
	delete _str;
}

//Operator overloads

//Equal to comparison operator == overload
bool String::operator==(const String& other) {
	int a;
	a = strcmp(_str, other._str);

	if (a == 0) return true;
	return false;
}

//Not equal to comparison operator != overload
bool String::operator!=(const String& other) {
	int a;
	a = strcmp(_str, other._str);

	if (a == 0) return false;
	return true;
}

//Assignment operator = overload
String& String::operator=(const String& str) {
	delete[] _str;
	size_t length = str.Length();
	_str = new char[length + 1];
	strcpy(_str, str._str);
	_str[length] = '\0';

	return *this;
}

//Member access operator [] overload
char& String::operator[](size_t index) {
	if (index < 0 || index > String::Length() - 1) {
		throw std::out_of_range("Index out of range!");
	}
	return _str[index];
}

//Member access operator [] overload
const char& String::operator[](size_t index) const {
	if (index < 0 || index > String::Length() - 1) {
		throw std::out_of_range("Index out of range!");
	}
	return _str[index];
}

//Arithmetic operator + overload
String String::operator+(const String& other) {
	size_t length = this->Length() + other.Length();
	String buffer = new char[length + 1];
	strcpy(buffer._str, _str);
	strcat(buffer._str, other._str);
	buffer._str[length] = '\0';
	return buffer;
}

//Assignment operator += overload
String& String::operator+=(const String& other) {
	String buffer = new char[this->Length() + 1];
	strcpy(buffer._str, _str);
	size_t length = this->Length() + other.Length();
	_str = new char[length + 1];
	strcpy(_str, buffer._str);
	strcat(_str, other._str);
	_str[length] = '\0';
	return *this;
}

//Member functions

//Get length of string.
size_t String::Length() const {
	size_t length;
	length = strlen(_str);
	return length;
}

//Finds character at specified index.
char& String::CharacterAt(size_t index) {
	return _str[index];
}

//Finds character at specified index.
const char& String::CharacterAt(size_t index) const {
	return _str[index];
}


//Checks if strings have the same characters.
bool String::EqualTo(const String& other) const {
	int a;
	a = strcmp(_str, other._str);

	if (a == 0) return true;
	return false;
}


//Concatenate string to the back.
String& String::Append(const String& str) {
	char* temp = _str;
	size_t length = strlen(temp) + str.Length() + 1;
	_str = new char[length];
	strcpy(_str, temp);
	strcat(_str, str._str);
	delete[] temp;
	_str[length] = '\0';

	return *this;
}

//Concatenate string to the front.
String& String::Prepend(const String& str) {
	char* temp = _str;
	size_t length = strlen(temp) + str.Length() + 1;
	_str = new char[length];
	strcpy(_str, str._str);
	strcat(_str, temp);
	delete[] temp;
	_str[length] = '\0';

	return *this;
}

//Return char array for console.
const char* String::CStr() const {
	return _str;
}

//Returns string with all characters in lower case.
String& String::ToLower() {
	for (int i = 0; i < this->Length(); i++) {
		this->_str[i] = std::tolower(this->_str[i]);
	}

	return *this;
}

//Returns string with all characters in upper case.
String& String::ToUpper() {
	for (int i = 0; i < this->Length(); i++) {
		this->_str[i] = std::toupper(this->_str[i]);
	}

	return *this;
}

////Find string.
//size_t String::Find(const String& str) {
//
//}
//
////Find string from the specified index.
//size_t String::Find(size_t startIndex, const String& str) {
//
//}
//
////Replace all occurences of the first string with the second string.
//String& String::Replace(const String& find, const String& replace) {
//
//}
//
////Convert input from console to string.
//String& String::ReadFromConsole() {
//
//}
//
////Output string to console.
//String& String::WriteToConsole() {
//
//}