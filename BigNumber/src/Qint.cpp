#include "Qint.h"
#include "BitProcess.h"

Qint::Qint()
	:_data{ 0 }
{
}

Qint::Qint(const std::string number)
{
}

Qint::~Qint()
{
}

void Qint::ScanQInt()
{
}

void Qint::PrintQInt() const
{
}

bool* Qint::DecToBin() const
{
	return nullptr;
}

Qint Qint::BinToDec(const bool* bit)
{
	return Qint();
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
	std::string bits = BitProcess::GetBit(this->_data);
	bits += "0";
	bits.erase(0, 1);

	Qint returnVal;
	BitProcess::SetBit(returnVal._data, bits);
	return returnVal;
}

Qint Qint::operator>>(const int n)
{
	std::string bits = BitProcess::GetBit(this->_data);
	bits.insert(0, "0");
	bits.erase(bits.length() - 1, 1);

	Qint returnVal;
	BitProcess::SetBit(returnVal._data, bits);
	return returnVal;
}

Qint Qint::rol(const int n)
{
	std::string bits = BitProcess::GetBit(this->_data);
	char f = bits.at(0);
	bits += f;
	bits.erase(0, 1);

	Qint returnVal;
	BitProcess::SetBit(returnVal._data, bits);
	return returnVal;
}

Qint Qint::ror(const int n)
{
	std::string bits = BitProcess::GetBit(this->_data);
	char f = bits.at(bits.length() - 1);
	bits.insert(bits.begin(), f);
	bits.erase(bits.length() - 1, 1);
	Qint returnVal;
	BitProcess::SetBit(returnVal._data, bits);
	return returnVal;

}

Qint Qint::operator&(const Qint& other) const
{
	std::string bitsThis = BitProcess::GetBit(this->_data);
	std::string bitsOther = BitProcess::GetBit(other._data);
	std::string result;
	for (int i = 0; i < 128; i++) {		
		if (bitsThis.at(i) == '1' && bitsOther.at(i) == '1') {
			result.append("1");
		}
		else {
			result.append("0");
		}
	}
	Qint returnVal;
	BitProcess::SetBit(returnVal._data, result);
	return returnVal;
}

Qint Qint::operator|(const Qint& other) const
{
	std::string bitsThis = BitProcess::GetBit(this->_data);
	std::string bitsOther = BitProcess::GetBit(other._data);
	std::string result;
	for (int i = 0; i < 128; i++) {
		if (bitsThis.at(i) == '0' && bitsOther.at(i) == '0') {
			result.append("0");
		}
		else {
			result.append("1");
		}
	}

	Qint returnVal;
	BitProcess::SetBit(returnVal._data, result);
	return returnVal;
}

Qint Qint::operator^(const Qint& other) const
{
	std::string bitsThis = BitProcess::GetBit(this->_data);
	std::string bitsOther = BitProcess::GetBit(other._data);
	std::string result;
	for (int i = 0; i < 128; i++) {
		if (bitsThis.at(i) == bitsOther.at(i) ) {
			result.append("0");
		}
		else {
			result.append("1");
		}
	}

	Qint returnVal;
	BitProcess::SetBit(returnVal._data, result);
	return returnVal;
}

Qint Qint::operator~()
{
	std::string bitsThis = BitProcess::GetBit(this->_data);
	std::string result;
	for (int i; i < 128; i++) {
		if (bitsThis.at(i) == '0') {
			result.append("1");

		}
		else {
			result.append("0");
		}
	}
	Qint returnVal;
	BitProcess::SetBit(returnVal._data, result);
	return returnVal;
}

