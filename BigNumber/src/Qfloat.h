#pragma once
class Qfloat
{
private:
	unsigned char _data[16];

public:
	Qfloat();
	~Qfloat();

public:
	//scan Qfloat fromt keyboard
	void ScanQfloat(Qfloat& x);

	//print Qfloat on screen
	void PrintQfloat(const Qfloat& x) const;

	//convert decimal to binary of Qfloat
	//return a bit array of bool 
	bool* DecToBin(const Qfloat& x) const;

	//convert binary to decimal of Qfloat
	//return a Qfloat
	Qfloat BinToDec(const bool* bit) const;
};
