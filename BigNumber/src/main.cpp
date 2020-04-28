#include <iostream>
#include "Qint.h"
#include "Qfloat.h"
#include "Convert.h"
#include "BitProcess.h"

int main()
{
	std::string e = "00100111";
	e.insert(e.begin(), '0');
	e.erase(8, 1);

	std::string bits = "00001010100010010101111010101001010101001001010101000100101011110101010010101010010010101010001001010111101010100100000000000001111";
	unsigned char data[16] = { 0 };
	
	BitProcess::SetBit(data, bits);
	std::cout << BitProcess::GetBit(data);

	std::cout << std::endl;

	std::string bin  = Convert::CovertBinToNumString("654324567543245675435678");
	system("pause");
	return 0;
}