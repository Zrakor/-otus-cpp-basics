#include <iostream>

#include <cstdlib>
#include <ctime>

int random_value() {

	std::srand(static_cast<int>(std::time(nullptr))); // use current time as seed for random generator

	return std::rand() % 100;
}