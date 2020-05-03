#include "Convert.h"
#include <algorithm>
#include "Convert.h"
#include "Utils.h"
#include "BitProcess.h"

#define SIGNIFICANT 112
#define MAX_EXP 16383

std::string Convert::CovertNumStringToBin(std::string num, unsigned int numOfBits)
{
	std::string result;
	unsigned int index = 0;
	bool negative = num[0] == '-';

	while (num != "0")
	{
		result += std::to_string((num[num.length() - 1] - '0') % 2);
		num = Utils::DivideNumStringForTwo(num);
	}

	std::reverse(result.begin(), result.end());

	BitProcess::StandardBits(result, numOfBits);

	if (negative)
	{
		ConvertBitsToTwoComplement(result, true);
	}

	return result;
}

std::string Convert::CovertBinToNumString(std::string bits)
{
	int index = 0;
	std::string decResult = "0";
	int length = bits.length();
	bool isNegativeNumber = bits[0] == '1';

	//Nếu kết quả phép chuyển là số âm chuyển về bit của số dương để thực hiện tính toán nhanh hơn
	if (isNegativeNumber)
	{
		ConvertBitsToTwoComplement(bits, true);
	}

	bool sign = false;

	while (index < length)
	{
		int exp = length - 1 - index;
		if (bits[index] == '1') {
			if (bits[index] == '1' && index == 0)
			{
				sign = true; //Sau khi đảo chuyển từ bù 2 về dạng nhị phân bình thường vẫn còn bit dấu thì lưu giá trị cờ
				index++;
				continue;
			}
			else
			{
				decResult = Utils::AddTwoIntString(decResult, Utils::PowOneDigit(2, exp));
			}
		}

		index++;
	}

	if (sign)
	{
		decResult = Utils::SubtractTwoSNumString(decResult, Utils::PowOneDigit(2, 127));
		//Trường hợp số nhỏ nhất -2^127
	}
	else if (isNegativeNumber)
	{
		decResult.insert(0, "-");
	}

	return decResult;

}

std::string Convert::ConvertDecPartToBin(std::string decPart, unsigned int& countBitsBeforeOne, const bool& isIntPartDiffZero = true)
{
	std::string result;
	std::string num = "1";

	int index = 0;
	int len = 0;
	int pos = 0;
	int i = 0;
	// xử lí số "0123" -> "123"
	pos = decPart.find_first_not_of('0', 0);
	int countFirstZero = pos;
	if (pos == -1)
		return "0";
	decPart = decPart.substr(pos, decPart.length() - pos);

	len = decPart.length();
	num = num.insert(1, len + countFirstZero, '0');

	if (isIntPartDiffZero)
	{
		while (i < SIGNIFICANT)
		{
			decPart = Utils::MultiplyNumStringWithOneDigit(decPart, 2);
			if (decPart.length() < len + countFirstZero + 1)
			{
				result.append(1, '0');
			}
			else
			{
				result.append(1, '1');

				if (decPart == num)
					break;
				decPart.erase(0, 1);
				pos = decPart.find_first_not_of('0', 0);
				if (pos > 0)
					decPart = decPart.substr(pos, decPart.length() - pos);
			}
			i++;
		}
		return result;
	}
	else
	{
		bool isOne = false;
		unsigned int firstPosOne = -1;
		unsigned int countBitsAfterOne = 0;
		while (!isOne && countBitsBeforeOne < MAX_EXP + SIGNIFICANT)
		{
			decPart = Utils::MultiplyNumStringWithOneDigit(decPart, 2);
			if (decPart.length() < len + countFirstZero + 1)
			{
				//result.append(1, '0');
				countBitsBeforeOne++;
			}
			else
			{
				result.append(1, '1');
				unsigned int firstPosOne = countBitsBeforeOne;
				isOne = true;

				if (decPart == num)
					return result;
				decPart.erase(0, 1);
				pos = decPart.find_first_not_of('0', 0);
				if (pos > 0)
					decPart = decPart.substr(pos, decPart.length() - pos);
			}
		}

		while (countBitsAfterOne < SIGNIFICANT - 1 && countBitsBeforeOne < MAX_EXP + SIGNIFICANT)
		{
			decPart = Utils::MultiplyNumStringWithOneDigit(decPart, 2);
			if (decPart.length() < len + countFirstZero + 1)
			{
				result.append(1, '0');
			}
			else
			{
				result.append(1, '1');

				if (decPart == num)
					break;
				decPart.erase(0, 1);
				pos = decPart.find_first_not_of('0', 0);
				if (pos > 0)
					decPart = decPart.substr(pos, decPart.length() - pos);
			}
			countBitsAfterOne++;
		}
		return result;
	}
}

std::string Convert::ConvertFloatToBin(std::string floatNum)
{
	std::string result;
	unsigned int index = 0;
	bool negative = floatNum[0] == '-';

	if (negative)
	{
		floatNum.erase(0, 1);
		result.insert(0, "1");
	}
	else
	{
		result.insert(0, "0");
	}

	unsigned int countBitBeforeOne = 0;
	unsigned int pos = floatNum.find_first_of('.', 0);

	std::string intPart = floatNum.substr(0, pos);

	if (intPart != "0")
		intPart = CovertNumStringToBin(intPart, 129);

	std::string decPart = floatNum.substr(pos + 1, floatNum.length() - 1 - pos);

	const int K = 16383;

	std::string exponent;

	if (intPart != "0")
	{
		decPart = ConvertDecPartToBin(decPart, countBitBeforeOne);
		unsigned int firstOne = intPart.find_first_of('1', 0);
		intPart = intPart.substr(firstOne + 1, intPart.length() - firstOne - 1);

		int exp = intPart.length();
		if (exp >= MAX_CELL * BITS_OF_CELL)
		{
			exponent = std::string(15, '1');
			result += exponent + std::string(112, '0');
			return result;
		}

		exponent = CovertNumStringToBin(std::to_string(exp + K), 15);

		floatNum = intPart + decPart;
		if (floatNum.length() < SIGNIFICANT)
		{
			floatNum += std::string(SIGNIFICANT - intPart.length() - decPart.length(), '0');
		}
	}
	else
	{
		decPart = ConvertDecPartToBin(decPart, countBitBeforeOne, false);
		int exp = countBitBeforeOne + 1;
		exp = -exp + K;
		exponent = CovertNumStringToBin(std::to_string(exp), 15);

		decPart.erase(0, 1);
		floatNum = intPart + decPart + std::string(SIGNIFICANT - intPart.length() - decPart.length(), '0');
	}

	//exponent = exponent.substr(127 - 14, 15);
	result += exponent + floatNum.substr(0, SIGNIFICANT);
	return result;
}

void Convert::ConvertBitsToTwoComplement(std::string& bits, bool sign)
{
	if (sign)
	{
		BitProcess::ReverseBits(bits);
		bits = BitProcess::AddTwoBits(bits, "1");
	}
}
