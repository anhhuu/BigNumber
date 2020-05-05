#pragma once
#include <string>
#include <map>
#include <memory>

class Utils
{
public:
	static std::unique_ptr<Utils>& Instance();

public:
	//Cộng 2 số nguyên lớn ở dạng chuỗi
	//Kết quả trả về là số nguyên lớn dạng chuỗi
	//exs: "23565432456754322356543245675432" + "24567543245676543456"
	std::string AddTwoIntString(std::string num1, std::string num2);

	//Chia số nguyên lớn cho 2
	//Trả về kết quả của phép chia là một số nguyên lớn dạng chuỗi
	//exs: "23565432456754322356543245675432" / "2"
	std::string DivideNumStringForTwo(std::string num);

	//Nhân số nguyên lớn dạng chuỗi với một số nguyên (int)
	//Kêt quả trả về một số nguyên lớn
	//exs: "1" * "24567543245676543456"
	std::string MultiplyNumStringWithOneDigit(std::string num1, int num2);

	//Nhân 2 số nguyên lớn dạng chuỗi với nhau
	//Kết quả trả về một số nguyên lớn dạng chuỗi
	//exs: "23565432456754322356543245675432" * "24567543245676543456"
	std::string MultiplyNumString(std::string num1, std::string num2);

	//Lũy thừa một số nguyên với số mũ
	//Trả về số nguyên lớn dạng chuỗi
	//exs: 2^72 = ? 
	std::string PowOneDigit(int factor, int exp);

	//Lũy thừa số 2 với mũ âm
	//Trả về số nguyên lớn dạng chuỗi
	//exs: 2^-72 = ? 
	std::string NegativePowTwo(unsigned int exp);

	std::string AddTwoDecWithPoint(std::string num1, std::string num2);
public:

	//Thực hiện trừ hai số với nhau
	//Nhận vào số trừ và số bị trừ
	//Trả về kết quả của phép trừ
	std::string SubtractTwoSNumString(std::string num1, std::string num2);

public:

	//Lấy ra map kết quả chứa thông tin phép chuyển theo từng bộ 4 bit bin sang hex
	//Không tham số đầu vào
	//Trả về std::map<std::string,std::string>
	std::map<std::string, std::string> GetMapBinToHex();

	//Nhân một thập phân với 2
	//Nhận vào một số thập phân
	//Trả ra kết quả đã nhân với 2 ở dạng chuỗi
	std::string MultiplyNumberWithTwo(std::string number);

private:
	Utils();

public:
	Utils(const Utils&) = delete;
	void operator=(const Utils&) = delete;


	//Tìm số lớn nhất giữa 2 chuỗi
	std::string FindMaxNumString(std::string num1, std::string num2);

private:
	static std::unique_ptr<Utils> m_pInstance;

	static std::map<std::string, std::string> _mapBinToHex;

};
