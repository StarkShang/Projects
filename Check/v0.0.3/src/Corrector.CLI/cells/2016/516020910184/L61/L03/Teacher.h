#pragma once
#include "Person.h"

class Teacher:public Person//继承person类后新增加工号、职称
{
public:
	int TeacherID;
	char Title[1024];

};