#include "Tree.h"

Tree::Tree(int age)//����������Ĺ��캯��
{
	this->age=age; //�Գ�ʼ������и�ֵ
}

void Tree::Grow(int years)//����������������ĺ���
{
	this->age+=years;//�������ڵ�����
}

int Tree::ShowAge()//������ʾ��������ĺ���
{
	return(age);
}
