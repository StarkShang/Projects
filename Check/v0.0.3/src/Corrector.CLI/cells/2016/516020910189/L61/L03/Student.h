#pragma once
#include "Person.h"

class Student:public Person //声明派生类Student
{	
public:
	int StudentId;//增加成员变量学号
	char Class[1024];//增加成员变量班级
	char Major[1024];//增加成员变量专业
};