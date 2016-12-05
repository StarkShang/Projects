#pragma once
#include "Person.h"

class Student:public Person//派生类，增加学号，班级，专业
{public:
	int StudentId;
	int Class;
	char Major[1024];
};