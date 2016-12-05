#include"Cylinder.h"
double Cylinder::Area()
{
	double s;//定义变量s
	s=r*r*3.14+2*len*3.14*r;//计算表面积
	return s;//返回函数值
}
double Cylinder::Volume()
{
	double v;//定义变量v
	v=r*r*3.14*len;//计算体积
	return v;//返回函数值
}
Cylinder::Cylinder(double len,double r)
{
	this->len=len;
	this->r=r;
}