#include <iostream>
#include "Singleton.h"

int main(int argc, char* argv[])
{
	Singleton* instance1 = Singleton::GetInstance();
	Singleton* instance2 = Singleton::GetInstance();

	std::cout << "The address of instace1 is : " << instance1 << std::endl;
	std::cout << "The address of instace2 is : " << instance2 << std::endl;

	return 0;
}