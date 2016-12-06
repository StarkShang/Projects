#include <iostream>
#include "String.h"

int main(int argc, char* argv[])
{
	char buffer[1025];
	std::cout << "Please input a sentence(less than 1024) : ";
	std::cin >> buffer;
	String str1(buffer);
	String str2(str1);
	char* str3 = str1.GetCString();

	std::cout << "The content of str3 : " << str3 << std::endl;

	return 0;
}