#include "Tree.h"

Tree::Tree(int age)  //定义Tree函数来初始化age
{
	this->age=age;
}
void Tree::Grow(int years)   //定义Grow函数对树的年龄进行增加
{
	age+=years;
}
int Tree::ShowAge()  //定义ShowAge显示树的年龄
{
	return(age);
}