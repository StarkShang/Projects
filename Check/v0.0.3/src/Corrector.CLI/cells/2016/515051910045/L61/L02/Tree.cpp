#include "Tree.h"

Tree::Tree(int age)  //����Tree��������ʼ��age
{
	this->age=age;
}
void Tree::Grow(int years)   //����Grow���������������������
{
	age+=years;
}
int Tree::ShowAge()  //����ShowAge��ʾ��������
{
	return(age);
}