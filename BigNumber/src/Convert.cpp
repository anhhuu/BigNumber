#include "Convert.h"

std::string Convert::CovertNumStringToBin(std::string num)
{
	std::string quotient = num;

	std::string binResult = "";
	do {
		if ((quotient[quotient.length() - 1] - '0') % 2 == 0) {

			binResult.insert(0,std::to_string(0));

		}
		else if ((quotient[quotient.length() - 1] - '0') % 2 == 1) {

			binResult.insert(0,std::to_string(1));

		}
		quotient = Utils::DivideNumStringForTwo(quotient);


	} while (quotient != "0");

	int length = binResult.length();
	int numberOfZeros = 128 - length;
	for (int i = 0; i < numberOfZeros; i++) {
		binResult.insert(0, "0");
	}
	length = binResult.length();

	if (num[0] == '-') {

		//Thực hiện đảo bit
		for (int i = 0; i < length; i++) {
			binResult[i] = binResult[i] == '0' ? '1' : '0';
		}

		int reminder = 1;
		for (int i = binResult.length() - 1; i >= 0; i--) {

			int result = binResult[i] - '0' + reminder;
			reminder = result / 2;
			result = result % 2;

			binResult[i] = (char)(result + '0');

			if (reminder == 0) break;
		}
		
		binResult[0] = '1';

	}
	else {
		binResult[0] = '0';
	}
	
	

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
			if (bits[index] == '1' && index == 0) {
				index++;
				continue;
			}
			else {
				decResult = Utils::AddTwoIntString(decResult, Utils::PowOneDigit(2, exp));
			}
			
		}
		
		index++;
	}

	if (bits[0] == '1') {
		decResult = Utils::SubtractTwoSNumString(decResult, Utils::PowOneDigit(2, length - 1));

	}

	return decResult;

}
