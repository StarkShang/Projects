#pragma once
#include "Person.h"

class Student:public Person//继承person类后增加学号、班级、专业
{	
public:
	int StudentId;
	char Class[1024];
	char Major[1024];
};