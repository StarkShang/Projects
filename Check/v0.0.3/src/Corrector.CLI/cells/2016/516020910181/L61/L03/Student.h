#pragma once
#include "Person.h"

class Student: public Person
{	
public:
	int StudentId;                   //学号
	char Class[1024];                //班级
	char Major[1024];                //专业
};