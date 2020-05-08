#include <iostream>
#include <stdint.h>
#include <cstdint>
#include <vector>
#include <fstream>
#include <sstream>
#include <conio.h>

#include "Qint.h"
#include "Qfloat.h"
#include "Utils.h"
#include "Convert.h"

//Hàm chuẩn hóa về hệ cơ số đề bài yêu cầu sau khi xử lí với toán tử
std::string StandardResult(Qint number, int base)
{
	switch (base)
	{
	case 10:
		return number.ToString();
		break;
	case 2:
		return number.DecToBin(true);
		break;
	case 16:
		return number.DecToHex();
		break;
	}
}

//Hàm xử lí với các toán tử và trả về chuỗi kết quả string
std::string processOperator(Qint A, Qint B, std::string numB, std::string _operator, int base)
{
	if (_operator == "~")
	{
		return StandardResult(~A, base);
	}
	else if (_operator == "+")
	{
		return StandardResult(A + B, base);
	}
	else if (_operator == "-")
	{
		return StandardResult(A - B, base);
	}
	else if (_operator == "*")
	{
		return StandardResult(A * B, base);
	}
	else if (_operator == "/")
	{
		return StandardResult(A / B, base);
	}
	else if (_operator == "&")
	{
		return StandardResult(A & B, base);
	}
	else if (_operator == "|")
	{
		return StandardResult(A | B, base);
	}
	else if (_operator == "^")
	{
		return StandardResult(A ^ B, base);
	}
	else if (_operator == "<<")
	{
		int nums = stoi(numB);
		return StandardResult(A << nums, base);
	}
	else if (_operator == ">>")
	{
		int nums = stoi(numB);
		return StandardResult(A >> nums, base);
	}
	else if (_operator == "rol")
	{
		int nums = stoi(numB);
		return StandardResult(A.rol(nums), base);
	}
	else if (_operator == "ror")
	{
		int nums = stoi(numB);
		return StandardResult(A.ror(nums), base);
	}
	else if (_operator == "<")
	{
		return ((A < B) ? "TRUE" : "FALSE");
	}
	else if (_operator == ">")
	{
		return ((A > B) ? "TRUE" : "FALSE");
	}
	else if (_operator == "<=")
	{
		return ((A <= B) ? "TRUE" : "FALSE");
	}
	else if (_operator == ">=")
	{
		return ((A >= B) ? "TRUE" : "FALSE");
	}
	else if (_operator == "==")
	{
		return ((A == B) ? "TRUE" : "FALSE");
	}
}


//Xử lí với số nguyên lớn và trả kết quả về chuỗi string
std::string processQint(std::string inputString)
{
	std::string UnaryOperator = "~";
	std::vector<std::string> BinaryOperator = { "+"," - ","*","/","<",">","<=",">=","==","&","|","^","<<",">>","rol","ror" };

	int OperatorType = 0;
	int ArgumentCount = 1;

	//Đếm số lượng tham số
	for (int i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == ' ')
			ArgumentCount++;
	}
	//Tìm Toán tử 1 ngôi trong chuỗi
	for (int i = 0; i < UnaryOperator.size(); i++)
	{
		if (inputString.find(UnaryOperator[i], 0) != std::string::npos)
		{
			OperatorType = 1;
			break;
		}
	}
	//Tìm Toán tử 2 ngôi trong chuỗi
	if (OperatorType == 0)
	{
		for (int i = 0; i < BinaryOperator.size(); i++)
		{
			if (inputString.find(BinaryOperator[i], 0) != std::string::npos)
			{
				OperatorType = 2;
				break;
			}
		}
	}

	std::string p1, p2, _operator, num1, num2;
	std::stringstream ss;

	ss << inputString;
	ss >> p1;

	//Kiểm tra có chỉ thị p2 hay không
	if (ArgumentCount - OperatorType == 3)
		ss >> p2;
	else
		p2 = p1;

	//Kiểu tra toán tử
	_operator = "";
	switch (OperatorType)
	{
	case 0:	//Không có toán tử
		ss >> num1;
		break;
	case 1: //Toán tử 1 ngôi
		ss >> _operator >> num1;
		break;
	case 2:	//Toán tử 2 ngôi
		ss >> num1 >> _operator >> num2;
		break;
	}


	//Trường hợp không có toán tử, thực hiện chuyển đổi giữa các toán hạng
	int base1 = stoi(p1);
	int base2 = stoi(p2);

	if (_operator == "")
	{
		if ((base1 == 2) && (base2 == 16))
		{
			Qint A;
			std::string Hex = Convert::Instance()->ConvertBinToHex(num1);
			return Hex;
			std::cout << std::endl;
		}
		else if ((base1 == 2) && (base2 == 10))
		{
			Qint A;
			return (A.BinToDec(num1)).ToString();
			std::cout << std::endl;
		}
		else if ((base1 == 10) && (base2 == 16))
		{
			Qint A(num1);
			std::string Hex = A.DecToHex();
			return Hex;
			std::cout << std::endl;
		}
		else if ((base1 == 10) && (base2 == 2))
		{
			Qint A(num1);
			std::string bits = A.DecToBin(true);
			return bits;
			std::cout << std::endl;
		}
		else if ((base1 == 16) && (base2 == 2))
		{
			std::string Bin = Convert::Instance()->ConvertHexToBin(num1);
			return Bin;
		}
		else if ((base1 == 16) && (base2 == 10))
		{
			Qint A;
			return (A.HexToDec(num1)).ToString();
		}
	}

	//Trường hợp có toán tử, xử lí các toán hạng với toán tử
	if (base1 == base2)
	{
		switch (base1)
		{
		case 2:
		{
			Qint A;
			Qint B;

			A = Qint::BinToDec(num1);
			B = Qint::BinToDec(num2);

			return processOperator(A, B, num2, _operator, base1);
		}
		break;
		case 10:
		{
			Qint A(num1);
			Qint B(num2);

			return processOperator(A, B, num2, _operator, base1);
		}
		break;
		case 16:
		{
			Qint A = Qint::HexToDec(num1);
			Qint B = Qint::HexToDec(num2);
			return processOperator(A, B, num2, _operator, base1);
		}
		break;
		}

	}

}

std::string processQfloat(std::string inputString)
{
	std::string p1, p2, number;
	std::stringstream ss;

	ss << inputString;
	ss >> p1 >> p2 >> number;

	if ((stoi(p1) == 2) && (stoi(p2) == 10))
	{
		Qfloat floatNum(number, true);
		return floatNum.ToString();
	}
	else
	{
		Qfloat floatNum(number);
		return floatNum.DecToBin();
	}
}


int main(int argc, char** argv)
{
	std::string file_in, file_out, type;
	if (argc < 4)
		std::cout << "invalid data!";
	else
	{
		file_in = std::string(argv[1]);
		file_out = std::string(argv[2]);
		type = std::string(argv[3]);

		Utils::Instance()->StandardFileName(file_in);
		Utils::Instance()->StandardFileName(file_out);

		std::vector<std::string> list = Utils::ReadFile(file_in);

		std::ofstream fout;
		fout.open(file_out, std::ios_base::out);

		if (fout.fail() == true)
			std::cout << "File is inavailable!\n";
		else
		{
			if (type == "1")
				for (int i = 0; i < list.size(); i++)
				{
					fout << processQint(list[i]) << "\n";
				}
			else
				for (int i = 0; i < list.size(); i++)
				{
					fout << processQfloat(list[i]) << "\n";
				}
		}

		fout.close();
	}
}