#pragma once
#include <iostream>

class String {
public:
	//Constructors
	String();
	String(const char* str);
	String(const String& other);

	//Destructor
	~String();

	//Member Functions
	size_t Length() const;
	char& CharacterAt(size_t index);
	const char& CharacterAt(size_t index) const;
	bool EqualTo(const String& other) const;
	String& Append(const String& str);
	String& Prepend(const String& str);
	const char* CStr() const;
	String& ToLower();
	String& ToUpper();
	size_t Find(const String& str);
	size_t Find(size_t startIndex, const String& str);
	String& Replace(const String& find, const String& replace);
	String& ReadFromConsole();
	String& WriteToConsole();

	String& Wobble();

	//Overloads
	bool operator==(const String& other);
	bool operator!=(const String& other);
	String& operator=(const String& str);
	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	String operator+(const String& other) const;
	String& operator+=(const String& other);
	friend std::ostream& operator<<(std::ostream& out, const String& str);
	friend std::istream& operator>>(std::istream& in, String& str);

private:
	char* _str;
	enum class AdoptPointer {};
	String(AdoptPointer, char* str);
};
