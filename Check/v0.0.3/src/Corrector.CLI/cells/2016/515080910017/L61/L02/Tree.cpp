#include "Tree.h"
Tree::Tree(int age)
{
	this->age=age; //定义Tree函数来初始化age
}

void Tree::Grow(int years)
{
	age=age+years; //定义Grow函数对树的年龄进行增加
}

int Tree::ShowAge()
{
	
	return(age);//定义ShowAge显示树的年龄
}