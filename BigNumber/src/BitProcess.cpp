#include "BitProcess.h"

bool BitProcess::GetBit(unsigned char memory, int pos)
{
	return (memory >> BITS_OF_CELL - 1- pos%BITS_OF_CELL) & 1;
}

void BitProcess::SetBitOne(unsigned char& memory, int pos)
{
	memory = (1 <<BITS_OF_CELL-1 - pos%BITS_OF_CELL) | memory;
}

void BitProcess::SetBitZero(unsigned char& memory, int pos)
{
	memory = (~(1 << BITS_OF_CELL - 1 - pos % BITS_OF_CELL)) & memory;
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
		bool bit = BitProcess::GetBit(memmory[i / BITS_OF_CELL],i);
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
	memset(memmory, 0, MAX_CELL);
	for (int i = 0; i < bits.size(); i++)
	{
		if (bits[i] == '0')
		{
			BitProcess::SetBitZero(memmory[i / BITS_OF_CELL], i);
		}
		else
		{
			BitProcess::SetBitOne(memmory[i / BITS_OF_CELL], i);
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

