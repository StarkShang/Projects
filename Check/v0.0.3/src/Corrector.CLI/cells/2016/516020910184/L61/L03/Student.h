#pragma once
#include "Person.h"

class Student:public Person//�̳�person�������ѧ�š��༶��רҵ
{	
public:
	int StudentId;
	char Class[1024];
	char Major[1024];
};