#include "Tree.h"
#include <iostream>
Tree::Tree(int age)
{
	this->age=age;//��ʼ��
}
void Tree::Grow(int years)//�������Ӻ���
{
	age=age+years;
}
int Tree::ShowAge()//�������
{
	return(age);
}