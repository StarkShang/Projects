#include "Tree.h"

Tree::Tree(int age)//定义带参数的构造函数
{
	this->age=age; //对初始树龄进行赋值
}

void Tree::Grow(int years)//声明计算现在树龄的函数
{
	this->age+=years;//计算现在的树龄
}

int Tree::ShowAge()//定义显示现在树龄的函数
{
	return(age);
}
