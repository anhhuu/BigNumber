#pragma once

#include <iostream>
#include <string>
#include "Core.h"

class Qfloat
{
private:
	unsigned char _data[16];

public:
	//Hàm khởi tạo mặc định
	Qfloat();
	//Hàm khởi tạo nhận vào 2 tham số:
	//numberOrBits: số ở dạng chuỗi hoặc dãy bit
	//isBits: true nếu numberOrBits là dãy bit, false nếu là số
	Qfloat(std::string numberOrBits, const bool& isBits = false);
	~Qfloat();

public:
	//Nhập số thực Qfloat
	void ScanQfloat(std::string num);

	//In số thực Qfloat ra màn hình
	void PrintQfloat() const;

	//Chuyển đổi thập phân sang nhị phân
	//Trả về mảng bit ở dạng bool
	bool* DecToBin(const Qfloat& x) const;

	//Chuyển đổi thập phân sang nhị phân
	//Trả về mảng bit ở dạng string
	std::string DecToBin(bool isStr = true) const;

	//Chuyển đổi nhị phân sang thập phân
	//Trả về một số Qfloat
	static Qfloat BinToDec(std::string bits);

	//Trả về string của số Qfloat
	std::string ToString() const;

public:
	//Operator nhập xuất
	friend std::ostream& operator<<(std::ostream& os, const Qfloat& dt);
	friend std::istream& operator>>(std::istream& is, Qfloat& dt);
};
