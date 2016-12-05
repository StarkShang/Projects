#include <math.h>
#include <string>
#include <sstream>
#include "Teacher.h"
#include "Student.h"

bool test(std::stringstream& iss, std::stringstream& oss, void(*errorDisplay)(std::string,std::string,std::string)) {
	std::stringstream rss;
	/***********************
	 ** Part 1 : 解析输入数据
	 ***********************/
	Teacher teacher;
	Student student;

	iss >> teacher.Name;
	iss >> teacher.Gender;
	iss >> teacher.Age;
	iss >> teacher.TeacherID;
	iss >> teacher.Title;

	iss >> student.Name;
	iss >> student.Gender;
	iss >> student.Age;
	iss >> student.StudentId;
	iss >> student.Class;
	iss >> student.Major;

	/***********************
	** Part 2 : 测试函数
	***********************/
	bool isPassed = true;
	rss << "0";
	/***********************
	** Part 3 : 解析输入数据
	***********************/
	if (!isPassed) errorDisplay(iss.str(), oss.str(), rss.str());

	return isPassed;
}