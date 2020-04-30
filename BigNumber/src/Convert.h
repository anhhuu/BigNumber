#pragma once
#include <string>
#include "Utils.h"

class Convert
{
public:
    static void ConvertBitsToTwoComplement(std::string& bits, bool sign);
    
    //Chuyển đổi một số nguyên hệ 10 sang chuỗi nhị nhân
    //Nhận vào số nguyên định dạng chuỗi
    //Trả về chuỗi chứa các bit ở dạng bù 2
    static std::string CovertNumStringToBin(std::string num);
    
    //Chuyển đổi một chuỗi bit sang số nguyên
    //Nhận vào chuỗi bit
    //Trả về số nguyên dạng chuỗi
    static std::string CovertBinToNumString(std::string bits);
    
    //Chuyển đổi một chuỗi bit sang mã hex
    //Nhận vào chuỗi bits
    //Trả về chuỗi hex
    static std::string ConvertBinToHex(std::string bits);
    
    //Thực hiện việc chuyển đổi chuỗi bits mảng bool sang string
    //Nhận vào mảng bool
    //Trả về chuỗi string
    static std::string ConvertBitsFromBoolToString(const bool * bits);
    
    //Thực hiện chuyển đổi chuỗi bit từ string sang mảng bool
    //Nhận vào chuỗi bits kiểu dữ liệu string
    //Trả về mảng bool chứa tất cả các bits
    static bool * ConvertBitsFromStringToBool(std::string bits);
    
};
