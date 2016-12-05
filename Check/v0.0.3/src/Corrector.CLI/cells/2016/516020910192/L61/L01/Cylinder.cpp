#include "Cylinder.h"
#include<iostream>
Cylinder::Cylinder(double Len, double R)
{
	this->len=Len;
	this->r=R;
 }
double Cylinder::Area()//求表面积函数
{
	return(2*3.14*r*r+len*2*3.14*r);
	
}
double Cylinder::Volume()//求体积函数
{
	return(3.14*r*r*len);
}
	