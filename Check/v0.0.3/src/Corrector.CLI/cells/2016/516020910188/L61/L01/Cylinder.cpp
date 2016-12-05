#include"Cylinder.h"
Cylinder::Cylinder(double len, double r)
{ this->len =len;
  this->r=r;
}//初始化变量
double Cylinder::Area()
	{
		double a;
		a=3.14*r*r*2+2*3.14*r*len;
		return a;
	}//计算表面积
double Cylinder::Volume()
	{
		double v;
		v=3.14*len*r*r*r;
		return v;
	}//计算体积