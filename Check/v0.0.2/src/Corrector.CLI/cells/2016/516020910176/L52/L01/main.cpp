#include <iostream>
#include "func__.hpp"

int main(int argc, char* argv[])
{
	char num1[1024], num2[1024], buffer[1025];
	std::cout << "Please input the first number : ";
	std::cin >> num1;
	std::cout << "Please input the second number : ";
	std::cin >> num2;
	char *sum = addTwoNumbers(num1, num2, buffer, 1025);
	std::cout << "The sum of tow numbers : " << sum << std::endl;
	return 0;
}