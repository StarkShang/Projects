#pragma once
#include "Person.h"

class Teacher:public Person//派生老师类，追加老师编号，头衔信息
{
public:
	int TeacherID;
	char Title[1024];
};