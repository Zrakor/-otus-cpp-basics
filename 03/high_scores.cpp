#include <iostream>
#include <fstream>


extern int attempts;

const std::string high_scores_filename = "high_scores.txt";
std::string user_name;

void  name() {

	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::cin >> user_name;
	std::cout << "Enter your guess:" << std::endl;
}

	
void record() {
	
	std::ofstream out_file{ high_scores_filename, std::ios_base::app };
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
	}

	// Append new results to the table:
	out_file << user_name << ' ';
	out_file << attempts;
	out_file << std::endl;
}

	
	void reading() {
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
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