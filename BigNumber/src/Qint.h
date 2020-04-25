#pragma once
#include <string>

class Qint
{
private:
	unsigned char _data[16];

public:
	Qint();
	Qint(const std::string number);
	~Qint();

public:
	//scan Qint fromt keyboard
	void ScanQInt();

	//print Qint on screen
	void PrintQInt() const;

	//convert decimal to binary of Qint
	//return a bit array of bool 
	bool* DecToBin() const;

	//convert binary to decimal of Qint
	//return a Qint
	static Qint BinToDec(const bool* bit);

	//convert hexadecimal to binary of Qint
	//return a hexa array of char 
	char* DecToHex() const;
	
	//convert binary to hexadecimal of Qint
	//return a hexa array of char 
	static char* BinToHex(const bool* bit);

public:
	//+ operator
	Qint operator+(const Qint& ) const;
	//- operator
	Qint operator-(const Qint& other) const;
	//* operator
	Qint operator*(const Qint& other) const;
	//div operator
	Qint operator/(const Qint& other) const;

	const Qint& operator=(const std::string number);

public:
	//++ operator: ++Qint
	Qint& operator++();
	//++ operator: Qint++ 
	Qint operator++(const int);
	//-- operator: --Qint
	Qint& operator--();
	//-- operator: Qint--
	Qint operator--(const int);

public:
	//boolean operator

	const bool operator>(const Qint& other) const;
	const bool operator>=(const Qint& other) const;
	const bool operator<(const Qint& other) const;
	const bool operator<=(const Qint& other) const;
	const bool operator==(const Qint& other) const;
	const bool operator!=(const Qint& other) const;

public:
	//bitwise operator

	Qint operator<<(const int n);
	Qint operator>>(const int n);
	Qint rol(const int n);
	Qint ror(const int n);

	Qint operator&(const Qint& other) const;
	Qint operator|(const Qint& other) const;
	Qint operator^(const Qint& other) const;
	Qint operator~();
};