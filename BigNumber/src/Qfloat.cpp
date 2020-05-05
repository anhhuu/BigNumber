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
		std::string bin = Convert::Instance()->ConvertFloatToBin(numberOrBits);
		BitProcess::Instance()->SetBit(_data, bin);
	}
	else
	{
		BitProcess::Instance()->SetBit(_data, numberOrBits);
	}
}

Qfloat::~Qfloat()
{
	memset(_data, 0, sizeof(_data));
}


void Qfloat::ScanQfloat(std::string num)
{
	std::string bin = Convert::Instance()->ConvertFloatToBin(num);
	BitProcess::Instance()->SetBit(_data, bin);
}

void Qfloat::PrintQfloat() const
{
	const std::string bits = BitProcess::Instance()->GetBit(_data);
	const std::string bigFloatNumber = Convert::Instance()->ConvertBinToFloat(bits);
	std::cout << bigFloatNumber;
}

bool* Qfloat::DecToBin(const Qfloat& x) const
{
	bool* result = new bool[MAX_CELL * BITS_OF_CELL];
	std::string bits = BitProcess::Instance()->GetBit(this->_data);
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

	const std::string numberInStr = Convert::Instance()->ConvertBinToNumString(bits);

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
	std::string num;
	is >> num;
	dt.ScanQfloat(num);
	return is;
}
