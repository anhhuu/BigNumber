#include "BitProcess.h"

bool BitProcess::GetBit(unsigned char memory, int pos)
{
	return (memory >> pos) & 1;
}

void BitProcess::SetBitOne(unsigned char& memory, int pos)
{
	memory = (1 << pos) | memory;
}

void BitProcess::SetBitZero(unsigned char& memory, int pos)
{
	memory = (~(1 << pos)) & memory;
}

void BitProcess::StandardBits(std::string& bits, unsigned int numOfBits)
{
	unsigned int i = bits.size();

	if (i > numOfBits)
	{
		unsigned int numErase = i - numOfBits;
		bits.erase(0, numErase);
	}

	while (i < numOfBits)
	{
		bits.insert(bits.begin(), '0');
		i++;
	}
}

std::string BitProcess::GetBit(unsigned char memmory[MAX_CELL])
{
	std::string temp;
	for (int i = 0; i < MAX_CELL * BITS_OF_CELL; i++)
	{
		bool bit = BitProcess::GetBit(memmory[i / BITS_OF_CELL], i % BITS_OF_CELL);
		if (bit == true)
		{
			temp += '1';
		}
		else
		{
			temp += '0';
		}
	}
	return temp;
}

void BitProcess::SetBit(unsigned char memmory[MAX_CELL], std::string bits)
{
	StandardBits(bits, MAX_CELL * BITS_OF_CELL);

	for (int i = 0; i < bits.size(); i++)
	{
		if (bits[i] == '0')
		{
			BitProcess::SetBitZero(memmory[i / BITS_OF_CELL], i % BITS_OF_CELL);
		}
		else
		{
			BitProcess::SetBitOne(memmory[i / BITS_OF_CELL], i % BITS_OF_CELL);
		}
	}
}

void BitProcess::ReverseBits(std::string& bits)
{
	for (unsigned int i = 0; i < bits.size(); i++)
	{
		if (bits[i] == '0')
		{
			bits[i] = '1';
		}
		else
		{
			bits[i] = '0';
		}
	}
}

std::string BitProcess::AddTwoBits(std::string bits1, std::string bits2)
{
	BitProcess::StandardBits(bits1, 128);
	BitProcess::StandardBits(bits2, 128);

	std::string result = "";
	unsigned int reminder = 0;
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	unsigned int tempResult = 0;
	for (int i = 127; i >= 0; i--)
	{
		num1 = bits1[i] - '0';
		num2 = bits2[i] - '0';
		tempResult = num1 + num2 + reminder;
		if (tempResult == 3)
		{
			result += "1";
			reminder = 1;
		}
		else if (tempResult == 2)
		{
			result += "0";
			reminder = 1;
		}
		else
		{
			result += std::to_string(tempResult);
			reminder = 0;
		}
	}
	std::reverse(result.begin(), result.end());
	BitProcess::StandardBits(result, 128);
	return result;
}
