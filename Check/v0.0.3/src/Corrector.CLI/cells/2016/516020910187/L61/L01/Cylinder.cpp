#include "Cylinder.h"
double Cylinder::Area()
{
	double pie = 3.14159;
	return len * 2 * pie*r + 2 * pie*r*r;
}
double Cylinder::Volume()
{
	double pie = 3.14159;
	return len*pie*r*r;
}
Cylinder::Cylinder(double len, double r)
{
	this->len=len;
	this->r=r;
}