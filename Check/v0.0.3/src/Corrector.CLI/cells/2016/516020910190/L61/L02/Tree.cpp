#include "Tree.h"//包含头文件Tree.h
Tree::Tree(int age)
{
	this->age=age;//初始化年龄
}
void Tree::Grow(int years)
{
	age=age+years;//最开始的年龄+生长的年数=现在的年龄
}
int Tree::ShowAge()
{
	return(age);//显示现在的年龄
}
