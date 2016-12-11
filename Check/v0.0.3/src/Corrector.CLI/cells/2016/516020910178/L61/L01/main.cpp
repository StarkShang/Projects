#include <iostream>
#include "Cylinder.h"

int main(int argc, char const *argv[])
{
	double len, r;
	std::cout << "Please input the length and the radius : ";
	std::cin >> len >> r;
	Cylinder cylinder(len, r);
	std::cout << "The surface area of the cylinder is " << cylinder.Area() << std::endl;
	std::cout << "The volume of the cylinder is " << cylinder.Volume() << std::endl;
	return 0;
}