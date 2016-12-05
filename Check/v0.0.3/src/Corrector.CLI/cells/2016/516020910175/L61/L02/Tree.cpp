#include "Tree.h"
Tree::Tree(int age=15)//构造函数，把参数赋给树龄
{
	this->age=age;
}
void Tree::Grow(int years=5)//成长函数，令树龄增加参数
{
	age+=years;
}
int Tree::ShowAge()//显示树龄函数，返回树龄大小
{
	return age;
}