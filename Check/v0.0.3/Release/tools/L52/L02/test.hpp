#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	std::string expr;
	int rst;
	iss >> expr;
	oss >> rst;
	/***********************
	** Part 2 : 测试函数
	***********************/
	auto result = solve((char*)expr.c_str(), expr.size());
	bool isPassed = result==rst;
	rss << result;
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}