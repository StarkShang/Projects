#include"Tree.h"
void Tree::Grow(int years)
{
	age += years;
}
int Tree::ShowAge()
{
	return age;
}
Tree::Tree(int age)
{
	this->age = age;
}