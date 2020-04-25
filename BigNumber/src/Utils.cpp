#include "Utils.h"

std::string Utils::AddTwoIntString(std::string num1, std::string num2)
{
	std::string result = "";
	int reminder = 0;
	int pointerNum1 = num1.length()-1;
	int pointerNum2 = num2.length()-1;
	int resultOfAddingTwoNum = 0;

	while (pointerNum1>= 0 && pointerNum2>= 0) {
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
}


short Utils::StringToShort(std::string input)
{
	short result = 0;
	for (int i = 0; i < input.length(); i++) {
		result = result * 10 + input[i] - 48;
	}
	return result;
}
std::string Utils::DivideNumStringForTwo(std::string num)
{

	if (num.length() <= 0) return nullptr;
	int index = 0;
	bool hasSign = false;


	if (num[0] == '+' || num[0] == '-') {
		index++;
		hasSign = true;
	}

	std::string currentNumber = "";
	std::string quotient = "";


	for (; index < num.length(); index++) {

		currentNumber += num[index];

		int kq = StringToShort(currentNumber) / 2;
		char kqConverted = kq + 48;

		if (!((index == 0 && hasSign == false && kqConverted == '0') ||
			(index == 1 && hasSign && kqConverted == '0'))) {
			quotient += kqConverted;

		}

		int remainder = StringToShort(currentNumber) % 2;

		if (remainder == 1) {
			currentNumber = "1";
		}
		else {
			currentNumber = "";
		}

	}


	if (num[0] == '-') {
		quotient.insert(0, "-");
	}




	return quotient;
	
}

std::string Utils::MultiplyNumStringWithOneDigit(std::string num1, int num2)
{
	return std::string();
}

std::string Utils::MultiplyNumString(std::string num1, std::string num2)
{
	return std::string();
}

std::string Utils::PowOneDigit(int factor, int exp)
{
	return std::string();
}

