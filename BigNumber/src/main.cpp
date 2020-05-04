#include <iostream>
#include "Qint.h"
#include "Qfloat.h"
#include "Utils.h"
#include "Convert.h"
#include "BitProcess.h"
#include "Utils.h"
#include <time.h>
#include <bitset>

#include <stdint.h>
#include <cstdint>

void testTask1_2()
{
	Qint aBig("0");
	Qint bBig("0");
	long long int a = 0;
	long long int b = 0;

	std::cout << "input int a = "; std::cin >> a;
	//aBig = Qint(std::to_string(a));
	std::cin >> aBig;

	std::cout << "input int b = "; std::cin >> b;
	//bBig = Qint(std::to_string(b));
	std::cin >> bBig;

	std::cout << std::endl;

	std::cout << "a \t\t= " << a << std::endl;
	std::cout << "aBig \t\t= " << aBig << std::endl;

	std::cout << "b \t\t= " << b << std::endl;
	std::cout << "bBig \t\t= " << bBig << std::endl;

	std::cout << "a + b \t\t= " << (a + b) << std::endl;
	std::cout << "aBig + bBig \t= " << (aBig + bBig) << std::endl;

	std::cout << "a - b \t\t= " << (a - b) << std::endl;
	std::cout << "aBig - bBig \t= " << (aBig - bBig) << std::endl;

	std::cout << "a * b \t\t= " << (a * b) << std::endl;
	std::cout << "aBig * bBig \t= " << (aBig * bBig) << std::endl;

	std::cout << "a / b \t\t= " << (a / b) << std::endl;
	std::cout << "aBig / bBig \t= " << (aBig / bBig) << std::endl;

	std::cout << "a & b \t\t= " << (a & b) << std::endl;
	std::cout << "aBig & bBig \t= " << (aBig & bBig) << std::endl;

	std::cout << "a | b \t\t= " << (a | b) << std::endl;
	std::cout << "aBig | bBig \t= " << (aBig | bBig) << std::endl;

	std::cout << "a ^ b \t\t= " << (a ^ b) << std::endl;
	std::cout << "aBig ^ bBig \t= " << (aBig ^ bBig) << std::endl;

	std::cout << "~a \t\t= " << (~a) << std::endl;
	std::cout << "~aBig \t\t= " << (~aBig) << std::endl;

	std::cout << "a << 5 \t\t= " << (a << 5) << std::endl;
	std::cout << "aBig << 5 \t= " << (aBig << 5) << std::endl;

	std::cout << "a >> 2 \t\t= " << (a >> 2) << std::endl;
	std::cout << "aBig >> 2 \t= " << (aBig >> 2) << std::endl;

	std::cout << std::endl;

	std::cout << "aBig > bBig: \t" << ((aBig > bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig < bBig: \t" << ((aBig < bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig == bBig: \t" << ((aBig == bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig != bBig: \t" << ((aBig != bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig >= bBig: \t" << ((aBig >= bBig) ? "true" : "false") << std::endl;
	std::cout << "aBig <= bBig: \t" << ((aBig <= bBig) ? "true" : "false") << std::endl;

	std::cout << std::endl;

	std::cout << "input a Big num: ";
	Qint cBig;
	cBig.ScanQInt();
	bool* bits = cBig.DecToBin();
}

void showRawBitFloat(std::string str)
{
	for (unsigned int i = 0; i < NUM_OF_EXPONENT_BITS + NUM_OF_SIGNIFICANT_BITS + 1; i++)
	{
		if (i == 1 || i == 1 + NUM_OF_EXPONENT_BITS)
		{
			std::cout << std::endl;
		}
		std::cout << str[i];
	}
}

int main()
{
	//testTask1();
	std::string floatNum;
	while (true)
	{
		std::cin >> floatNum;
		showRawBitFloat(Convert::ConvertFloatToBin(floatNum));
		std::cout << std::endl;
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
