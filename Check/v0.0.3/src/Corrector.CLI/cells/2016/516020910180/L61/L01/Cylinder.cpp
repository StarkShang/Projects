#include"Cylinder.h"
Cylinder::Cylinder(double len,double r)
{
	this->len=len;//����ֵ
	this->r=r;
}
const double Cylinder::Pi=3.14159;
double Cylinder::Area()
{
	
	double a=2*Pi*len*r+2*Pi*r*r;//�����
	return a;
}
double Cylinder::Volume()
{
	double v=Pi*r*r*len;//�����
	return v;
}