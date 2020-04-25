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

void BitProcess::StandardBits(std::string& bits)
{
	int i = bits.size();
	
	if (i >= 128)
	{
		bits.erase(128);
	}
	
	while (i < 128)
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
	StandardBits(bits);

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
