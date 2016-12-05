#pragma once
#include "Person.h"

class Teacher:public Person//声明派生类Teacher
{
  public:
	int TeacherID;//增加成员变量工号
	char Title[1024];//增加成员变量职称
};