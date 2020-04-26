#include <iostream>
#include "Qint.h"
#include "Qfloat.h"
#include "Utils.h"
#include "Convert.h"
#include "BitProcess.h"

int main()
{
	/*std::string bits = "00001010100010010101111010101001010101001001010101000100101011110101010010101010010010101010001001010111101010100100000000000001111";
	unsigned char data[16] = { 0 };
	
	BitProcess::SetBit(data, bits);
	std::cout << BitProcess::GetBit(data);

	std::cout << std::endl;*/
	
	std::cout << Utils::MultiplyNumStringWithOneDigit("12345",5);
	std::cout << std::endl;
	std::cout << Utils::MultiplyNumString("8793278316383117319", "123456789");
	std::cout << std::endl;
	system("pause");
	return 0;
}