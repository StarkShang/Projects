#include <iostream>
#include "Tree.h"

int main(int argc, char const *argv[])
{
	int age, years;
	std::cout << "Please input the age of the tree : ";
	std::cin >> age;
	std::cout << "Please input the year of growth : ";
	std::cin >> years;

	Tree tree(age);
	tree.Grow(years);
	std::cout << "Now the tree is " << tree.ShowAge() << " year(s) old." << std::endl;
	return 0;
}