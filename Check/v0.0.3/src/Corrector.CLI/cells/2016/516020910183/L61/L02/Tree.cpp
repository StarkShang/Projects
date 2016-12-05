#include "Tree.h"
Tree::Tree(int age)//
{//
	this->age = age;//定义变量
}//
void Tree::Grow(int years)//定义函数
{//
	age = age + years;//计算年龄
}//
int Tree::ShowAge()//定义函数
{//
	return(age);//返回年龄
}//