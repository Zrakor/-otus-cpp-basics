#include <iostream>
#include <fstream>
#include <string>
#include "random_value.h"

int main() {

	const std::string high_scores_filename = "high_scores.txt";

	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	int target_value = random_value(); // сохраняем в переменную сгенерированное число
	int current_value = 0; // вводимое пользователем число
	int attempts = 0; // количество попыток


	std::cout << "Enter your guess:" << std::endl;

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

	// Write new high score to the records table
	{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		// Append new results to the table:
		out_file << user_name << ' ';
		out_file << attempts;
		out_file << std::endl;
	} // end of score here just to mark end of the logic block of code

	// Read the high score file and print all results
	{
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> attempts;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << attempts << std::endl;
		}
	}

	return 0;
}