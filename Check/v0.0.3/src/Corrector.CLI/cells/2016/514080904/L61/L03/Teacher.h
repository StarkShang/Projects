#pragma once
#include "Person.h"

class Teacher: public Person//teacher ��person��һ������
{
public:
	int TeacherID;
	char Title[1024];
};