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
	if (str == nullptr) {
		_str = new char[1];
		_str[0] = '\0';
	}

	else {
		_str = new char[strlen(str) + 1];

		strcpy(_str, str);

		_str[strlen(str)] = '\0';
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

//Member functions

//Get length of string.
size_t String::Length() const {
	size_t length;
	length = strlen(_str);
	return length;
}

//Finds character at specified index.
char& String::CharacterAt(size_t index) {
	
}

//Finds character at specified index.
const char& String::CharacterAt(size_t index) const {

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
	
}

//Concatenate string to the front.
String& String::Prepend(const String& str) {

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
}

//Returns string with all characters in upper case.
String& String::ToUpper() {
	for (int i = 0; i < this->Length(); i++) {
		this->_str[i] = std::toupper(this->_str[i]);
	}
}

//Find string.
size_t String::Find(const String& str) {

}

//Find string from the specified index.
size_t String::Find(size_t startIndex, const String& str) {

}

//Replace all occurences of the first string with the second string.
String& String::Replace(const String& find, const String& replace) {

}

//Convert input from console to string.
String& String::ReadFromConsole() {

}

//Output string to console.
String& String::WriteToConsole() {

}

