#pragma once

#include <string>
#include "Utils.h"

//Lớp Convert thiết kế dưới dạng Singleton
class Convert
{
public:
	//Chuyển đổi một chuỗi bit sang mã hex
	//Nhận vào chuỗi bits
	//Trả về chuỗi hex
	std::string ConvertBinToHex(std::string bits);

	//Chuyển đổi một chuỗi hex sang bin
	//Nhận vào chuỗi hex
	//Trả về chuỗi bits
	std::string ConvertHexToBin(std::string hex);

	//Chuyển dổi dãy bits sang dạng bù 2
	//Nhận vào tham chiếu của dãy bits cần chuyển
	void ConvertBitsToTwoComplement(std::string& bits, bool sign);

	//Chuyển đổi một số nguyên hệ 10 sang chuỗi nhị nhân
	//Nhận vào số nguyên định dạng chuỗi
	//Trả về chuỗi chứa các bit ở dạng bù 2
	std::string CovertNumStringToBin(std::string num, unsigned int numOfBits);

	//Chuyển đổi một chuỗi bit sang số nguyên
	//Nhận vào chuỗi bit
	//Trả về số nguyên dạng chuỗi
	std::string ConvertBinToNumString(std::string bits);

	//Chuyển phần thập phân dạng decimal qua binary
	//Nhận vào phần thập phân, 1 tham chiếu để đếm bao nhiêu bit 0 trước bit 1 đầu tiên của phần thập phân, tham 
	//chiếu thứ 2 xác định phần nguyên trước đó khác 0 hay không.
	//Trả về dang binary dạng chuỗi
	std::string ConvertDecPartToBin(std::string decPart, unsigned int& countBitsBeforeOne, const bool& isIntPartDiffZero);

	//Chuyển đổi một số thực dạng chuỗi qua dạng binary (floating point)
	//Nhận vào 1 số thực dạng chuỗi
	//Trả về 1 chuỗi bits
	std::string ConvertFloatToBin(std::string floatNum);

	//Chuyển đổi một chuỗi bit sang số thực
	//Nhận vài chuỗi bit định dang số chấm động 16 bytes
	//Trả về số thực dạng chuỗi
	std::string ConvertBinToFloat(std::string bits);

	//Chuyển đổi phần thập phân của bin qua float
	std::string ConvertBinPartToFloat(std::string bits, const unsigned int& countFirstZero = 0);

private:
	Convert();

public:
	Convert(const Convert&) = delete;
	void operator=(const Convert&) = delete;

public:
	static std::unique_ptr<Convert>& Instance();

private:
	static std::unique_ptr<Convert> m_pInstance;
};
