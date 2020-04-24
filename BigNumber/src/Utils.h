#pragma once
#include <string>

class Utils
{
public:
	//add tưo number string
	//return a string result
	static std::string AddTwoIntString(std::string num1, std::string num2);

	//divide number string for two
	//return a string result
	static std::string DivideNumStringForTwo(std::string num);

	//multiply number string with number one digit
	//return a string result
	static std::string MultiplyNumStringWithOneDigit(std::string num1, int num2);

	//multiply two number string
	//return a string result
	static std::string MultiplyNumString(std::string num1, std::string num2);

	//pow a number with exp
	//return a number string
	static std::string PowOneDigit(int factor, int exp);
};