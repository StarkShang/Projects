#pragma once
#include "Person.h"

class Teacher:public Person//声明派生类
{
public://派生类共用部分
Teacher(char Name[1024],bool Gender,int Age, int id,char Title[1024]):Person(Name,Gender,Age)//派生类构造函数
{
	TeacherID=id;
	Title=Title;
}
~Teacher(){};//派生类析构函数

	int TeacherID;
	char Title[1024];
};