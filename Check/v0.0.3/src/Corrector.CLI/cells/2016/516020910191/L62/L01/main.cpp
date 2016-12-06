#include <iostream>
#include "Summator.h"
#include "Subtractor.h"

int main(int argc, char* argv[])
{
	float num1, num2;
	Summator* summator = new Summator();
	Subtractor* subtractor = new Subtractor();

	std::cout << "Please input 2 numbers : ";
	std::cin >> num1 >> num2;
	summator->Add(num1, num2);
	subtractor->Sub(num1, num2);

	std::cout << "Summator.Calculate : " << summator->GetResult() << std::endl;
	std::cout << "Subtractor.Calculate : " << subtractor->GetResult() << std::endl;

	delete summator;
	delete subtractor;

	return 0;
}