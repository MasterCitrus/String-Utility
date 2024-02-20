#pragma once
class String {
public:

	String();
	String(const char* str);
	String(const String& other);

	~String();

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

	bool operator==(const String& other);
	bool operator!=(const String& other);
	String& operator=(const String& str);
	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	String operator+(const String& other);
	String& operator+=(const String& other);

private:
	char* _str;
};
