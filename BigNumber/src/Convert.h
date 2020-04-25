#pragma once

#include <string>

class Convert
{
private:
	static void ConvertBitsToTwoComplement(std::string& bits, bool sign);

public:
	//Chuyển đổi một số nguyên hệ 10 sang chuỗi nhị nhân
	//Nhận vào số nguyên định dạng chuỗi
	//Trả về chuỗi chứa các bit ở dạng bù 2
	static std::string CovertNumStringToBin(std::string num);

	//Chuyển đổi một chuỗi bit sang số nguyên
	//Nhận vào chuỗi bit
	//Trả về số nguyên dạng chuỗi
	static std::string CovertBinToNumString(std::string bits);

};
