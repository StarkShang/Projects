#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)//构造函数，把参数长度，半径赋给对象
{
	this->len=len;
	this->r=r;
}
double Cylinder::Area()//求面积函数，求对象的表面积
{
	return 2*3.14*r*len+2*3.14*r*r;
}
double Cylinder::Volume()//求体积函数，求对象的体积
{
	return 3.14*r*r*len;
}