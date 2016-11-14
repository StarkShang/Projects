#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <functional>

#include "tmp.hpp"

void show(std::string shouldIn,
	std::string shouldOut,
	std::string realOut);

bool test(std::stringstream &ss) {
	bool flag = true;
	std::string shouldIn;
	std::string shouldOut;
	std::string realOut;
	/*****************/
	ss >> shouldIn;
	ss >> shouldOut;
	char str[1024];
	shouldIn.copy(str, shouldIn.size(), 0);
	str[shouldIn.size()] = 0;
	substitute(str, shouldIn.size());
	realOut = str;

	for (int i = 0; i < shouldOut.size(); i++)
	{
		if (shouldOut[i] != realOut[i])
		{
			flag = false;
			std::cout << "false" << std::endl;
		}
	}
	/**************************************/
	if (!flag)
	{
		show(shouldIn, shouldOut, realOut);
	}
	return flag;
}

void show(std::string shouldIn,
		  std::string shouldOut,
		  std::string realOut) {
	std::cout << "[out] Input : " << shouldIn << std::endl;
	std::cout << "[out] Output: " << shouldOut << std::endl;
	std::cout << "[out] Got   : " << realOut << std::endl;
}