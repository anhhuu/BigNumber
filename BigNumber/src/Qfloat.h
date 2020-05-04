#pragma once
#include <string>

class Qfloat
{
private:
	unsigned char _data[16];

public:
	Qfloat();
	Qfloat(const std::string& numberOrBits, const bool& isBits = false);
	~Qfloat();

public:
	//Nhập số thực Qfloat từ bàn phím
	void ScanQfloat();

	//In số thực Qfloat ra màn hình
	void PrintQfloat() const;

	//Chuyển đổi thập phân sang nhị phân
	//Trả về mảng bit ở dạng bool
	bool* DecToBin(const Qfloat& x) const;

	//Chuyển đổi nhị phân sang thập phân
	//Trả về một số Qfloat
	static Qfloat BinToDec(std::string bits);

public:
	friend std::ostream& operator<<(std::ostream& os, const Qfloat& dt);
	friend std::istream& operator>>(std::istream& is, Qfloat& dt);
};
