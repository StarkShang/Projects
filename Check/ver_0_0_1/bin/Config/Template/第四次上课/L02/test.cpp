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
	float x, y;
	ss >> x >> y;
	struct Point p = func();
	if (fabs(p.x-x)+fabs(p.y-y) > 1e5) {
		flag = false;
	}

	shouldOut = std::to_string(x) + " " + std::to_string(y);
	realOut = std::to_string(p.x) + " " + std::to_string(p.y);

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