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
	int in[3];
	ss >> in[0] >> in[1] >> in[2];
	int out[4];
	ss >> out[0] >> out[1] >> out[2] >> out[3];
	int rst[4] = { 0 };

	struct Stack stack;
	for (int i = 0; i < 3; i++) {
		push(stack, in[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		pop(stack, rst[i]);
		if (fabs(rst[i] - out[i]) > 1e-5) {
			flag = false;
		}
	}
	
	shouldIn = std::to_string(in[0]) + " " + std::to_string(in[1]) + " " + std::to_string(in[2]);
	shouldOut = std::to_string(out[0]) + " " +
				std::to_string(out[1]) + " " +
				std::to_string(out[2]) + " " +
				std::to_string(out[3]);
	realOut = std::to_string(rst[0]) + " " +
			  std::to_string(rst[1]) + " " +
			  std::to_string(rst[2]) + " " +
			  std::to_string(rst[3]);

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