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
	return nullptr;
}

Qfloat Qfloat::BinToDec(const bool* bit) const
{
	return Qfloat();
}
