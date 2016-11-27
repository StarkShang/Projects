#include <math.h>
#include <string>
#include <sstream>
#include "func.hpp"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	int insData, insLoc, delLoc;
	iss >> insData >> insLoc >> delLoc;

	int dataOfNodes[1024], numOfNodes = 0;
	int dataOfLNs[1024], numOfLNs = 0;
	while (!iss.eof()) iss >> dataOfNodes[numOfNodes++];
	while (!oss.eof()) oss >> dataOfLNs[numOfLNs++];
	/***********************
	** Part 2 : 测试函数
	***********************/
	auto head = create(dataOfNodes, numOfNodes);
	LinkedNode insNode;
	insNode.data = insData;
	insert(&insNode, &head, insLoc);
	remove(&head, delLoc);
	LinkedNode* iterator = head;

	bool isPassed = true;
	int num = 0;
	while (iterator != nullptr) {
		if (num > numOfLNs) {
			isPassed = false;
			break;
		}
		if (iterator->data != dataOfLNs[num++]) isPassed = false;
		iterator = iterator->next;
	}
	if (num != numOfLNs) isPassed = false;
	iterator = head;
	while (iterator != nullptr) {
		rss << iterator->data << " ";
		iterator = iterator->next;
	}
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}