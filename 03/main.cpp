#include <iostream>
#include "H.h"



int main() {
	
	name();

	int target_value = random_value(); // ��������� � ���������� ��������������� �����

	do {
		std::cin >> current_value;
		attempts++; //����� ����� ����� ����������� ������� �������

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			std::cout << "Your attempts:" << attempts << std::endl; // �����  ���������� �������
			break;
		}

	} while (true);


	 record();

	 reading();


	return 0;
}