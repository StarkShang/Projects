#include <iostream>
#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)
{
	this->len=len;
	this->r=r;
}
double Cylinder::Area()
{
	double s;
	s=2*3.14*r*r+2*3.14*r*len;
	return s;
}
double Cylinder::Volume()
{
	double v;
	v=3.14*r*r*len;
	return v;
}