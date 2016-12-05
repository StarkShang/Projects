#include <iostream>
#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)                                        //定义函数Cylinder
{
	this->len = len;
	this->r = r;                                                                //初始化len，r
}
double Cylinder::Area()                                                        //定义计算表面积的函数
{
	double pi = 3.1415926;
	return (2 * this->r*this->r*pi + 2 * this->r*pi  * this->len);            //返回表面积
}
double Cylinder::Volume()                                                      //定义计算体积的函数
{
	double pi = 3.1415926;
	return (this->r*this->r*pi*this->len);                                    //返回体积
}