#pragma once
#include <string>
#include "Utils.h"

class Convert
{
public:
	//Chuyển đổi một chuỗi bit sang mã hex
	//Nhận vào chuỗi bits
	//Trả về chuỗi hex
	static std::string ConvertBinToHex(std::string bits);

	//Chuyển dổi dãy bits sang dạng bù 2
	//Nhận vào tham chiếu của dãy bits cần chuyển
	static void ConvertBitsToTwoComplement(std::string& bits, bool sign);

	//Chuyển đổi một số nguyên hệ 10 sang chuỗi nhị nhân
	//Nhận vào số nguyên định dạng chuỗi
	//Trả về chuỗi chứa các bit ở dạng bù 2
	static std::string CovertNumStringToBin(std::string num, unsigned int numOfBits);

	//Chuyển đổi một chuỗi bit sang số nguyên
	//Nhận vào chuỗi bit
	//Trả về số nguyên dạng chuỗi
	static std::string ConvertBinToNumString(std::string bits);

	//Chuyển phần thập phân dạng decimal qua binary
	//Nhận vào phần thập phân, 1 tham chiếu để đếm bao nhiêu bit 0 trước bit 1 đầu tiên của phần thập phân, tham 
	//chiếu thứ 2 xác định phần nguyên trước đó khác 0 hay không.
	static std::string ConvertDecPartToBin(std::string decPart, unsigned int& countBitsBeforeOne, const bool& isIntPartDiffZero);

	//Chuyển đổi một số thực dạng chuỗi qua dạng binary (floating point)
	static std::string ConvertFloatToBin(const std::string& floatNum);

	//Chuyển đổi một chuỗi bit sang số thực
	static std::string ConvertBinToFloat(std::string bits);

	//Chuyển đổi phần thập phân của bin qua float
	static std::string ConvertBinPartToFloat(std::string bits, const unsigned int& countFirstZero = 0);
};
