#pragma once
#include "Person.h"

class Teacher:public Person//����������
{
public://�����๲�ò���
Teacher(char Name[1024],bool Gender,int Age, int id,char Title[1024]):Person(Name,Gender,Age)//�����๹�캯��
{
	TeacherID=id;
	Title=Title;
}
~Teacher(){};//��������������

	int TeacherID;
	char Title[1024];
};