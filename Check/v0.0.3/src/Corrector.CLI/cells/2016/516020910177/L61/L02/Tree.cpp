#include "Tree.h"

Tree::Tree(int age)  //定义成员函数
{
	this->age=age;   //初始化成员变量 树龄are
}
void Tree::Grow(int years)    //定义成员函数
{
	age=age+years;     //计算成长后的树龄
}
int  Tree::ShowAge()      //定义成员函数
{
	return age;    //返回现在相应树龄
}