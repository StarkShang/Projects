#include "Tree.h"
Tree::Tree(int age)
{
	this->age=age; //����Tree��������ʼ��age
}

void Tree::Grow(int years)
{
	age=age+years; //����Grow���������������������
}

int Tree::ShowAge()
{
	
	return(age);//����ShowAge��ʾ��������
}