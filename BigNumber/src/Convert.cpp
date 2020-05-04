#include <algorithm>

#include "Convert.h"
#include "Utils.h"
#include "BitProcess.h"
#include "Core.h"


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

std::string Convert::ConvertBinToNumString(std::string bits)
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
	//Xử lí số "0123" -> "123"
	unsigned int firstPosDecPartNotOfZero = decPart.find_first_not_of('0', 0);

	int countFirstZero = firstPosDecPartNotOfZero;
	if (firstPosDecPartNotOfZero == -1)
	{
		return "0";
	}
	decPart = decPart.substr(firstPosDecPartNotOfZero, decPart.length() - firstPosDecPartNotOfZero);

	unsigned int lengthDecPartAtFirstTime = decPart.length();

	std::string num = "1";
	num = num.insert(1, lengthDecPartAtFirstTime + countFirstZero, '0');

	std::string result;

	if (isIntPartDiffZero)
	{
		int index = 0;
		while (index < NUM_OF_SIGNIFICANT_BITS)
		{
			decPart = Utils::MultiplyNumStringWithOneDigit(decPart, 2);
			if (decPart.length() < lengthDecPartAtFirstTime + countFirstZero + 1)
			{
				result.append(1, '0');
			}
			else
			{
				result.append(1, '1');

				if (decPart == num)
				{
					break;
				}

				decPart.erase(0, 1);
				firstPosDecPartNotOfZero = decPart.find_first_not_of('0', 0);

				if (firstPosDecPartNotOfZero > 0)
				{
					decPart = decPart.substr(firstPosDecPartNotOfZero, decPart.length() - firstPosDecPartNotOfZero);
				}
			}
			index++;
		}
		return result;
	}
	else
	{
		bool isOne = false;
		unsigned int firstPosOne = -1;
		unsigned int countBitsAfterOne = 0;
		while (!isOne && countBitsBeforeOne < MAX_EXPONENT + NUM_OF_SIGNIFICANT_BITS)
		{
			decPart = Utils::MultiplyNumStringWithOneDigit(decPart, 2);
			if (decPart.length() < lengthDecPartAtFirstTime + countFirstZero + 1)
			{
				countBitsBeforeOne++;
			}
			else
			{
				result.append(1, '1');
				unsigned int firstPosOne = countBitsBeforeOne;
				isOne = true;

				if (decPart == num)
				{
					return result;
				}

				decPart.erase(0, 1);
				firstPosDecPartNotOfZero = decPart.find_first_not_of('0', 0);
				if (firstPosDecPartNotOfZero > 0)
				{
					decPart = decPart.substr(firstPosDecPartNotOfZero, decPart.length() - firstPosDecPartNotOfZero);
				}
			}
		}

		while (countBitsAfterOne < NUM_OF_SIGNIFICANT_BITS - 1 && countBitsBeforeOne < MAX_EXPONENT + NUM_OF_SIGNIFICANT_BITS)
		{
			decPart = Utils::MultiplyNumStringWithOneDigit(decPart, 2);
			if (decPart.length() < lengthDecPartAtFirstTime + countFirstZero + 1)
			{
				result.append(1, '0');
			}
			else
			{
				result.append(1, '1');

				if (decPart == num)
				{
					break;
				}

				decPart.erase(0, 1);
				firstPosDecPartNotOfZero = decPart.find_first_not_of('0', 0);
				if (firstPosDecPartNotOfZero > 0)
				{
					decPart = decPart.substr(firstPosDecPartNotOfZero, decPart.length() - firstPosDecPartNotOfZero);
				}
			}
			countBitsAfterOne++;
		}
		return result;
	}
}

std::string Convert::ConvertFloatToBin(const std::string& floatNum)
{
	unsigned int index = 0;
	std::string result;
	bool negative = floatNum[0] == '-';
	if (negative)
	{
		index++;
		result.insert(0, "1");
	}
	else
	{
		result.insert(0, "0");
	}

	unsigned int countBitBeforeOne = 0;
	unsigned int firstPosOfDot = floatNum.find_first_of('.', 0);

	std::string intPart = floatNum.substr(index, firstPosOfDot - index);

	unsigned int firstPosDecPartNotOfZero = intPart.find_first_not_of('0', 0);

	if (firstPosDecPartNotOfZero == -1)
	{
		intPart = "0";
	}

	if (firstPosDecPartNotOfZero != std::string::npos)
	{
		intPart = intPart.substr(firstPosDecPartNotOfZero, intPart.length() - firstPosDecPartNotOfZero);
	}

	if (intPart != "0")
	{
		intPart = CovertNumStringToBin(intPart, MAX_CELL * BITS_OF_CELL + 1);
	}

	std::string decPart = floatNum.substr(firstPosOfDot + 1, floatNum.length() - 1 - firstPosOfDot);

	std::string exponent;
	std::string significant;

	if (intPart != "0")
	{
		decPart = ConvertDecPartToBin(decPart, countBitBeforeOne);
		unsigned int firstOne = intPart.find_first_of('1', 0);
		intPart = intPart.substr(firstOne + 1, intPart.length() - firstOne - 1);

		int exp = intPart.length();
		if (exp >= MAX_CELL * BITS_OF_CELL)
		{
			exponent = std::string(NUM_OF_EXPONENT_BITS, '1');
			result += exponent + std::string(NUM_OF_SIGNIFICANT_BITS, '0');
			return result;
		}

		exponent = CovertNumStringToBin(std::to_string(exp + EXPONENT_BIAS), NUM_OF_EXPONENT_BITS);

		significant = intPart + decPart;
		if (significant.length() < NUM_OF_SIGNIFICANT_BITS)
		{
			significant += std::string(NUM_OF_SIGNIFICANT_BITS - intPart.length() - decPart.length(), '0');
		}
	}
	else
	{
		if (std::atoi(decPart.c_str()) == 0)
		{
			return std::string(MAX_CELL * BITS_OF_CELL, '0');
		}

		decPart = ConvertDecPartToBin(decPart, countBitBeforeOne, false);
		int exp = countBitBeforeOne + 1;
		if (exp < EXPONENT_BIAS - 1)
		{
			exp = -exp + EXPONENT_BIAS;
			decPart.erase(0, 1);
		}
		else if (exp == EXPONENT_BIAS - 1)
		{
			exp = -exp + EXPONENT_BIAS - 1;
		}
		else
		{
			decPart.insert(decPart.begin(), exp - EXPONENT_BIAS, '0');
			exp = 0;
		}
		exponent = CovertNumStringToBin(std::to_string(exp), NUM_OF_EXPONENT_BITS);

		significant = decPart;
		if (significant.length() < NUM_OF_SIGNIFICANT_BITS)
		{
			significant += std::string(NUM_OF_SIGNIFICANT_BITS - decPart.length(), '0');
		}
	}

	result += exponent + significant.substr(0, NUM_OF_SIGNIFICANT_BITS);
	return result;
}

std::string Convert::ConvertBinToFloat(std::string bits)
{
	std::string result;
	std::string exponent;

	if (bits[0] == '1')
	{
		result += "-";
	}

	exponent = bits.substr(1, NUM_OF_EXPONENT_BITS);
	//lấy 15 bit mũ trong bits
	std::string significant;
	significant = bits.substr(NUM_OF_EXPONENT_BITS + 1, NUM_OF_EXPONENT_BITS + NUM_OF_SIGNIFICANT_BITS);

	//xét trường hợp số vô cùng và số báo lỗi
	if (exponent == std::string(NUM_OF_EXPONENT_BITS, '1'))
	{
		if (std::atoi(significant.c_str()) == 0)
		{
			result = "inf";
		}
		else
		{
			result = "NaN";
		}
		return result;
	}

	BitProcess::StandardBits(exponent, MAX_CELL * BITS_OF_CELL);

	int exp = atoi(Convert::ConvertBinToNumString(exponent).c_str());

	if (exp == 0)
	{
		if (std::atoi(significant.c_str()) == 0)
		{
			result = "0";
		}
		else
		{
			exp = -EXPONENT_BIAS + 1;
			//result.append("0.");
			result += ConvertBinPartToFloat(significant, -exp);
		}

		return result;
	}

	exp -= EXPONENT_BIAS;
	significant.insert(0, "1");

	if (exp > 0)
	{
		significant.insert(exp + 1, ".");
	}
	else
	{
		significant.insert(0, std::string(-exp, '0'));
		significant.insert(1, ".");
	}

	int pos = significant.find_first_of(".", 0);
	std::string significantInt = significant.substr(0, pos);
	std::string significantAfterPoint = significant.substr(pos + 1, significant.length() - 1);
	
	BitProcess::StandardBits(significantInt, MAX_CELL * BITS_OF_CELL);

	result += ConvertBinToNumString(significantInt);
	significantAfterPoint = ConvertBinPartToFloat(significantAfterPoint);
	significantAfterPoint.erase(0, 1);
	result += significantAfterPoint;

	return result;
}

std::string Convert::ConvertBinPartToFloat(std::string bits, const unsigned int& countFirstZero)
{
	std::string result;
	for (unsigned int i = 0; i < bits.length(); i++)
	{
		if (bits[i] == '1')
		{
			result = Utils::AddTwoDecWithPoint(result, Utils::NegativePowTwo(i + countFirstZero + 1));
		}
	}
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

std::string Convert::ConvertBinToHex(std::string bits)
{
	std::string result = "";
	auto mapBinToHex = Utils::GetMapBinToHex();
	for (int i = 0; i < MAX_CELL * BITS_OF_CELL; i += 4)
	{
		result += mapBinToHex[bits.substr(i, 4)];
	}
	return result;
}
