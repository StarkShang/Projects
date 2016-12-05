#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)//定义Cylinder函数来初始化len与r
{
	this->len=len;
	this->r=r;
}
double Cylinder::Area()   //定义Area函数来计算圆柱的表面积
{   
	double s;
	s=3.1415925*r*2*(r+len);
	return(s);
}
double Cylinder::Volume () //定义Volume函数来计算圆柱的体积
{
	double V;
	V=3.1415926*r*r*len;
	return V;
}