#pragma once
#include "Person.h"

class Student :public Person///��������student
{	public:
    int StudentId;
	char Class[1024];
	char Major[1024];//Ϊ������ӱ���
};