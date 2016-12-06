#include <math.h>
#include <string>
#include <sstream>
#include "String.h"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : ������������
	 ***********************/
	std::string iStr, oStr;
	iss >> iStr;
	oss >> oStr;
	/***********************
	** Part 2 : ���Ժ���
	***********************/
	String str1((char*)iStr.c_str());
	String str2(str1);
	std::string str3(str2.GetCString());
	bool isPassed = str3 == oStr;

	rss << str3;
	/***********************
	** Part 3 : ������������
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}