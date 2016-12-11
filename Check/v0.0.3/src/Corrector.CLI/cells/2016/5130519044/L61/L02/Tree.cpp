#include "Tree.h"

//在类外定义函数Grow和Showage
void Tree::Grow(int years)
{age=age+years;}

int Tree::ShowAge()
{return age;}