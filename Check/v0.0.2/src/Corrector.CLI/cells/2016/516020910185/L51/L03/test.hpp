#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : ������������
	 ***********************/
	int numOfArray = 0, array[1024], numOfEven;
	while (!iss.eof()) {
		iss >> array[numOfArray++];
	}
	oss >> numOfEven;
	/***********************
	** Part 2 : ���Ժ���
	***********************/
	int num;
	func(array, numOfArray, &num);
	bool isPassed = abs(num - numOfEven) < 1e-5;
	rss << num;
	/***********************
	** Part 3 : ������������
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}