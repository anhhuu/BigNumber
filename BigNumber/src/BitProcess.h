#pragma once
#include"Qint.h"
#include <string>
#include "Core.h"

class BitProcess
{
private:
	//Lấy bit tại vị trị pos từ trái qua
	static bool GetBit(const unsigned char memory, const unsigned int& pos);
	//Bật bit lên 1 tại pos từ trái qua
	static void SetBitOne(unsigned char& memory, const unsigned int& pos);
	//Tắt bit xuống 0 tại pos từ trái qua
	static void SetBitZero(unsigned char& memory, const unsigned int& pos);

public:
	//Chuẩn hoá chuỗi bit cho đủ 128 bits, nếu thiếu thì thêm bit 0 vào đầu, thừa thì cắt các bit ở cuối
	static void StandardBits(std::string& bits, const unsigned int& numOfBits);

	//Get bit trên vùng nhớ unsigned char 16 bytes
	static std::string GetBit(const unsigned char memmory[MAX_CELL]);

	//Set bit trên vùng nhớ unsigned char 16 bytes
	static void SetBit(unsigned char memmory[MAX_CELL], std::string bits);

	//Đảo chuỗi bits
	static void ReverseBits(std::string& bits);

public:
	//Cộng nhị phân 2 dãy bits
	static std::string AddTwoBits(std::string bits1, std::string bits2);
	//Thực hiện trừ 2 dãy bits
	static std::string SubtractTwoBits(std::string bits1, std::string bits2);
	//Thực hiện nhân nhị phân 2 dãy bits
	static std::string MultiplyTwoBits(std::string bits1, std::string bits2);
	//Shift right một chuỗi 3 dãy bits
	static void ShiftRightThreeBits(std::string& A, std::string& Q, char& Q_1);
	//Chia 2 dãy bit
	static std::string DivideTwoBits(std::string bits1, std::string bits2);
	//Shift left một chuỗi 3 dãy bits
	static void ShiftLeftTwoBits(std::string& A, std::string& Q);

};
