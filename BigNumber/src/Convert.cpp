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
	return std::string();
}

void Convert::ConvertBitsToTwoComplement(std::string &bits, bool sign)
{
    if (sign)
    {
        BitProcess::ReverseBits(bits);
        bits = BitProcess::AddTwoBits(bits, "1");
    }
}
