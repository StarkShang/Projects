#pragma once
#include "Person.h"

class Student:public Person//person�����������
{	
public:
	int StudentId;//ѧ��
	int Class[1024];//���
	char *Major[1024];//רҵ
};