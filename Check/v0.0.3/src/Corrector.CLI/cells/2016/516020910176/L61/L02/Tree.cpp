#include <iostream>
#include "Tree.h"
Tree::Tree(int age)                                  //����Tree����
{
	this->age = age;                                //Ϊage��ֵ
} 
void Tree::Grow(int years)                           //����Grow����
{
	this->years = years;                            //Ϊyears��ֵ
}
int Tree::ShowAge()
{
	return (Tree::age + Tree::years);              //���㵱ǰ����
}