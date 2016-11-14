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
	int count = 0;
	std::queue<float> q;
	while (!ss.eof())
	{
		float tmp;
		ss >> tmp;
		q.push(tmp);
		count++;
	}
	float in[1024];
	for (int i = 0; i < count / 2; i++)
	{
		in[i] = q.front(); q.pop();
		shouldIn += std::to_string(in[i]) + " ";
	}
	float out[1024];
	for (int i = 0; i < count / 2; i++)
	{
		out[i] = q.front(); q.pop();
		shouldOut += std::to_string(out[i]) + " ";
	}

	insertSort(in, count / 2);
	for (int i = 0; i < count / 2; i++)
	{
		if (fabs(in[i]-out[i]) > 1e-5)
		{
			flag = false;
		}
	}
	for (int i = 0; i < count / 2; i++)
	{
		realOut += std::to_string(in[i]) + " ";
	}
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