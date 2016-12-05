//定义一个Cylinder类，包括成员变量:长(Len)、半径(R)，以及计算表面积、体积的成员函数。
//添加一个带参数的重载构造函数，实现对成员变量长和半径的初始化。
//在主函数中定义这个类的对象，并用带参数的构造函数初始化，调用成员函数输出对象面积和体积。
#include "Cylinder.h"
#include<iostream>
Cylinder::Cylinder(double Len, double R)
{
	this->len=Len;
	this->r=R;
 }
double Cylinder::Area()
{
	return(2*3.14*r*r+len*2*3.14*r);
	
}
double Cylinder::Volume()
{
	return(3.14*r*r*len);
}
	
