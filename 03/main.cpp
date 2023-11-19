#include <iostream>
#include "H.h"



int main() {
	
	name();

	int target_value = random_value(); // сохраняем в переменную сгенерированное число

	do {
		std::cin >> current_value;
		attempts++; //после ввода числа увеличиваем счетчик попыток

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			std::cout << "Your attempts:" << attempts << std::endl; // вывод  количества попыток
			break;
		}

	} while (true);


	 record();

	 reading();


	return 0;
}