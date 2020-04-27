#include <iostream>
#include "Qint.h"
#include "Qfloat.h"
#include "Utils.h"
#include "Convert.h"
#include "BitProcess.h"
#include "Utils.h"
#include <time.h>
#include <bitset>
void TestCaseSubtract() {
	int num1 = 0;
	int num2 = 0;
	bool pass = true;

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		
		num1 = rand() % 500;
		num2 = rand() % 1000;

		
		std::cout << "Thuc hien: " << num1 << " - " << num2 << std::endl;
		std::cout << "Ket qua dung: " << num1 - num2 << std::endl;
		std::cout << "Ket qua ham: " << Utils::SubtractTwoSNumString(std::to_string(num1), std::to_string(num2))<<std::endl;
		if (std::to_string(num1 - num2) !=
			Utils::SubtractTwoSNumString(std::to_string(num1), std::to_string(num2))) {
			std::cout << "failed" << std::endl;
			return;

		}
		
	}

	std::cout << "Pass";

}
void TestCaseConvert() {

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		int number = rand()%3000-1000;		
		std::cout << number << std::endl;
		std::string bits = Convert::CovertNumStringToBin(std::to_string(number));
		std::string numberStr = Convert::CovertBinToNumString(bits);
	

		if (std::to_string(number) != numberStr) {
			std::cout << "Failed"; return;
		}
	}

	std::cout << "Passed";
}
int main()
{

	TestCaseConvert();

	system("pause");
	return 0;
}