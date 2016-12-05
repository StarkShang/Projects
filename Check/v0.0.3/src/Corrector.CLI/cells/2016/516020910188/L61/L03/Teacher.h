#pragma once
#include "Person.h"

class Teacher :public Person//添加子类teacher
{  public:
	int TeacherID;
	char Title[1024];//为子类添加变量
};