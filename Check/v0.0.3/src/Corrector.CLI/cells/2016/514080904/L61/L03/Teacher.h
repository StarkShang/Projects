#pragma once
#include "Person.h"

class Teacher: public Person//teacher 是person的一个子类
{
public:
	int TeacherID;
	char Title[1024];
};