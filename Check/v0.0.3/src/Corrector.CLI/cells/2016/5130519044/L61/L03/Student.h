#pragma once
using namespace std;
#include "Person.h"


class Student:public Person
{public:
	int StudentID;  //派生类新增加的学号、班级、专业成员
	char* Class;
	char* Major;
};