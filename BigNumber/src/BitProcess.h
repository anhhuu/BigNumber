#pragma once
#include"Qint.h"

#define MAX_CELL 16 
#define BITS_OF_CELL 8
#include <string>

class BitProcess
{
public: 
	// Lấy bit tại vị trị pos từ phải qua
	static bool GetBit(unsigned char memory, int pos);
	//Bật bit lên 1 tại pos từ phải qua
	static void SetBitOne(unsigned char& memory, int pos);
	//Tắt bit xuống 0 tại pos từ phải qua
	static void SetBitZero(unsigned char& memory, int pos);

public:
	//Chuẩn hoá chuỗi bit cho đủ 128 bits, nếu thiếu thì thêm bit 0 vào đầu, thừa thì cắt các bit ở cuối
	static void StandardBits(std::string& bits, unsigned int numOfBits);

	// Get bit trên vùng nhớ unsigned char 16 bytes
	static std::string GetBit(unsigned char memmory[MAX_CELL]);

	//Set bit trên vùng nhớ unsigned char 16 bytes
	static void SetBit(unsigned char memmory[MAX_CELL], std::string bits);

	//Đảo chuỗi bits
	static void ReverseBits(std::string& bits);

public:
	//Cộng nhị phân 2 dãy bits
	static std::string AddTwoBits(std::string bits1, std::string bits2);
};