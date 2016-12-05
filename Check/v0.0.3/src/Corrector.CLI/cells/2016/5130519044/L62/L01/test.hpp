#include <math.h>
#include <string>
#include <sstream>
#include "Summator.h"
#include "Subtractor.h"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	float num1, num2, sumRst, subRst;
	iss >> num1 >> num2;
	oss >> sumRst >> subRst;
	/***********************
	** Part 2 : 测试函数
	***********************/
	Summator summator;
	Subtractor subtractor;
	summator.Add(num1, num2);
	subtractor.Sub(num1, num2);
	auto oSumRst = summator.GetResult();
	auto oSubRst = subtractor.GetResult();
	
	bool isPassed = true;
	if (abs(oSumRst - sumRst) > 1e-3) isPassed = false;
	if (abs(oSubRst - subRst) > 1e-3) isPassed = false;

	rss << oSumRst << " " << oSubRst;
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}