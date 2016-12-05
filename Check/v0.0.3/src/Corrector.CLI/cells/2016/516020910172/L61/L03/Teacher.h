#pragma once
#include "Person.h"

class Teacher:public Person//person基类的派生类
{
public:
	int TeacherID;//工号
	char Title;//职称
};