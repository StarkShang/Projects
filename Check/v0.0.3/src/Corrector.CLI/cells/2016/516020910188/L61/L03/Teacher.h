#pragma once
#include "Person.h"

class Teacher :public Person//�������teacher
{  public:
	int TeacherID;
	char Title[1024];//Ϊ������ӱ���
};