#include <algorithm>
#include "Convert.h"
#include "Utils.h"

std::string Convert::CovertNumStringToBin(std::string num)
{
    std::string result;

    while (num != "") 
    {
        result += std::to_string((num[num.length() - 1] - '0') % 2);
        num = Utils::DivideNumStringForTwo(num);
    }

    std::reverse(result.begin(), result.end());

    return result;
}

std::string Convert::CovertBinToNumString(std::string bits)
{
	return std::string();
}
