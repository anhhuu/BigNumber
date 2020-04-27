#pragma once
#include <string>
using namespace std;

class Convert
{
public:
	//Chuyển đổi một số nguyên hệ 10 sang chuỗi nhị nhân
	//Nhận vào số nguyên định dạng chuỗi
	//Trả về chuỗi chứa các bit
	static std::string CovertNumStringToBin(std::string num);

	//Chuyển đổi một chuỗi bit sang số nguyên
	//Nhận vào chuỗi bit
	//Trả về số nguyên dạng chuỗi
	static std::string CovertBinToNumString(std::string bits);

	//Chuyển đổi từ hệ bù hai về hệ nhị phân thường và lưu vào biến result được truyền vào
	static void convertFromC2ToBin(const bool source[128], bool result[128]);
};
