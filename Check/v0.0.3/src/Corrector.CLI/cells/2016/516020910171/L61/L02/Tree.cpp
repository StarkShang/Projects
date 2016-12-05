/*****************************
 * 声明一个Tree（树）类，有成员变量ages(树龄),
 成员函数grow(int years)用以对成员变量ages加上years，
 showage( )用以显示tree对象的ages值。
 在主函数中定义Tree类对象，调用成员函数并输出（初始化树龄15，grow(5))
 *****************************/

#include "Tree.h"

Tree::Tree(int age)//初始化变量
{ this->age=age;}

void Tree::Grow(int years)//计算树龄的函数
{
	age=age+years;//计算树龄
}

int Tree::ShowAge()//返回树龄的函数
{
	return age;//返回树龄
}