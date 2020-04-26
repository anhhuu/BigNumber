#include "Convert.h"

std::string Convert::CovertNumStringToBin(std::string num)
{
	std::string binResult = "";
	

	do {
		if ((num[num.length() - 1] - '0') % 2 == 0) {

			binResult.insert(0,std::to_string(0));

		}
		else if ((num[num.length() - 1] - '0') % 2 == 1) {

			binResult.insert(0,std::to_string(1));

		}
		num = Utils::DivideNumStringForTwo(num);


	} while (num != "0");
	

	return binResult;
}

std::string Convert::CovertBinToNumString(std::string bits)
{
	int index = 0;
	std::string decResult = "0";
	int length = bits.length();

	while (index < length) {
		
		int exp = length - 1 - index;
		if (bits[index] == '1') {
			decResult = Utils::AddTwoIntString(decResult, Utils::PowOneDigit(2, exp));
		}
		
		index++;
	}
	return decResult;

}
