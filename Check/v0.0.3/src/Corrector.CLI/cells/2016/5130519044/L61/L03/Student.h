#pragma once
using namespace std;
#include "Person.h"


class Student:public Person
{public:
	int StudentID;  //�����������ӵ�ѧ�š��༶��רҵ��Ա
	char* Class;
	char* Major;
};