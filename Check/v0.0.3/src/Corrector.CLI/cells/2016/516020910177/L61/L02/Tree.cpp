#include "Tree.h"

Tree::Tree(int age)  //�����Ա����
{
	this->age=age;   //��ʼ����Ա���� ����are
}
void Tree::Grow(int years)    //�����Ա����
{
	age=age+years;     //����ɳ��������
}
int  Tree::ShowAge()      //�����Ա����
{
	return age;    //����������Ӧ����
}