#include "Tree.h"
Tree::Tree(int age)//���캯�����������AGE��ֵ�����е�AGE
{
	this->age=age;
	
}

void Tree::Grow(int years)//����������������AGE����YEARS
{age+=years;
}

int Tree::ShowAge()//������ʾ����������AGE
{return age;
}