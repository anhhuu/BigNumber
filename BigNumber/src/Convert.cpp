#include "Convert.h"
#include <algorithm>
#include "Convert.h"
#include "Utils.h"
#include "BitProcess.h"

std::string Convert::CovertNumStringToBin(std::string num)
{
    std::string result;
    unsigned int index = 0;
    bool negative = num[0] == '-';    

    while (num != "0") 
    {
        result += std::to_string((num[num.length() - 1] - '0') % 2);
        num = Utils::DivideNumStringForTwo(num);
    }

    std::reverse(result.begin(), result.end());

    BitProcess::StandardBits(result, 128);

    if (negative)
    {
        ConvertBitsToTwoComplement(result, true);
    }

    return result;
}

std::string Convert::CovertBinToNumString(std::string bits)
{
	int index = 0;
	std::string decResult = "0";
	int length = bits.length();
	bool isNegativeNumber = bits[0] == '1';
	
	//Nếu kết quả phép chuyển là số âm chuyển về bit của số dương để thực hiện tính toán nhanh hơn
	if (isNegativeNumber) 
	{
		ConvertBitsToTwoComplement(bits, true);
	}
	
	bool sign = false;

	while (index < length)
	{
		int exp = length - 1 - index;
		if (bits[index] == '1') {
			if (bits[index] == '1' && index == 0) 
			{
				sign = true; //Sau khi đảo chuyển từ bù 2 về dạng nhị phân bình thường vẫn còn bit dấu thì lưu giá trị cờ
				index++;
				continue;
			}
			else
			{
				decResult = Utils::AddTwoIntString(decResult, Utils::PowOneDigit(2, exp));
			}
		}
		
		index++;
	}

	if (sign)
	{
		decResult = Utils::SubtractTwoSNumString(decResult, Utils::PowOneDigit(2, 127));
		//Trường hợp số nhỏ nhất -2^127
	}
	else if (isNegativeNumber) 
	{
		decResult.insert(0, "-");
	}

	return decResult;

}

void Convert::ConvertBitsToTwoComplement(std::string &bits, bool sign)
{
    if (sign)
    {
        BitProcess::ReverseBits(bits);
        bits = BitProcess::AddTwoBits(bits, "1");
    }
}

std::string Convert::ConvertBinToHex(std::string bits){
    
    std::string result = "";
    auto mapBinToHex = Utils::GetMapBinToHex();
    for(int i = 0;i<MAX_CELL*BITS_OF_CELL;i+=4){
        
        result+=mapBinToHex[bits.substr(i,4)];
        
    }
    return result;
}


std::string Convert::ConvertBitFromBoolToString(const bool * bits){
    
    std::string result = "";
    for(int i = 0;i<MAX_CELL*BITS_OF_CELL;i++)
        result+=bits[i]?'1':'0';
    
    return result;
    
    
}
 
bool * Convert::ConvertBitFromStringToBool(std::string bits){
    
    
    bool result[MAX_CELL*BITS_OF_CELL];
    for(int i = 0;i<MAX_CELL*BITS_OF_CELL;i++)
        result[i] = bits[i] == '1'?true:false;
  
    return result;
}

std::string Convert::ConvertDecToHex(std::string number){
    return nullptr;
}
