#include "Convert.h"
#include "BitProcess.h"

std::string Convert::CovertNumStringToBin(std::string num)
{
	std::string quotient = num;

	std::string bitsResult = "";
	do {
		if ((quotient[quotient.length() - 1] - '0') % 2 == 0) {

			bitsResult.insert(0,std::to_string(0));

		}
		else if ((quotient[quotient.length() - 1] - '0') % 2 == 1) {

			bitsResult.insert(0,std::to_string(1));

		}
		quotient = Utils::DivideNumStringForTwo(quotient);


	} while (quotient != "0");

	int length = bitsResult.length();
	int numberOfZeros = 128 - length;
	for (int i = 0; i < numberOfZeros; i++) {
		bitsResult.insert(0, "0");
	}
	length = bitsResult.length();

	if (num[0] == '-') {

		BitProcess::ReverseBits(bitsResult);


		int reminder = 1;
		for (int i = bitsResult.length() - 1; i >= 0; i--) {

			int result = bitsResult[i] - '0' + reminder;
			reminder = result / 2;
			result = result % 2;

			bitsResult[i] = (char)(result + '0');

			if (reminder == 0) break;
		}
		
		bitsResult[0] = '1';

	}
	else {
		bitsResult[0] = '0';
	}
	
	

	return bitsResult;
}

std::string Convert::CovertBinToNumString(std::string bits)
{
	int index = 0;
	std::string decResult = "0";
	int length = bits.length();
	bool isNegativeNumber = bits[0] == '1';
	
	//Nếu kết quả phép chuyển là số âm chuyển về bit của số dương để thực hiện tính toán nhanh hơn
	if (isNegativeNumber) {
		
		int index = bits.length() - 1;
		int reminder = 1;

		//Trừ bits cho 1
		while (index >= 0) {
			

			int tempResult = bits[index] -'0' - reminder;
			if (tempResult == 0) {
				bits[index] = '0';
				break;
			}
			else if (tempResult == -1) {
				bits[index] = '1';
				reminder = 1;
			}

			index--;
		}

		BitProcess::ReverseBits(bits);

		bits[0] = '0';

	}


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

	if (isNegativeNumber) {
		decResult.insert(0, "-");
	}

	return decResult;

}
