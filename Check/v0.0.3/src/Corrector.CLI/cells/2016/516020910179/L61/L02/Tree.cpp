//声明一个Tree（树）类，有成员变量ages(树龄),
//成员函数grow(int years)用以对成员变量ages加上years，
//showage( )用以显示tree对象的ages值。在主函数中定义Tree类对象，
//调用成员函数并输出（初始化树龄15，grow(5))
#include "Tree.h"
#include <iostream>
Tree::Tree(int age)
{
	this->age=age;
}
void Tree::Grow(int years)
{
	age=age+years;
}
int Tree::ShowAge()
{
	return(age);
}