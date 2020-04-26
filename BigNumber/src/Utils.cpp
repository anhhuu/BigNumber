#include "Utils.h"
#include <string>
std::string Utils::AddTwoIntString(std::string num1, std::string num2)
{
	std::string result = "";
	int reminder = 0;
	int pointerNum1 = num1.length() - 1;
	int pointerNum2 = num2.length() - 1;
	int resultOfAddingTwoNum = 0;

	while (pointerNum1 >= 0 && pointerNum2 >= 0) {
		resultOfAddingTwoNum = num1[pointerNum1] + num2[pointerNum2] + reminder - 2 * 48;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum1--;
		pointerNum2--;

	}
	while (pointerNum1 >= 0) {
		resultOfAddingTwoNum = num1[pointerNum1] - 48 + reminder;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum1--;



	}
	while (pointerNum2 >= 0) {
		resultOfAddingTwoNum = num2[pointerNum2] - 48 + reminder;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum2--;


	}
	if (reminder != 0) {
		std::string s = "";
		s += reminder + 48;

		result.insert(0, s);
	}



	return result;
	return std::string();
}

std::string Utils::DivideNumStringForTwo(std::string num)
{
	return std::string();
}

std::string Utils::MultiplyNumStringWithOneDigit(std::string num1, int num2)
{
	int r = 0;
	std::string q = "";

	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int k = (int)(num1[i] - '0');
		int temp = (k * num2) + r;

		if (temp > 9) 
		{
			r = temp / 10;
			temp = temp % 10;
			q = std::to_string(temp) + q;
		}
		else {
			q = std::to_string(temp) + q;
			r = 0;
		}
	}
	if (r > 0) 
		q = std::to_string(r) + q;

	return std::string(q);
}

std::string Utils::MultiplyNumString(std::string num1, std::string num2)
{
	std::string q = "";
	std::string zero = "";
	for (int i = num1.length() - 1; i >= 0; i--) {
		int k = (int)(num1[i] - '0');

		std::string temp = Utils::MultiplyNumStringWithOneDigit(num2, k) + zero;

		zero = zero + "0";

		q = AddTwoIntString(q, temp);
		
	}
	return std::string(q);
}

std::string Utils::PowOneDigit(int factor, int exp)
{
	return std::string();
}

