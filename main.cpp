#include "String.h"
#include <iostream>
#include <string>

int main() {
	String one = "This is a test string";
	one.Wobble();
	std::cout << one.CStr();
}