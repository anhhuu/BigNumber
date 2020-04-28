#include "Qint.h"


Qint::Qint()
	:_data{0}
{
}

Qint::Qint(const std::string number)
{
	const std::string bits = Convert::CovertNumStringToBin(number);
	memset(_data, 0, MAX_CELL);
	for (int i = 0; i < bits.length(); i++) {
		BitProcess::SetBit(_data, bits);
	}

}

Qint::~Qint()
{
	memset(_data, 0, 16);
}

void Qint::ScanQInt()
{
}

void Qint::PrintQInt()
{
	const std::string bits = BitProcess::GetBit(_data);
	const std::string bigIntNumber = Convert::CovertBinToNumString(bits);
	std::cout << bigIntNumber; 



}

bool* Qint::DecToBin()
{
	bool bitsInBool[MAX_CELL*BITS_OF_CELL];
	const std::string bitsInString = BitProcess::GetBit(_data);
	for (int i = 0; i < MAX_CELL * BITS_OF_CELL; i++) {
		bitsInBool[i] = bitsInString[i];
	}

	return bitsInBool;



}

Qint Qint::BinToDec(const bool* bit)
{
	int length = MAX_CELL * BITS_OF_CELL;
	std::string bits = "";

	for(int i = 0;i<length;i++){
		bits += (bit[i] ? '1' : '0');
	}
	const std::string numberInStr = Convert::CovertBinToNumString(bits);

	Qint newQInt = Qint(numberInStr);
	return newQInt;

}

char* Qint::BinToHex(const bool* bit)
{
	return nullptr;
}

char* Qint::DecToHex() const
{
	return nullptr;
}

Qint Qint::operator+(const Qint&) const
{
	return Qint();
}

Qint Qint::operator-(const Qint& other) const
{
	return Qint();
}

Qint Qint::operator*(const Qint& other) const
{
	return Qint();
}

Qint Qint::operator/(const Qint& other) const
{
	return Qint();
}

const Qint& Qint::operator=(const std::string number)
{
	Qint rv;
	return rv;
	// TODO: insert return statement here
}

Qint& Qint::operator++()
{
	Qint rv;
	return rv;
	// TODO: insert return statement here
}

Qint Qint::operator++(const int)
{
	return Qint();
}

Qint& Qint::operator--()
{
	Qint rv;
	return rv;
	// TODO: insert return statement here
}

Qint Qint::operator--(const int)
{
	return Qint();
}

const bool Qint::operator>(const Qint& other) const
{
	return false;
}

const bool Qint::operator>=(const Qint& other) const
{
	return false;
}

const bool Qint::operator<(const Qint& other) const
{
	return false;
}

const bool Qint::operator<=(const Qint& other) const
{
	return false;
}

const bool Qint::operator==(const Qint& other) const
{
	return false;
}

const bool Qint::operator!=(const Qint& other) const
{
	return false;
}

Qint Qint::operator<<(const int n)
{
	return Qint();
}

Qint Qint::operator>>(const int n)
{
	return Qint();
}

Qint Qint::rol(const int n)
{
	return Qint();
}

Qint Qint::ror(const int n)
{
	return Qint();
}

Qint Qint::operator&(const Qint& other) const
{
	return Qint();
}

Qint Qint::operator|(const Qint& other) const
{
	return Qint();
}

Qint Qint::operator^(const Qint& other) const
{
	return Qint();
}

Qint Qint::operator~()
{
	return Qint();
}

