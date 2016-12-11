#include <math.h>
#include <string>
#include <sstream>
#include "Tree.h"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	int age, years, nowAge;
	iss >> age >> years;
	oss >> nowAge;
	/***********************
	** Part 2 : 测试函数
	***********************/
	Tree tree(age);
	tree.Grow(years);

	bool isPassed = nowAge == tree.ShowAge();
	rss << tree.ShowAge();
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}