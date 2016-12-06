#include <math.h>
#include <string>
#include <sstream>
#include "Singleton.h"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : ������������
	 ***********************/
	
	/***********************
	** Part 2 : ���Ժ���
	***********************/
	Singleton* instance1 = Singleton::GetInstance();
	Singleton* instance2 = Singleton::GetInstance();

	bool isPassed = instance1 == instance2;
	/***********************
	** Part 3 : ������������
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}