#include "Tree.h"
Tree::Tree(int age)
{
	this->age =age;
}
void Tree::Grow(int years)
{
	age=age+years;
}
int Tree::ShowAge()
{
	return age;
}
