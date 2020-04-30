#pragma once
#include <string>
#include <map>
class Utils
{
    
public:
    //Cộng 2 số nguyên lớn ở dạng chuỗi
    //Kết quả trả về là số nguyên lớn dạng chuỗi
    static std::string AddTwoIntString(std::string num1, std::string num2);
    //Chuyển đổi một số nguyên dạng chuỗi về kiểu dữ liệu short
    static short StringToShort(std::string input);
    
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
    
private:
    //Tìm số lớn nhất giữa 2 chuỗi
    static std::string FindMaxNumString(std::string num1, std::string num2);
    
public:
    
    //Thực hiện trừ hai số với nhau
    //Nhận vào số trừ và số bị trừ
    //Trả về kết quả của phép trừ
    static std::string SubtractTwoSNumString(std::string num1, std::string num2);

private:
    inline static std::map<std::string,std::string> _mapBinToHex;
    
    //Kiểm soát việc khởi tạo giá trị cho map quá nhiều lần
    inline static bool calledLazyFunctionBinToHex = false;
    
    //Lấy ra map kết quả chứa thông tin phép chuyển theo từng bộ 4 bit bin sang hex
    //Không tham số đầu vào
    //Trả về std::map<std::string,std::string>
public: static std::map<std::string,std::string> GetMapBinToHex();
    
    //Thực hiện chia một số cho 16
    //Nhận vào một số hệ 10
    //Trả về kết quả phép chia param/16 kết quả chia lấy nguyên
    static std::string DevideNumDecForSixteen(std::string num);
    
    //Đảo bit đồng thời cộng 1 vào chuỗi bits vừa đảo
    //Nhận vào một chuỗi bits
    //Trả về 1 chuỗi bit đã được đảo ngược và cộng 1
    static std::string ReverseBitsAndPlusOne(std::string bits);
};
