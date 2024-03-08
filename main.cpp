#include "String.h"

int main() {
	String string = "Hello World!";
	std::cout << string << std::endl;

	std::cout << "\nPress 'Enter' to exit.";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
}