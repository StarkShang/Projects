#include "Tree.h"

Tree::Tree(int age)//初始化
{
	this->age=age;
}
void Tree::Grow(int years)//改变age
{
	age = age + years;
}
int Tree::ShowAge()//返回现在的年龄
{
	return age;
}
