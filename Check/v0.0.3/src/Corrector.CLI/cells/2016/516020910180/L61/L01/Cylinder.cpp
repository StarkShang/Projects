#include"Cylinder.h"
Cylinder::Cylinder(double len,double r)
{
	this->len=len;//赋初值
	this->r=r;
}
const double Cylinder::Pi=3.14159;
double Cylinder::Area()
{
	
	double a=2*Pi*len*r+2*Pi*r*r;//算面积
	return a;
}
double Cylinder::Volume()
{
	double v=Pi*r*r*len;//算体积
	return v;
}