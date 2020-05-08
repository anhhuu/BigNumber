#include <algorithm>

#include "Convert.h"
#include "Utils.h"
#include "BitProcess.h"
#include "Core.h"

std::unique_ptr<Convert> Convert::m_pInstance(nullptr);

std::string Convert::CovertIntStringToBin(std::string num, unsigned int numOfBits)
{
	std::string result;
	unsigned int index = 0;
	bool negative = num[0] == '-';

	while (num != "0")
	{
		result += std::to_string((num[num.length() - 1] - '0') % 2);
		num = Utils::Instance()->DivideNumStringForTwo(num);
	}

	std::reverse(result.begin(), result.end());

	BitProcess::Instance()->StandardBits(result, numOfBits);

	if (negative)
	{
		ConvertBitsToTwoComplement(result, true);
	}

	return result;
}

std::string Convert::ConvertBinToIntString(std::string bits)
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
				decResult = Utils::Instance()->AddTwoIntString(decResult, Utils::Instance()->PowOneDigit(2, exp));
			}
		}

		index++;
	}

	if (sign)
	{
		decResult = Utils::Instance()->SubtractTwoSNumString(decResult, Utils::Instance()->PowOneDigit(2, 127));
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
			decPart = Utils::Instance()->MultiplyNumStringWithOneDigit(decPart, 2);
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
			decPart = Utils::Instance()->MultiplyNumStringWithOneDigit(decPart, 2);
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
			decPart = Utils::Instance()->MultiplyNumStringWithOneDigit(decPart, 2);
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

std::string Convert::ConvertFloatStringToBin(std::string floatNum)
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

	if (firstPosOfDot == std::string::npos)
	{
		floatNum += ".0";
		firstPosOfDot = floatNum.length() - 2;
	}

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
		intPart = CovertIntStringToBin(intPart, MAX_CELL * BITS_OF_CELL + 1);
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

		exponent = CovertIntStringToBin(std::to_string(exp + EXPONENT_BIAS), NUM_OF_EXPONENT_BITS);

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
		exponent = CovertIntStringToBin(std::to_string(exp), NUM_OF_EXPONENT_BITS);

		significant = decPart;
		if (significant.length() < NUM_OF_SIGNIFICANT_BITS)
		{
			significant += std::string(NUM_OF_SIGNIFICANT_BITS - decPart.length(), '0');
		}
	}

	result += exponent + significant.substr(0, NUM_OF_SIGNIFICANT_BITS);
	return result;
}

std::string Convert::ConvertBinToFloatString(std::string bits)
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

	BitProcess::Instance()->StandardBits(exponent, MAX_CELL * BITS_OF_CELL);

	int exp = atoi(Convert::ConvertBinToIntString(exponent).c_str());

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
			result += ConvertBinPartToFloatString(significant, -exp);
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
	
	BitProcess::Instance()->StandardBits(significantInt, MAX_CELL * BITS_OF_CELL);

	result += ConvertBinToIntString(significantInt);
	significantAfterPoint = ConvertBinPartToFloatString(significantAfterPoint);
	significantAfterPoint.erase(0, 1);
	result += significantAfterPoint;

	return result;
}

std::string Convert::ConvertBinPartToFloatString(std::string bits, const unsigned int& countFirstZero)
{
	std::string result;
	for (unsigned int i = 0; i < bits.length(); i++)
	{
		if (bits[i] == '1')
		{
			result = Utils::Instance()->AddTwoDecWithPoint(result, Utils::Instance()->NegativePowTwo(i + countFirstZero + 1));
		}
	}
	return result;
}

void Convert::ConvertBitsToTwoComplement(std::string& bits, bool sign)
{
	if (sign)
	{
		BitProcess::Instance()->ReverseBits(bits);
		bits = BitProcess::Instance()->AddTwoBits(bits, "1");
	}
}

std::string Convert::ConvertHexToBin(std::string hex)
{
	std::string result = "";
	std::map<std::string, std::string> mapBinToHex = {
	{"0", "0000"},
	{"1", "0001"},
	{"2", "0010"},
	{"3", "0011"},
	{"4", "0100"},
	{"5", "0101"},
	{"6", "0110"},
	{"7", "0111"},
	{"8", "1000"},
	{"9", "1001"},
	{"A", "1010"},
	{"B", "1011"},
	{"C", "1100"},
	{"D", "1101"},
	{"E", "1110"},
	{"F", "1111"}
	};

	for (int i = 0; i < hex.length(); i++)
	{
		result += mapBinToHex[hex.substr(i, 1)];
	}

	BitProcess::Instance()->StandardBits(result, MAX_CELL * BITS_OF_CELL);
	return result;
}

std::string Convert::ConvertBinToHex(std::string bits)
{
	std::string result = "";
	std::map<std::string, std::string> mapBinToHex = {
	{"0000","0"},
	{"0001","1"},
	{"0010","2"},
	{"0011","3"},
	{"0100","4"},
	{"0101","5"},
	{"0110","6"},
	{"0111","7"},
	{"1000","8"},
	{"1001","9"},
	{"1010","A"},
	{"1011","B"},
	{"1100","C"},
	{"1101","D"},
	{"1110","E"},
	{"1111","F"}
	};

	BitProcess::Instance()->StandardBits(bits, MAX_CELL * BITS_OF_CELL);

	for (int i = 0; i < MAX_CELL * BITS_OF_CELL; i += 4)
	{
		result += mapBinToHex[bits.substr(i, 4)];
	}
	return result;
}

Convert::Convert()
{
}

std::unique_ptr<Convert>& Convert::Instance()
{
	if (m_pInstance.get() == nullptr)
	{
		m_pInstance.reset(new Convert());
	}
	return m_pInstance;
}