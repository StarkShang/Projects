#pragma once
#include "Person.h"

class Student: public Person//student ͬ����person��һ������
{
public:
	int StudentId;
	int Class;
	char Major[1024];
};