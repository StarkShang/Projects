#include"Tree.h"
Tree::Tree(int age)
{
	this->age=age;//初始化年龄
}
void Tree::Grow(int years)
{
	age+=years;//加年龄
}
int Tree::ShowAge()
{
	int age=this->age;//输出年龄
	return age;
}