#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	int x, out[1024], n;
	iss >> x;
	oss >> n;
	for (int i = 0; i < n; ++i) oss >> out[i];
	/***********************
	** Part 2 : 测试函数
	***********************/
	int pp[1024], num;
	func(x, pp, num);
	bool isPassed = true;
	if (num != n) {
		isPassed = false;
	} else {
		for (int i = 0; i < num; ++i) {
			if (abs(pp[i] - out[i]) > 1e-5) {
				isPassed = false;
				break;
			}
		}
	}
	
	rss << num;
	for (int i = 0; i < num; ++i) {
		rss << pp[i];
	}
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}