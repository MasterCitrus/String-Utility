#include "String.h"


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

String::String(AdoptPointer, char* str) : _str{str} {

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
	strncpy(_str, str._str, length);
	_str[length] = '\0';

	return *this;
}

//Member access operator [] overload
char& String::operator[](size_t index) {
	if (index > this->Length()) {
		throw std::out_of_range("Index out of range!");
	}
	return _str[index];
}

//Member access operator [] overload
const char& String::operator[](size_t index) const {
	if (index > this->Length()) {
		throw std::out_of_range("Index out of range!");
	}
	return _str[index];
}

//Arithmetic operator + overload
String String::operator+(const String& other) const {
	size_t length = this->Length() + other.Length();
	String buffer(AdoptPointer{}, new char[length + 1] {});
	strcpy(buffer._str, _str);
	strcat(buffer._str, other._str);
	return buffer;
}

//Assignment operator += overload
String& String::operator+=(const String& other) {
	size_t length = this->Length() + other.Length();
	char* str = new char[length + 1] {};
	strcpy(str, _str);
	strcat(str, other._str);
	delete[] _str;
	_str = str;
	return *this;
}

//Insertion operator << overload
std::ostream& operator<<(std::ostream& out, const String& str) {
	return out << str.CStr();
}

////Extraction operator >> overload
//std::istream& operator>>(std::istream& in, String& str) {
//	in.getline(str._str, sizeof(str._str));
//	str._str[str.Length()] = '\0';
//	return in >> str._str;
//}

//Member functions

//Get length of string.
size_t String::Length() const {
	size_t length;
	length = strlen(_str);
	return length;
}

//Finds character at specified index. Returns null if outside of index range.
char& String::CharacterAt(size_t index) {
	size_t length = this->Length();
	if (index > length) return _str[length];
	return _str[index];
}

//Finds character at specified index. Returns null if outside of index range.
const char& String::CharacterAt(size_t index) const {
	size_t length = this->Length();
	if (index > length) return _str[length];
	return _str[index];
}


//Checks if strings have the same characters. Returns true if equal; returns false if not equal.
bool String::EqualTo(const String& other) const {
	int a;
	a = strcmp(_str, other._str);

	if (a == 0) return true;
	return false;
}


//Concatenates another string to the end of the string.
String& String::Append(const String& str) {
	char* temp = _str;
	size_t length = strlen(temp) + str.Length() + 1;
	_str = new char[length];
	strcpy(_str, temp);
	strcat(_str, str._str);
	delete[] temp;

	return *this;
}

//Concatenates another string to the front of the string.
String& String::Prepend(const String& str) {
	char* temp = _str;
	size_t length = strlen(temp) + str.Length() + 1;
	_str = new char[length];
	strcpy(_str, str._str);
	strcat(_str, temp);
	delete[] temp;

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

//Finds a substring in a string and returns it's location.
size_t String::Find(const String& str) {
	
	return -1;
}

//Finds a substring from the specified index of a string and returns it's location.
size_t String::Find(size_t startIndex, const String& str) {
	
	return -1;
}

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
//Output string to console.
String& String::WriteToConsole() {
	std::cout << _str;
	return *this;
}

String& String::Wobble() {
	srand(time(nullptr));
	int r = rand() % 2;
	this->ToLower();
	if (r == 0) {
		for (int i = 0; i < this->Length(); i++) {
			_str[i] = toupper(_str[i]);
			i++;
		}
	}
	else if (r == 1) {
		for (int i = 1; i < this->Length(); i++) {
			_str[i] = toupper(_str[i]);
			i++;
		}
	}

	return *this;
}