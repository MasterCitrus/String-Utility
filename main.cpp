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

	std::ofstream file;
	file.open("log.txt", std::ios::app);

	std::chrono::zoned_time currentTime(std::chrono::current_zone(), std::chrono::system_clock::now());

	file << currentTime << std::endl;
	//LENGTH
	//Check if string length of 'testString' is equal to 22.
	CheckSuccess(testString.Length() == 22, "Length Test", file);

	//CHARACTER AT
	//Check if the character at 10 is 't'.
	CheckSuccess(testString.CharacterAt(10) == 't', "Character At Test", file);

	//EQUAL TO
	//Check if 'comp1' is equal to 'comp3'.
	CheckSuccess(comp1.EqualTo(comp3), "Equal To Test", file);

	//APPEND
	//Append 'World' to 'Hello'.
	append = lhs;
	CheckSuccess(append.Append(rhs) == "HelloWorld", "Append Test", file);

	//PREPEND
	//Prepend 'World' to 'Hello'
	prepend = lhs;
	CheckSuccess(prepend.Prepend(rhs) == "WorldHello", "Prepend Test", file);

	//TO LOWER
	//Check if string is converted to all lowercase
	lower = testString;
	CheckSuccess(testString.ToLower() == "this is a test string.", "To Lower Test", file);

	//TO UPPER
	//Check if string is converted to all uppercase
	upper = testString;
	CheckSuccess(testString.ToUpper() == "THIS IS A TEST STRING.", "To Upper Test", file);

	//FIND
	//Find the string 'TEST' at index 10.
	size_t loc = 10;
	CheckSuccess(testString.Find(find) == loc, "Find Test", file);

	//REPLACE
	//Check if filler words were replaced with John.
	CheckSuccess(sentence.Replace(findR, replace) == "Your name is John? Are you sure your name is John?", "Replace Test", file);
	float result = (success * 100) / tests;

	file << result << "% Successful" << std::endl << std::endl;

	std::cout << "Results logged to file.\n";

	std::cout << std::endl << "Press 'Enter' to exit.";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
}