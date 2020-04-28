
#include<string>
using namespace std;
#include <iostream>

#include "Qint.h"
#include "Utils.h"
#include "Convert.h"
#include "BitProcess.h"
  
Qint::Qint()
	:_data{0}
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
	std::string temp;
	std::cin >> temp;

	std::string bin = Convert::CovertNumStringToBin(temp);

	BitProcess::SetBit(_data, bin);
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

const bool Qint::operator==(const Qint& other) const
{
	string AllZeroBitString = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	Qint ComparedValue = (*this ^ other);	//Lấy kq XOR giữa số so sánh và số được so sánh Ra một số Qint
	bool *ComparedValueArray = ComparedValue.DecToBin();	//Chuyển số Qint vừa có được sang mảng các bit
	
	bool flag = false; //Checking flag
	for (int i = 0; i < 128; i++) //Nếu kq XOR là 0 thì hai số bằng nhau và ngược lại
	{
		if (AllZeroBitString[i] != ComparedValueArray[i])
			return flag;
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
	Qint temp = other;//Sao chép other sang biến tạm
	bool *OTHER = temp.DecToBin();//Chuyển sang dãy bit
	bool *THIS = DecToBin();//Chuyển sang dãy bit
	bool flag = false;//Checking flag

	// a = b
	if (*this == other) 
		return flag;

	// a < 0 and b > 0
	if (THIS[127] == 1 && OTHER[127] == 0)
		return flag;

	// a > 0 and b < 0
	else if (THIS[127] == 0 && OTHER[127] == 1) 
	{
		flag = true;
		return flag;
	}

	// a > 0 and b > 0
	else if (THIS[127] == 0 && OTHER[127] == 0)
	{
		int i = 126;
		do //So sánh bit giá trị bên trái nhất
		{
			if (THIS[i] == 1 && OTHER[i] == 0) //a > b
			{
				flag = true;
				return flag;
			}
			else if (THIS[i] == 0 && OTHER[i] == 1) //a < b
			{
				flag = false;
				return flag;
			}
			i--; //Xét bit kế tiếp
		} while (i >= 0);
	}
	
	// a < 0 and b < 0
	else if (THIS[127] == 1 && OTHER[127] == 1)
	{
		Qint temp1 = *this;//Copy dữ liệu
		Qint temp2 = other;
		bool result1[128], result2[128]; //Các biến chứa dãy bit của (this) và (other)

		Convert::convertFromC2ToBin(temp1.DecToBin(),result1);//Chuyển từ dạng bù 2 về nhị phân thường
		Convert::convertFromC2ToBin(temp2.DecToBin(),result2);


		int i = 126;
		do	// So sánh ngược của TH so sánh 2 số dương		
		{
			if (result1[i] == 1 && result2[i] == 0) 
			{
				flag = false;
				return flag;
			}
			else if (result1[i] == 0 && result2[i] == 1)
			{
				flag = true;
				return flag;
			}
			i--;
		} while (i >= 0);
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

