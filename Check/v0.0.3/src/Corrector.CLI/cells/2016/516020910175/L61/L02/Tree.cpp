#include "Tree.h"
Tree::Tree(int age=15)//���캯�����Ѳ�����������
{
	this->age=age;
}
void Tree::Grow(int years=5)//�ɳ����������������Ӳ���
{
	age+=years;
}
int Tree::ShowAge()//��ʾ���亯�������������С
{
	return age;
}