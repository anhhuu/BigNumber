#include "BitProcess.h"

bool BitProcess::GetBit(const unsigned char memory, const unsigned int& pos)
{
	return (memory >> BITS_OF_CELL - 1 - pos % BITS_OF_CELL) & 1;
}

void BitProcess::SetBitOne(unsigned char& memory, const unsigned int& pos)
{
	memory = (1 << BITS_OF_CELL - 1 - pos % BITS_OF_CELL) | memory;
}

void BitProcess::SetBitZero(unsigned char& memory, const unsigned int& pos)
{
	memory = (~(1 << BITS_OF_CELL - 1 - pos % BITS_OF_CELL)) & memory;
}

void BitProcess::StandardBits(std::string& bits, const unsigned int &numOfBits)
{
	unsigned int i = bits.size();

	if (i > numOfBits)
	{
		unsigned int numErase = i - numOfBits;
		bits.erase(0, numErase);
	}

	while (i < numOfBits)
	{
		bits.insert(bits.begin(), '0');
		i++;
	}
}

std::string BitProcess::GetBit(const unsigned char memmory[MAX_CELL])
{
	std::string temp;
	for (int i = 0; i < BITS_OF_CELL * MAX_CELL; i++)
	{
		bool bit = BitProcess::GetBit(memmory[i / BITS_OF_CELL], i);
		if (bit == true)
		{
			temp += '1';
		}
		else
		{
			temp += '0';
		}
	}
	return temp;
}

void BitProcess::SetBit(unsigned char memmory[MAX_CELL], std::string bits)
{
	StandardBits(bits, MAX_CELL * BITS_OF_CELL);
	memset(memmory, 0, MAX_CELL);
	for (int i = 0; i < bits.size(); i++)
	{
		if (bits[i] == '0')
		{
			BitProcess::SetBitZero(memmory[i / BITS_OF_CELL], i % BITS_OF_CELL);
		}
		else
		{
			BitProcess::SetBitOne(memmory[i / BITS_OF_CELL], i % BITS_OF_CELL);
		}
	}
}

void BitProcess::ReverseBits(std::string& bits)
{
	for (unsigned int i = 0; i < bits.size(); i++)
	{
		if (bits[i] == '0')
		{
			bits[i] = '1';
		}
		else
		{
			bits[i] = '0';
		}
	}
}

std::string BitProcess::AddTwoBits(std::string bits1, std::string bits2)
{
	BitProcess::StandardBits(bits1, BITS_OF_CELL * MAX_CELL);
	BitProcess::StandardBits(bits2, BITS_OF_CELL * MAX_CELL);

	std::string result = "";
	unsigned int reminder = 0;
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	unsigned int tempResult = 0;
	for (int i = 127; i >= 0; i--)
	{
		num1 = bits1[i] - '0';
		num2 = bits2[i] - '0';
		tempResult = num1 + num2 + reminder;
		if (tempResult == 3)
		{
			result += "1";
			reminder = 1;
		}
		else if (tempResult == 2)
		{
			result += "0";
			reminder = 1;
		}
		else
		{
			result += std::to_string(tempResult);
			reminder = 0;
		}
	}
	std::reverse(result.begin(), result.end());
	BitProcess::StandardBits(result, BITS_OF_CELL * MAX_CELL);
	return result;
}

std::string BitProcess::SubtractTwoBits(std::string bits1,std::string bits2){
    
    std::string processedBits2 = Utils::ReverseBitsAndPlusOne(bits2);
    std::string result = BitProcess::AddTwoBits(bits1, processedBits2);
    return result;
    
}

std::string BitProcess::MultiplyTwoBits(std::string bits1,std::string bits2){
    

    int k = bits2.length();
    
    std::string A = std::string(128,'0');
    char Q_1 = '0';
    std::string Q = bits2;
    const std::string M = bits1;
    
    
    while (k>0) {
        
        int QLength = Q.length();
        
        if(Q[QLength-1]=='1' && Q_1 == '0'){
            
            A = BitProcess::SubtractTwoBits(A, M);
            
        }else if(Q[QLength-1] == '0' && Q_1 == '1'){
            
            A = BitProcess::AddTwoBits(A, M);
            
        }else if((Q[QLength-1] == '0'&& Q_1 == '0') ||
                 (Q[QLength-1] =='1' && Q_1 == '1')) {
            
            //DoNothing
            
        }
        
        BitProcess::ShiftRightThreeBits(A, Q, Q_1);
        
        k--;
    }
    std::string result = A+Q;
    auto length = result.length();
    
    BitProcess::StandardBits(result, 128);
    
    return result ;
    
}

void BitProcess::ShiftRightThreeBits(std::string &A,std::string &Q,char &Q_1){
    
    std::string concatenatedBits = A+Q;
    Q_1 = Q[Q.length()-1];
    concatenatedBits.insert(0, "0");
    
    A = concatenatedBits.substr(0,A.length());
    Q = concatenatedBits.substr(A.length(),Q.length());
    
    
    
}
