#include "Utils.h"
#include "BitProcess.h"
#include <string>
#include <utility>
std::string Utils::AddTwoIntString(std::string num1, std::string num2)
{
	std::string result = "";
	int reminder = 0;
	int pointerNum1 = num1.length() - 1;
	int pointerNum2 = num2.length() - 1;
	int resultOfAddingTwoNum = 0;

	while (pointerNum1 >= 0 && pointerNum2 >= 0)
	{
		resultOfAddingTwoNum = num1[pointerNum1] + num2[pointerNum2] + reminder - 2 * 48;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum1--;
		pointerNum2--;

	}

	while (pointerNum1 >= 0)
	{
		resultOfAddingTwoNum = num1[pointerNum1] - 48 + reminder;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum1--;
	}

	while (pointerNum2 >= 0)
	{
		resultOfAddingTwoNum = num2[pointerNum2] - 48 + reminder;

		reminder = resultOfAddingTwoNum / 10;
		resultOfAddingTwoNum %= 10;

		std::string s = "";
		s += resultOfAddingTwoNum + 48;

		result.insert(0, s);
		resultOfAddingTwoNum = 0;
		pointerNum2--;
	}

	if (reminder != 0)
	{
		std::string s = "";
		s += reminder + 48;

		result.insert(0, s);
	}

	return result;
}


short Utils::StringToShort(std::string input)
{

	short result = 0;
	for (int i = 0; i < input.length(); i++)
	{
		result = result * 10 + input[i] - 48;
	}
	return result;
}

std::string Utils::DivideNumStringForTwo(std::string num)
{
    unsigned int index = 0;
    if (num[0] == '-' || num[0] == '+')
    {
        index++;
    }
    
    unsigned int dividendNum = 0;
    unsigned int surplus = 0;
    unsigned int resultTemp = 0;
    std::string resultStr = "";
    
    while (index < num.length())
    {
        dividendNum = (dividendNum * 10) + num[index] - '0';
        resultTemp = dividendNum / 2;
        surplus = dividendNum % 2;
        
        if (surplus != 0)
        {
            dividendNum = surplus;
        }
        else
        {
            dividendNum = 0;
        }
        resultStr += std::to_string(resultTemp);
        index++;
    }
    
    if (resultStr[0] == '0' && resultStr.length() > 1)
    {
        resultStr.erase(0, 1);
    }
    
    return resultStr;
}

std::string Utils::MultiplyNumStringWithOneDigit(std::string num1, int num2)
{
	int r = 0;
	std::string q = "";

	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int k = (int)(num1[i] - '0');
		int temp = (k * num2) + r;

		if (temp > 9)
		{
			r = temp / 10;
			temp = temp % 10;
			q = std::to_string(temp) + q;
		}
		else
		{
			q = std::to_string(temp) + q;
			r = 0;
		}
	}
	if (r > 0)
		q = std::to_string(r) + q;

	return std::string(q);
}

std::string Utils::MultiplyNumString(std::string num1, std::string num2)
{
	std::string q = "";
	std::string zero = "";
	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int k = (int)(num1[i] - '0');

		std::string temp = Utils::MultiplyNumStringWithOneDigit(num2, k) + zero;

		zero = zero + "0";

		q = AddTwoIntString(q, temp);

	}
	return std::string(q);
}

std::string Utils::PowOneDigit(int factor, int exp)
{
	std::string result = "1";

	for (int i = 0; i < exp; i++)
	{
		result = MultiplyNumStringWithOneDigit(result, factor);
	}
	return result;
}

std::string Utils::NegativePowTwo(unsigned int exp)
{
	std::string str = "5";
	for (int i = 1; i < exp; i++)
	{
		str.push_back('0');												
	}
	for (int i = 1; i < exp; i++)
	{
		str = DivideNumStringForTwo(str);								
	}
	str.insert(str.begin(), exp - str.size(), '0');						
	str = "0." + str;													
	return str;
}

std::string Utils::FindMaxNumString(std::string num1, std::string num2)
{
	int lengthNum1 = num1.length();
	int lengthNum2 = num2.length();

	if (lengthNum1 > lengthNum2)
	{
		return num1;
	}
	else if (lengthNum1 < lengthNum2)
	{
		return num2;
	}

	//Trường hợp 2 chuỗi có độ dài bằng nhau
	int index = 0;
	if (num1 == num2) return num1;


	while (index < lengthNum1 && num1[index] == num2[index])
	{
		index++;
	}

	if (num1[index] - num2[index] > 0)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

std::string Utils::SubtractTwoSNumString(std::string num1, std::string num2)
{
    if (num1 == num2) return "0";
    
    std::string result = "";
    std::string subtrahend = FindMaxNumString(num1, num2);
    std::string minuend = subtrahend == num1 ? num2 : num1;
    int reminder = 0;
    int tempResult = 0;
    int pointerSubtrahend = subtrahend.length() - 1;
    int pointerMinuend = minuend.length() - 1;
    
    
    while (pointerSubtrahend >= 0) {
        
        if (pointerMinuend>=0) {
            tempResult = subtrahend[pointerSubtrahend] - minuend[pointerMinuend] - reminder;
        }
        else {
            tempResult = subtrahend[pointerSubtrahend]  - reminder-'0';
        }
        
        
        if (tempResult < 0) {
            if (pointerMinuend >= 0) {
                tempResult = subtrahend[pointerSubtrahend] +10 - minuend[pointerMinuend] - reminder;
            }
            else {
                tempResult = subtrahend[pointerSubtrahend] +10  - reminder-'0';
            }
            reminder = 1;
            
        }
        else {
            reminder = 0;
            
        }
        result.insert(0, std::to_string(tempResult));
        pointerSubtrahend--;
        pointerMinuend--;
    }
    
    if (subtrahend == num2)
    {
        result.insert(0, "-");
    }
    
    int lengthResult = result.length();
    //Xóa những số 0 thừa
    int currentPos = 0;
    //
    int minimumLength = 2;
    
    if (result[0] == '-')
    {
        currentPos++;
        minimumLength++;
    }
    
    while (currentPos < lengthResult && result[currentPos] == '0' && lengthResult>=minimumLength)
    {
        result.erase(currentPos, 1);
        lengthResult = result.length();
    }
    
    return result;
}

std::map<std::string, std::string> Utils::_mapBinToHex = {
    {"0000","0"},
    {"0001","1"},
    {"0010","2"},
    {"0011","3"},
    {"0100","4"},
    {"0101","5"},
    {"0110","6"},
    {"0111","7"},
    {"1000","8"},
    {"1001","9"},
    {"1010","A"},
    {"1011","B"},
    {"1100","C"},
    {"1101","D"},
    {"1110","E"},
    {"1111","F"}

};

std::map<std::string,std::string> Utils::GetMapBinToHex(){      
 
    return _mapBinToHex;
    
}

std::string Utils::DevideNumDecForSixteen(std::string num){
    
    std::string result = "";
    
    int index = 0;
    bool isNegative = false;
   
    if(num[0] == '-'){
        index++;
        isNegative = true;
    }
    
    int length = num.length();
    int reminder = 0;
    
    //currentNumber <=99
    int currentNumber = 0;
    
    
    while(index<length){
        
        currentNumber = currentNumber*10 + num[index]- '0';
        if(currentNumber>=16){
            result+=currentNumber/16 + '0';
            currentNumber%=16;
        }else{
            result+='0';
        }
        index++;
        
    }
    size_t currentLength = result.length();
    index = 0;
    while(currentLength>1&&result[index] == '0'){
        result.erase(index,1);
        currentLength = result.length();
    }
   
    
    return result;
    
}


std::string Utils::ReverseBitsAndPlusOne(std::string bits){
   
    BitProcess::ReverseBits(bits);
    std::string result = BitProcess::AddTwoBits(bits, "1");
    return result;
    
}

std::string Utils::ConvertPartAfterBinaryPointToBits(std::string number){
    
    return nullptr;
    
}


std::string Utils::MultiplyNumberWithTwo(std::string number){
    
    unsigned long posOfDot = number.find(".");
    
    if(posOfDot == std::string::npos){
        return Utils::MultiplyNumStringWithOneDigit(number, 2);
    }
    int reminder = 0;
    int tempResult = 0;
    bool hasMetPoint = false;
    std::string result = number;
    
    for(int i = number.length()-1;i>=0;i--){
        
        if(number[i]!='.'){
            
            tempResult = (number[i]-'0') *2 + reminder;
            
            reminder = tempResult/10;
            tempResult %= 10;
            result[i] = tempResult + '0';
            
            if(hasMetPoint && i == 0 && reminder!=0){
                result.insert(0, std::to_string(reminder));
            }
                        
            
            
        }else{
            hasMetPoint = true;
        }
        
        
    }
    
 
    return result;
    
}
