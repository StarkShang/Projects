#pragma once
#include "Person.h"

class Student:public Person //����������Student
{	
public:
	int StudentId;//���ӳ�Ա����ѧ��
	char Class[1024];//���ӳ�Ա�����༶
	char Major[1024];//���ӳ�Ա����רҵ
};