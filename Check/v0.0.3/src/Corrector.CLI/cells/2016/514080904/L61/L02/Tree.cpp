#include "Tree.h"

Tree::Tree(int age)//��ʼ��
{
	this->age=age;
}
void Tree::Grow(int years)//�ı�age
{
	age = age + years;
}
int Tree::ShowAge()//�������ڵ�����
{
	return age;
}
