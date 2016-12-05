#pragma once
#include "Person.h"

class Student:public Person//person基类的派生类
{	
public:
	int StudentId;//学号
	int Class[1024];//班号
	char *Major[1024];//专业
};