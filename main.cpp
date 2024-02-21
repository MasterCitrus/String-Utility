#include "String.h"
#include <iostream>
#include <string>

int main() {
	String one = "This is a test string";
	String two = "A second test string";
	String three;
	String four;
	String five;
	three = one + " || " + two;
	std::cout << one << " | " << two << std::endl;
	std::cout << three << std::endl;
	std::cin >> five;
	std::cout << std::endl << "Output: " << five << std::endl;
}