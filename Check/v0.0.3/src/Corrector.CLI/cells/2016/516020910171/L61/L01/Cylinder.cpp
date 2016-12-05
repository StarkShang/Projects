/*定义一个Cylinder类，包括成员变量:长(Len)、半径(R)，以及计算表面积、体积的成员函数。
添加一个带参数的重载构造函数，实现对成员变量长和半径的初始化。
在主函数中定义这个类的对象，并用带参数的构造函数初始化，调用成员函数输出对象面积和体积。
 */

#include <cmath>
#include "Cylinder.h"

Cylinder::Cylinder(double len, double r)//初始化变量
{
	this->r=r;
	this->len=len;
}

double Cylinder::Area()//计算面积函数
{
	double a;
	a=2*3.14*pow(r,2)+len*2*3.14*r;//计算面积
	return a;//返回面积值
}

double Cylinder::Volume()//计算体积函数
{
	double v;
	v=3.14*len*pow(r,2);//计算体积
	return v;//返回体积值
}
