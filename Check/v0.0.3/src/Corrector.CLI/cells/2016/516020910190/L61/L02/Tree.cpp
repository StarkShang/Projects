#include "Tree.h"//����ͷ�ļ�Tree.h
Tree::Tree(int age)
{
	this->age=age;//��ʼ������
}
void Tree::Grow(int years)
{
	age=age+years;//�ʼ������+����������=���ڵ�����
}
int Tree::ShowAge()
{
	return(age);//��ʾ���ڵ�����
}
