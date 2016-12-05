#include"Tree.h"

Tree::Tree(int age)
	{  this->age=age;}//初始化树龄

	void Tree::Grow(int years)
	{  this->age=age+years;}//计算加和后树龄

	int Tree::ShowAge()
	{
	int a=age;
	return a;
	}//显示计算结果