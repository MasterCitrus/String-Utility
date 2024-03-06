#include "String.h"

#include <iostream>
#include <fstream>
#include <chrono>

float tests;
float success;
float fail;

static bool CheckSuccess(bool expression, const char* message) {
	tests++;
	if (!expression) {
		std::cout << "Test " << tests << " | " << message << " | Failed" << std::endl;
		fail++;
		return false;
	}
	else {
		std::cout << "Test " << tests << " | " << message << " | Succeeded" << std::endl;
		success++;
		return true;
	}
}

static bool CheckSuccess(bool expression, const char* message, std::ofstream &file) {
	tests++;
	if (!expression) {
		file << "Test " << tests << " | " << message << " | Failed" << std::endl;
		fail++;
		return false;
	}
	else {
		file << "Test " << tests << " | " << message << " | Succeeded" << std::endl;
		success++;
		return true;
	}
}

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
	String find = "TEST";
	String input;

	//LENGTH
	int i = rand() % testString.Length();
	std::cout << i << std::endl;
	CheckSuccess(testString.Length() == i, "Length Test");

	//CHARACTER AT
	size_t caIndex = rand() % testString.Length();
	CheckSuccess(testString.CharacterAt(caIndex) == 't', "Character At Test");
	std::cout << testString[caIndex];

	//EQUAL TO
	CheckSuccess(comp1.EqualTo(comp3), "Equal To Test");

	//APPEND
	append = lhs;
	CheckSuccess(append.Append(rhs) == "HelloWorld", "Append Test");

	//PREPEND
	prepend = lhs;
	CheckSuccess(prepend.Prepend(rhs) == "WorldHello", "Prepend Test");

	//CSTR
	CheckSuccess(testString.CStr() == "This is a test string.", "CStr Test");

	//TO LOWER
	lower = testString;
	CheckSuccess(testString.ToLower() == "this is a test string.", "To Lower Test");

	//TO UPPER
	upper = testString;
	CheckSuccess(testString.ToUpper() == "THIS IS A TEST STRING.", "To Upper Test");

	//FIND
	size_t loc = 10;
	CheckSuccess(testString.Find(find) == loc, "Find Test");

	//REPLACE
	CheckSuccess(sentence.Replace(findR, replace) == "Your name is John? Are you sure your name is John?", "Replace Test");
	float result = (tests * success) / 100 * 100;

	std::cout << result << "% Successful" << std::endl << std::endl;
}