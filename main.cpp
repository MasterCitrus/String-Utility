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

	
}