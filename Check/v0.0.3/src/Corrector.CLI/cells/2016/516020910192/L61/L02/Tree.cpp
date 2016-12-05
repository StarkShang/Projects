#include "Tree.h"
#include <iostream>
Tree::Tree(int age)
{
	this->age=age;//初始化
}
void Tree::Grow(int years)//树龄增加函数
{
	age=age+years;
}
int Tree::ShowAge()//输出树龄
{
	return(age);
}