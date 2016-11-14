#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stack>

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
	std::stack<float> q;
	int count = 0;
	while (!ss.eof())
	{
		float tmp;
		ss >> tmp;
		q.push(tmp);
		count++;
	}
	int out = (int)q.top(); q.pop();
	int len = (int)q.top(); q.pop();
	float* nums = new float[len];
	for (int i = 0; i < len; i++)
	{
		nums[len - 1 - i] = q.top(); q.pop();
	}
	auto target = q.top(); q.pop();
	auto rst = func(target, nums, len);
	if (fabs(rst - out) > 1e-5)
	{
		flag = false;
	}

	shouldIn += "{\"target\":" +
				std::to_string(target) +
				"},{\"nums\":[" + 
				std::to_string(nums[0]);
	for (int i = 1; i < len; i++)
	{
		shouldIn += "," + std::to_string(nums[i]);
	}
	shouldIn += "]},{\"len\":" + std::to_string(len) + "}";
	shouldOut = std::to_string(out);
	realOut = std::to_string(rst);

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