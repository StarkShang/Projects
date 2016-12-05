#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)
{
	this->len=len;
	this->r=r;//初始化半径和长度
}
double pi=3.1415927;
double Cylinder::Area()
{   
	double s;
	s=2*pi*r*r+2*pi*r*len;//求圆柱表面积
	return s;
}
double Cylinder::Volume()
{
	double V;
	V=pi*r*r*len;//求圆柱体积
	return V;
}
