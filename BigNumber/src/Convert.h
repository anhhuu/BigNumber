#pragma once

#include <string>

class Convert
{
public:
	//convert number decimal string to binary string
	//return a string result 
	static std::string CovertNumStringToBin(std::string num);

	//convert binary string to number string
	//return a string result 
	//34655465367654736573576 to bin = ?
	static std::string CovertBinToNumString(std::string num);

	
};
