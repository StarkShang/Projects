#pragma once
#include "Person.h"

class Student:public Person//添加student类
{public:
int StudentId;//定义学号
char Class[1024];//定义班级
char Major[1024];//定义专业
};