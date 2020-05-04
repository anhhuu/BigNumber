#include "Qfloat.h"
#include <string>
#include <iostream>

#include "BitProcess.h"
#include "Convert.h"

Qfloat::Qfloat()
	:_data{ 0 }
{
}

Qfloat::Qfloat(const std::string& numberOrBits, const bool& isBits)
{
	if (!isBits)
	{
		std::string bin = Convert::ConvertFloatToBin(numberOrBits);
		BitProcess::SetBit(_data, bin);
	}
	else
	{
		BitProcess::SetBit(_data, numberOrBits);
	}
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
	const std::string bits = BitProcess::GetBit(_data);
	const std::string bigFloatNumber = Convert::ConvertBinToFloat(bits);
	std::cout << bigFloatNumber;
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
	int length = MAX_CELL * BITS_OF_CELL;

	const std::string numberInStr = Convert::ConvertBinToNumString(bits);

	const Qfloat newQfloat = Qfloat(numberInStr);
	return newQfloat;
}

std::ostream& operator<<(std::ostream& os, const Qfloat& dt)
{
	dt.PrintQfloat();
	return os;
}

std::istream& operator>>(std::istream& is, Qfloat& dt)
{
	dt.ScanQfloat();
	return is;
}
