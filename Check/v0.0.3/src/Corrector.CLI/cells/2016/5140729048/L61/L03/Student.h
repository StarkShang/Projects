#pragma once
#include "Person.h"

class Student:public Person//����������
{	
public://�����๲�ò���
	Student(char Name[1024],bool Gender,int Age, int id,int Class,char Major[1024]):Person(Name,Gender,Age)//�����๹�캯��
	{
	StudentId=id;
	Class=Class;
	Major=Major;
	}
	~Student(){};//��������������

	int StudentId;
	int Class;
	char Major[1024];
};