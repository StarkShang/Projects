#include"Cylinder.h"
Cylinder::Cylinder(double len,double r)
{
	this->len=len;
	this->r=r;
}
double Cylinder::Area()
{
	double area;
	area=2*3.14*r*r+2*3.14*r*len;
	return area;
}
double Cylinder::Volume()
{
	double volume;
	volume=3.14*r*r*len;
	return volume;
}
