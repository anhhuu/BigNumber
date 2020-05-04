#pragma once
class Qfloat
{
private:
	unsigned char _data[16];

public:
	Qfloat();
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
};
