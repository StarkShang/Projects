#include "Cylinder.h"
Cylinder::Cylinder(double len,double r)//定义构造函数，令圆柱体的长与半径为赋值
 {
	 this->len=len;
	 this->r=r;
 }
double Cylinder ::Area()//定义求面积的函数，返回圆的面积
{ return 3.1415926*r*r;
}

double Cylinder ::Volume()//定义求体积的函数，返回圆的体积
{return (3.1415926*r*r*len);
}