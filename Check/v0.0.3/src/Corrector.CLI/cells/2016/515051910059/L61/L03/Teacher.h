#pragma once
#include "Person.h"

class Teacher:public Person//增加teacher类
{public:
int Age;//定义年龄
int TeacherID;//定义工号
char Title[1024];//定义职称
};

