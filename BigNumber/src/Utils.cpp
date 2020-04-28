#include "Utils.h"

std::string Utils::AddTwoIntString(std::string num1, std::string num2)
{
	return std::string();
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
			dividendNum = surplus;
		}
		else
		{
			dividendNum = 0;
		}
		resultStr += std::to_string(resultTemp);
		index++;
	}

	if (resultStr[0] == '0' && resultStr.length() > 1)
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
	return std::string();
}
