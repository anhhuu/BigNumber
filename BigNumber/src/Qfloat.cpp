#include "Qfloat.h"
#include <string>
#include <iostream>

#include "BitProcess.h"
#include "Convert.h"

Qfloat::Qfloat()
	:_data{ 0 }
{
}

Qfloat::~Qfloat()
{
	memset(_data, 0, sizeof(_data));
}


void Qfloat::ScanQfloat()
{
	std::string temp;
	std::cin >> temp;
	std::string bin = Convert::ConvertFloatToBin(temp);
	BitProcess::SetBit(_data, bin);
}

void Qfloat::PrintQfloat() const
{
}

bool* Qfloat::DecToBin(const Qfloat& x) const
{
	bool* result = new bool[MAX_CELL * BITS_OF_CELL];
	std::string bits = BitProcess::GetBit(this->_data);
	for (unsigned int i = 0; i < bits.length(); i++)
	{
		if (bits[i] == '1')
		{
			result[i] = true;
		}
		else
		{
			result[i] = false;
		}
	}

	return result;
}

Qfloat Qfloat::BinToDec(std::string bits)
{
	return Qfloat();
}