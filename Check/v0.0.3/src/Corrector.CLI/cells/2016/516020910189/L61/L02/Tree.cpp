#include "Tree.h"
Tree::Tree(int age) //��ʼ����Ա����ages
{
	this->age = age;
}
void Tree::Grow(int years) //�Գ�Ա����ages����years
{
	age = age + years;
}
int Tree::ShowAge() //�������
{
	return age;
}