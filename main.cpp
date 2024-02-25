#include "String.h"
#include <iostream>
#include <string.h>

int main() {
	String one = "Your name is $name? Are you sure your name is $name?";
	String two = "John";
	String three = "$name";
	/*String four;
	String five;
	three = one + " || " + two;
	std::cout << one << " | " << two << std::endl;
	std::cout << three << std::endl;
	std::cin >> five;
	std::cout << std::endl << five << std::endl;
	five.Wobble();
	std::cout << five << std::endl;

	std::cout << std::strstr(one.CStr(), "is");*/
	std::cout << one << std::endl;
	one.Replace(three, two);
	std::cout << one << std::endl;
}