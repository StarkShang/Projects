#include"Tree.h"
Tree::Tree(int age)//ʵ�ֽ�����age��ֵ����Tree�е�age
{
	this->age=age;
}
void Tree::Grow(int years)//ʵ�ֺ���Grow����Ա����ages����years

{
	age=age+years;
}
int Tree::ShowAge()//��ʾtree�����agesֵ
{
	return age;
}