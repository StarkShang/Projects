#pragma once
#include "Person.h"
class Student:public Person
{	
public:
	int StudentId;//定义学生ID
	int Class;//定义学生班级
	char Major[1024];//定义学生专业

};