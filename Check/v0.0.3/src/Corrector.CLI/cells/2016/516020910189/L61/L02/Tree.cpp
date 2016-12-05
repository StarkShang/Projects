#include "Tree.h"
Tree::Tree(int age) //初始化成员变量ages
{
	this->age = age;
}
void Tree::Grow(int years) //对成员变量ages加上years
{
	age = age + years;
}
int Tree::ShowAge() //输出树龄
{
	return age;
}