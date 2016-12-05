#include "Tree.h"
Tree::Tree(int age)//构造函数，把输入的AGE赋值到类中的AGE
{
	this->age=age;
	
}

void Tree::Grow(int years)//年龄增长函数，把AGE加上YEARS
{age+=years;
}

int Tree::ShowAge()//年龄显示函数，返回AGE
{return age;
}