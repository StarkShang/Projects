#include"Tree.h"
Tree::Tree(int age)
{
	this->age=age;
}
void Tree::Grow(int years)
{
	this->age=this->age+years;
}
int Tree::ShowAge()
{
	int s;
	s=age;
	return s;
}