#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

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
	int year, month, day, index;
	ss >> year >> month >> day;
	ss >> index;
	int num = func(year, month, day);
	if (num != index) {
		flag = false;
	}
	shouldIn += std::to_string(year) + "/" + std::to_string(month) + "/" + std::to_string(day);
	shouldOut += std::to_string(index);
	realOut += std::to_string(num);
	/**********************/
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