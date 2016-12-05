#pragma once
#include "Person.h"

class Student :public Person///建立子类student
{	public:
    int StudentId;
	char Class[1024];
	char Major[1024];//为子类添加变量
};