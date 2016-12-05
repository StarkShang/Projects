#pragma once
#include "Person.h"

class Student: public Person//student 同样是person的一个子类
{
public:
	int StudentId;
	int Class;
	char Major[1024];
};