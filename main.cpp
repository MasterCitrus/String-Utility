#include "String.h"
#include <string.h>
#include <iostream>

int main() {
	srand(time(nullptr));
	String testString = "This is a test string.";
	String sentence = "Your name is $name? Are you sure your name is $name?";
	String replace = "John";
	String findR = "$name";
	String comp1 = "Same";
	String comp2 = "Not Same";
	String comp3;
	comp3 = comp1;
	String lhs = "Hello";
	String rhs = "World";
	String append;
	String prepend;
	String lower;
	String upper;
	String find = "test";
	String input;


	std::cout << std::boolalpha;
	//LENGTH
	std::cout << "LENGTH TEST" << std::endl;
	std::cout << testString << std::endl;
	std::cout << "Length is " << testString.Length() << std::endl << std::endl;

	//CHARACTER AT
	size_t caIndex = rand() % testString.Length();
	std::cout << "CHARACTER AT TEST" << std::endl;
	std::cout << "Character at " << caIndex << ": " << testString.CharacterAt(caIndex) << std::endl << std::endl;;

	//EQUAL TO
	std::cout << "EQUAL TO TEST" << std::endl;
	std::cout << "Is String 1: " << comp1 << " equal to " << "String 2: " << comp3 << " ?" << std::endl;
	std::cout << comp1.EqualTo(comp3) << std::endl;
	std::cout << "Is String 1: " << comp1 << " equal to " << "String 2: " << comp2 << " ?" << std::endl;
	std::cout << comp1.EqualTo(comp2) << std::endl << std::endl;

	//APPEND
	std::cout << "APPEND TEST" << std::endl;
	std::cout << "Append " << rhs << " to " << lhs << std::endl;
	append = lhs;
	append.Append(rhs);
	std::cout << append << std::endl << std::endl;

	//PREPEND
	std::cout << "PREPEND TEST" << std::endl;
	std::cout << "Prepend " << rhs << " to " << lhs << std::endl;
	prepend = lhs;
	prepend.Prepend(rhs);
	std::cout << prepend << std::endl << std::endl;

	//CSTR
	std::cout << "CSTR TEST" << std::endl;
	std::cout << testString.CStr() << std::endl << std::endl;;

	//TO LOWER
	std::cout << "TO LOWER TEST" << std::endl;
	lower = testString;
	std::cout << lower << std::endl;
	lower.ToLower();
	std::cout << lower << std::endl << std::endl;

	//TO UPPER
	std::cout << "TO UPPER TEST" << std::endl;
	upper = testString;
	std::cout << upper << std::endl;
	upper.ToUpper();
	std::cout << upper << std::endl << std::endl;

	//FIND
	caIndex = rand() % testString.Length();
	size_t fIndex = testString.Find(caIndex, find);
	std::cout << "FIND TEST" << std::endl;
	std::cout << "The string " << find << " starts at index " << testString.Find(find) << std::endl;
	std::cout << "Starting Find() from index " << caIndex << std::endl;
	if (fIndex != -1) {
		std::cout << "The string " << find << " starts at index " << testString.Find(caIndex, find) << std::endl << std::endl;
	}
	else {
		std::cout << "Find() could not find the string after " << caIndex << std::endl << std::endl;
	}

	
}