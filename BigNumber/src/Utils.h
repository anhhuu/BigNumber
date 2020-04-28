﻿#pragma once
#include <string>

class Utils
{
public:
	//Cộng 2 số nguyên lớn ở dạng chuỗi
	//Kết quả trả về là số nguyên lớn dạng chuỗi
	static std::string AddTwoIntString(std::string num1, std::string num2);

	//Chia số nguyên lớn cho 2
	//Trả về kết quả của phép chia là một số nguyên lớn dạng chuỗi
	static std::string DivideNumStringForTwo(std::string num);

	//Nhân số nguyên lớn dạng chuỗi với một số nguyên (int)
	//Kêt quả trả về một số nguyên lớn
	static std::string MultiplyNumStringWithOneDigit(std::string num1, int num2);

	//Nhân 2 số nguyên lớn dạng chuỗi với nhau
	//Kết quả trả về một số nguyên lớn dạng chuỗi
	//ex: "23565432456754322356543245675432" * "24567543245676543456"
	static std::string MultiplyNumString(std::string num1, std::string num2);

	//Lũy thừa một số nguyên với số mũ
	//Trả về số nguyên lớn dạng chuỗi
	//ex: 2^72 = ? 
	static std::string PowOneDigit(int factor, int exp);

};