#include"Tree.h"
Tree::Tree(int age)
{
	this->age=age;//��ʼ������
}
void Tree::Grow(int years)
{
	age+=years;//������
}
int Tree::ShowAge()
{
	int age=this->age;//�������
	return age;
}