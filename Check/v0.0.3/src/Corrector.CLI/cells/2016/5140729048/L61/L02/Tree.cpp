#include "Tree.h"
Tree::Tree(int age)
{
this->age=age;
}//赋值

void Tree::Grow(int years)
{
 age=age+years;
}//生长

int Tree::ShowAge()
{return age;}//显示年纪