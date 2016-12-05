#include "Cylinder.h"

Cylinder::Cylinder(double LEN, double R) //定义带参数的构造函数
{
	len=LEN;  //对对象进行赋值
	r=R;
}

double Cylinder::Area()  //定义计算表面积的函数
{
	return(2*3.14*r*len+2*3.14*r*r);
}

double Cylinder::Volume() //定义计算体积的函数
{
	return(3.14*r*r*len);
}