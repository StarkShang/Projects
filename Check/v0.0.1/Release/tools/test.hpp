#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	int in1, in2, out;
	iss >> in1 >> in2;
	oss >> out;
	std::stringstream rss;
	/***********************
	** Part 2 : 测试函数
	***********************/
	int rst = func(in1, in2);
	bool isPassed = abs(rst - out) < 1e-5;
	rss << rst;
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}