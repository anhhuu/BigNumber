﻿#pragma once
#include <string>
#include "Utils.h"

class Convert
{
public:
	static void ConvertBitsToTwoComplement(std::string& bits, bool sign);

	//Chuyển đổi một số nguyên hệ 10 sang chuỗi nhị nhân
	//Nhận vào số nguyên định dạng chuỗi
	//Trả về chuỗi chứa các bit ở dạng bù 2
	static std::string CovertNumStringToBin(std::string num, unsigned int numOfBits);

	//Chuyển đổi một chuỗi bit sang số nguyên
	//Nhận vào chuỗi bit
	//Trả về số nguyên dạng chuỗi
	static std::string CovertBinToNumString(std::string bits);


	static std::string ConvertDecPartToBin(std::string decPart, unsigned int& countBitsBeforeOne, const bool& isIntPartDiffZero);

	static std::string ConvertFloatToBin(std::string floatNum);
};
