#include "Cylinder.h"
Cylinder::Cylinder(double Len, double R)//
{//
	this->len = Len;//赋值
	this->r = R;//赋值
}//
double Cylinder::Area()//定义函数
{//
	double S ;//定义表面积
	S = 2 * 3.14*r*r + len * 2 * 3.14*r;//计算
	return S;//返回表面积
}//
double Cylinder::Volume()//定义函数
{//
	return(3.14*r*r*len);//计算体积
}//