#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	std::string num1, num2, out;
	iss >> num1 >> num2;
	oss >> out;
	/***********************
	** Part 2 : 测试函数
	***********************/
	char buffer[1024];
	std::string sum(addTwoNumbers((char*)num1.c_str(), (char*)num2.c_str(), buffer, 1024));
	bool isPassed = sum==out;
	rss << sum;
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}