//����һ��Tree�������࣬�г�Ա����ages(����),
//��Ա����grow(int years)���ԶԳ�Ա����ages����years��
//showage( )������ʾtree�����agesֵ�����������ж���Tree�����
//���ó�Ա�������������ʼ������15��grow(5))
#include "Tree.h"
#include <iostream>
Tree::Tree(int age)
{
	this->age=age;
}
void Tree::Grow(int years)
{
	age=age+years;
}
int Tree::ShowAge()
{
	return(age);
}