#pragma once
#include "Person.h"

class Teacher:public Person//派生类，增加工号、职称
{public:
	int TeacherID;
	char Title[1024];
};