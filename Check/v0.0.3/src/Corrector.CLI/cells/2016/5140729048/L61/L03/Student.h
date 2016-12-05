#pragma once
#include "Person.h"

class Student:public Person//声明派生类
{	
public://派生类共用部分
	Student(char Name[1024],bool Gender,int Age, int id,int Class,char Major[1024]):Person(Name,Gender,Age)//派生类构造函数
	{
	StudentId=id;
	Class=Class;
	Major=Major;
	}
	~Student(){};//派生类析构函数

	int StudentId;
	int Class;
	char Major[1024];
};