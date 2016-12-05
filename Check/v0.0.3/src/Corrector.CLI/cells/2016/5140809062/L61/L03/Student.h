#pragma once
#include "Person.h"

class Student :public Person//派生学生类。追加学号，班级，专业等信息
{	
public:
	int StudentId;
	char Class[1024];
	char Major[1024];

};