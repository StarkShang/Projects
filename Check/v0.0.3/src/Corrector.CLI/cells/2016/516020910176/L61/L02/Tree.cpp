#include <iostream>
#include "Tree.h"
Tree::Tree(int age)                                  //定义Tree函数
{
	this->age = age;                                //为age赋值
} 
void Tree::Grow(int years)                           //定义Grow函数
{
	this->years = years;                            //为years赋值
}
int Tree::ShowAge()
{
	return (Tree::age + Tree::years);              //计算当前年龄
}