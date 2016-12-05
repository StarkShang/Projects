#include <math.h>
#include <string>
#include <sstream>
#include "Cylinder.h"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	double len, radii, area, volu;
	iss >> len >> radii;
	oss >> area >> volu;
	/***********************
	** Part 2 : 测试函数
	***********************/
	Cylinder c(len, radii);
	double oArea = c.Area();
	double oVolu = c.Volume();

	bool isPassed = true;
	if (abs(area - oArea) > 1e-3) isPassed = false;
	if (abs(volu - oVolu) > 1e-3) isPassed = false;

	rss << oArea << " " << oVolu;
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}