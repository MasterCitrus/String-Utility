#include "String.h"
#include <iostream>

int main() {
	String one = "One";
	String two = "Two";
	String three;
	std::cout << one.CStr() << " + " << two.CStr() << std::endl;
	three = one + two;
	std::cout << three.CStr() << std::endl;
	std::cout << one.CStr() << " " << two.CStr() << std::endl;
}