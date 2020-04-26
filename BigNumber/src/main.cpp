#include <iostream>
#include "Qint.h"
#include "Qfloat.h"
#include "Utils.h"
#include "Convert.h"
#include "BitProcess.h"
#include "Utils.h"

int main()
{
	/*std::string bits = "00001010100010010101111010101001010101001001010101000100101011110101010010101010010010101010001001010111101010100100000000000001111";
	unsigned char data[16] = { 0 };
	
	BitProcess::SetBit(data, bits);
	std::cout << BitProcess::GetBit(data);

	std::cout << std::endl;*/

	//Debug
	//std::cout<<Utils::AddTwoIntString("348794823723798", "312");
	//std::cout<<Convert::CovertNumStringToBin("12");
	std::string number = "12345677889999";
	std::string binResult = Convert::CovertNumStringToBin(number);
	std::cout << "Bin result: " << binResult << std::endl;
	std::cout << "number: " << Convert::CovertBinToNumString(binResult);







	system("pause");
	return 0;
}