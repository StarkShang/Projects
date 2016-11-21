#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	const int numOfCourse = 3;
	int numOfStu;
	iss >> numOfStu;
	STUDENT *stu = new STUDENT[numOfStu];
	for (int i = 0; i < numOfCourse; ++i) {
		for (int j = 0; j < numOfStu; ++j) {
			iss >> stu[j].course[i];
		}
	}
	double avr[numOfCourse],high[numOfCourse];
	for (int i = 0; i < numOfCourse; ++i) {
		oss >> avr[i] >> high[i];
	}
	/***********************
	** Part 2 : 测试函数
	***********************/
	double average[numOfCourse], highest[numOfCourse];
	func(stu, numOfStu, average, highest);
	bool isPassed = true;
	for (int i = 0; i < numOfCourse; ++i)
	{
		if (abs(average[i] - avr[i]) > 1e-5) {
			isPassed = false;
			break;
		}
		if (abs(highest[i] - high[i]) > 1e-5) {
			isPassed = false;
			break;
		}
	}
	for (int i = 0; i < numOfCourse; ++i) {
		rss << average[i] << highest[i];
	}
	delete[]stu;
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}