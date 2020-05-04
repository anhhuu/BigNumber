#pragma once
#include <string>
#include <map>
class Utils
{

public:
	//Cộng 2 số nguyên lớn ở dạng chuỗi
	//Kết quả trả về là số nguyên lớn dạng chuỗi
	//exs: "23565432456754322356543245675432" + "24567543245676543456"
	static std::string AddTwoIntString(std::string num1, std::string num2);

	//Chia số nguyên lớn cho 2
	//Trả về kết quả của phép chia là một số nguyên lớn dạng chuỗi
	//exs: "23565432456754322356543245675432" / "2"
	static std::string DivideNumStringForTwo(std::string num);

	//Nhân số nguyên lớn dạng chuỗi với một số nguyên (int)
	//Kêt quả trả về một số nguyên lớn
	//exs: "1" * "24567543245676543456"
	static std::string MultiplyNumStringWithOneDigit(std::string num1, int num2);

	//Nhân 2 số nguyên lớn dạng chuỗi với nhau
	//Kết quả trả về một số nguyên lớn dạng chuỗi
	//exs: "23565432456754322356543245675432" * "24567543245676543456"
	static std::string MultiplyNumString(std::string num1, std::string num2);

	//Lũy thừa một số nguyên với số mũ
	//Trả về số nguyên lớn dạng chuỗi
	//exs: 2^72 = ? 
	static std::string PowOneDigit(int factor, int exp);

	//Lũy thừa số 2 với mũ âm
	//Trả về số nguyên lớn dạng chuỗi
	//exs: 2^-72 = ? 
	static std::string NegativePowTwo(unsigned int exp);

	static std::string AddTwoDecWithPoint(std::string num1, std::string num2);
private:
	//Tìm số lớn nhất giữa 2 chuỗi
	static std::string FindMaxNumString(std::string num1, std::string num2);

public:

	//Thực hiện trừ hai số với nhau
	//Nhận vào số trừ và số bị trừ
	//Trả về kết quả của phép trừ
	static std::string SubtractTwoSNumString(std::string num1, std::string num2);

private:
	static  std::map<std::string, std::string> _mapBinToHex;

public:

	//Lấy ra map kết quả chứa thông tin phép chuyển theo từng bộ 4 bit bin sang hex
	//Không tham số đầu vào
	//Trả về std::map<std::string,std::string>
	static std::map<std::string, std::string> GetMapBinToHex();

	//Nhân một thập phân với 2
	//Nhận vào một số thập phân
	//Trả ra kết quả đã nhân với 2 ở dạng chuỗi
	static std::string MultiplyNumberWithTwo(std::string number);

};
