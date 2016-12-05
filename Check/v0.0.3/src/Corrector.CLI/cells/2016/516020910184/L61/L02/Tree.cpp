#include"Tree.h"
Tree::Tree(int age)//实现将参数age赋值给类Tree中的age
{
	this->age=age;
}
void Tree::Grow(int years)//实现函数Grow将成员变量ages加上years

{
	age=age+years;
}
int Tree::ShowAge()//显示tree对象的ages值
{
	return age;
}