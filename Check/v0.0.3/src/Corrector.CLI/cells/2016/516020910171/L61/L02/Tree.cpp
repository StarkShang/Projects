/*****************************
 * ����һ��Tree�������࣬�г�Ա����ages(����),
 ��Ա����grow(int years)���ԶԳ�Ա����ages����years��
 showage( )������ʾtree�����agesֵ��
 ���������ж���Tree����󣬵��ó�Ա�������������ʼ������15��grow(5))
 *****************************/

#include "Tree.h"

Tree::Tree(int age)//��ʼ������
{ this->age=age;}

void Tree::Grow(int years)//��������ĺ���
{
	age=age+years;//��������
}

int Tree::ShowAge()//��������ĺ���
{
	return age;//��������
}