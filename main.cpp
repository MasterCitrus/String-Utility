#include "String.h"
#include <iostream>

int main() {
	String str1 = "Hello";
	String str2 = "World";

	str1.Append(str2);

	std::cout << str1.CStr() << std::endl;
}