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

	unsigned int index = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		index++;
	}
	unsigned int dividendNum = 0;
	unsigned int surplus = 0;
	unsigned int resultTemp = 0;
	std::string resultStr = "";

	while (index < num.length())
	{
		dividendNum = (dividendNum * 10) + num[index] - '0';

		resultTemp = dividendNum / 2;
		surplus = dividendNum % 2;

		if (surplus != 0)
		{
			//Du khac khong
			dividendNum = surplus;
		}
		else
		{
			//Du bang 0 
			dividendNum = 0;
		
		}
		resultStr += std::to_string(resultTemp);
		index++;
	}

	if (resultStr[0] == '0' && resultStr.length()>1)
	{
		resultStr.erase(0, 1);
	}
	return resultStr;
	
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
	std::string result = "1";

	for (int i = 0; i < exp; i++) {
		result = MultiplyNumStringWithOneDigit(result, factor);

	}
	return result;
}

