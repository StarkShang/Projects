#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	int locOfLoop, dataOfNodes[1024], numOfNodes = 0;
	iss >> locOfLoop;
	while (!iss.eof()) iss >> dataOfNodes[numOfNodes++];

	bool iHasLoop;
	int iLenOfLoop, iLocOfLoop;
	oss >> iHasLoop >> iLenOfLoop >> iLocOfLoop;
	/***********************
	** Part 2 : 测试函数
	***********************/
	auto head = create(dataOfNodes, numOfNodes, locOfLoop);
	auto oHasLoop = hasLoop(head);
	int oLenOfLoop, oLocOfLoop;
	if (oHasLoop) {
		oLenOfLoop = lenOfLoop(head);
		oLocOfLoop = locationOfLoop(head);
	} else {
		oLenOfLoop = 0;
		oLocOfLoop = -1;
	}
	bool isPassed = true;
	
	if (oHasLoop != iHasLoop) isPassed = false;
	if (oLenOfLoop != iLenOfLoop) isPassed = false;
	if (oLocOfLoop != iLocOfLoop) isPassed = false;
	
	rss << oHasLoop << " "
		<< oLenOfLoop << " "
		<< oLocOfLoop;
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}