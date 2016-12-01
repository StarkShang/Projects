#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : ������������
	 ***********************/
	std::string expr;
	int rst;
	iss >> expr;
	oss >> rst;
	/***********************
	** Part 2 : ���Ժ���
	***********************/
	auto result = solve((char*)expr.c_str(), expr.size());
	bool isPassed = result==rst;
	rss << result;
	/***********************
	** Part 3 : ������������
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}