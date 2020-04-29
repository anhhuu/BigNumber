
#include <string>
#include <iostream>

#include "Qint.h"
#include "Utils.h"
#include "Convert.h"
#include "BitProcess.h"


Qint::Qint()
	:_data{ 0 }
{
}

Qint::Qint(const std::string number)
{
	std::string bin = Convert::CovertNumStringToBin(number);
	BitProcess::SetBit(_data, bin);

	std::string x = BitProcess::GetBit(_data);
}

Qint::~Qint()
{
	memset(_data, 0, 16);
}

void Qint::ScanQInt()
{
	std::string temp;
	std::cin >> temp;

	std::string bin = Convert::CovertNumStringToBin(temp);

	BitProcess::SetBit(_data, bin);
}

void Qint::PrintQInt() const
{
	const std::string bits = BitProcess::GetBit(_data);
	const std::string bigIntNumber = Convert::CovertBinToNumString(bits);
	std::cout << bigIntNumber;
}

bool* Qint::DecToBin() const
{
	bool* result = new bool[128];
	std::string bits = BitProcess::GetBit(this->_data);
	for (int i = 0; i < bits.length(); i++)
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

Qint Qint::BinToDec(const bool* bit)
{
	int length = MAX_CELL * BITS_OF_CELL;
	std::string bits = "";

	for (int i = 0; i < length; i++) {
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

const bool Qint::operator==(const Qint& other) const
{
	std::string allZeroBitsString = std::string(128, '0');
	Qint comparedValue = (*this ^ other);	//Lấy kq XOR giữa số so sánh và số được so sánh Ra một số Qint

	std::string comparedValueBitsStr = BitProcess::GetBit(comparedValue._data);

	bool flag = false; //Checking flag
	for (int i = 0; i < 128; i++) //Nếu kq XOR là 0 thì hai số bằng nhau và ngược lại
	{
		if (allZeroBitsString[i] != comparedValueBitsStr[i])
		{
			return flag;
		}
	}

	flag = true;
	return flag;
}

const bool Qint::operator!=(const Qint& other) const
{
	bool flag = false;
	if (*this == other)
		return flag;
	else flag = true;
	return flag;
}

const bool Qint::operator>(const Qint& other) const
{
	std::string otherBitsStr = BitProcess::GetBit(other._data);//Chuyển sang dãy bit
	std::string thisBitsStr = BitProcess::GetBit(this->_data);//Chuyển sang dãy bit
	bool flag = false;//Checking flag

	// a = b
	if (*this == other)
		return flag;

	// a < 0 and b > 0
	if (thisBitsStr[0] == '1' && otherBitsStr[0] == '0')
		return flag;

	// a > 0 and b < 0
	else if (thisBitsStr[0] == '0' && otherBitsStr[0] == '1')
	{
		flag = true;
		return flag;
	}

	// a > 0 and b > 0
	else if (thisBitsStr[0] == '0' && otherBitsStr[0] == '0')
	{
		int i = 1;
		do //So sánh bit giá trị bên trái nhất
		{
			if (thisBitsStr[i] == '1' && otherBitsStr[i] == '0') //a > b
			{
				flag = true;
				return flag;
			}
			else if (thisBitsStr[i] == '0' && otherBitsStr[i] == '1') //a < b
			{
				flag = false;
				return flag;
			}
			i++; //Xét bit kế tiếp
		} while (i < 128);
	}

	// a < 0 and b < 0
	else if (thisBitsStr[0] == '1' && otherBitsStr[0] == '1')
	{
		Convert::ConvertBitsToTwoComplement(thisBitsStr, true);
		Convert::ConvertBitsToTwoComplement(otherBitsStr, true);

		int i = 1;
		do	// So sánh ngược của TH so sánh 2 số dương		
		{
			if (thisBitsStr[i] == '1' && otherBitsStr[i] == '0')
			{
				flag = false;
				return flag;
			}
			else if (thisBitsStr[i] == '0' && otherBitsStr[i] == '1')
			{
				flag = true;
				return flag;
			}
			i++;
		} while (i < 128);
	}

	return flag;
}

const bool Qint::operator>=(const Qint& other) const
{
	bool flag = true;

	if (*this > other || *this == other)
		return flag;
	else flag = false;
	return flag;
}

const bool Qint::operator<(const Qint& other) const
{
	bool flag = false;

	if (*this >= other)
		return flag;

	else flag = true;

	return flag;
}

const bool Qint::operator<=(const Qint& other) const
{
	bool flag = false;
	if (*this > other)
		return flag;
	else flag = true;
	return flag;
}

Qint Qint::operator<<(const int n)
{
	std::string bits = BitProcess::GetBit(this->_data);
	bits += std::string(n, '0');
	bits.erase(0, n);

	Qint returnVal;
	BitProcess::SetBit(returnVal._data, bits);
	return returnVal;
}

Qint Qint::operator>>(const int n)
{
	std::string bits = BitProcess::GetBit(this->_data);

	if (bits.at(0) == '1')
	{
		bits.insert(0, std::string(n, '1'));
	}
	else
	{
		bits.insert(0, std::string(n, '0'));
	}
	bits.erase(bits.length() - n, n);

	Qint returnVal;
	BitProcess::SetBit(returnVal._data, bits);
	return returnVal;
}

Qint Qint::rol(const int n)
{
	std::string bits = BitProcess::GetBit(this->_data);
	std::string f = bits.substr(0, n);
	bits += f;
	bits.erase(0, n);

	Qint returnVal;
	BitProcess::SetBit(returnVal._data, bits);
	return returnVal;
}

Qint Qint::ror(const int n)
{
	std::string bits = BitProcess::GetBit(this->_data);
	std::string f = bits.substr(bits.length() - n, n);
	bits.insert(0, f);
	bits.erase(bits.length() - n, n);
	Qint returnVal;
	BitProcess::SetBit(returnVal._data, bits);
	return returnVal;

}

Qint Qint::operator&(const Qint& other) const
{
	std::string bitsThis = BitProcess::GetBit(this->_data);
	std::string bitsOther = BitProcess::GetBit(other._data);
	std::string result;
	for (int i = 0; i < 128; i++)
	{
		if (bitsThis.at(i) == '1' && bitsOther.at(i) == '1')
		{
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
	for (int i = 0; i < 128; i++)
	{
		if (bitsThis.at(i) == '0' && bitsOther.at(i) == '0')
		{
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
	for (int i = 0; i < 128; i++)
	{
		if (bitsThis.at(i) == bitsOther.at(i))
		{
			result.append("0");
		}
		else
		{
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
	for (int i = 0; i < 128; i++)
	{
		if (bitsThis.at(i) == '0')
		{
			result.append("1");

		}
		else
		{
			result.append("0");
		}
	}
	Qint returnVal;
	BitProcess::SetBit(returnVal._data, result);
	return returnVal;
}

std::ostream& operator<<(std::ostream& os, const Qint& dt)
{
	dt.PrintQInt();
	return os;
}

std::istream& operator>>(std::istream& is, Qint& dt)
{
	dt.ScanQInt();
	return is;
}
