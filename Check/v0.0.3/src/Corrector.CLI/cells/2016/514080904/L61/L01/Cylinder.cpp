#include "Cylinder.h"

const int PI=3.14;//由于main函数中以及.h文件中均定义为double型，因此此处pi取3.14和取3没有什么区别
Cylinder::Cylinder(double len, double r)//赋值
{
	this->len=len;
	this->r=r;
}
double Cylinder::Area()//计算表面积
{
	return PI*r*r*2+2*PI*r*len;
}
double Cylinder::Volume()//计算体积
{
	return PI*r*r*len;
}