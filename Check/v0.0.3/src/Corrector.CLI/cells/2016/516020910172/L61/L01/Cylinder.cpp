#include  "Cylinder.h";//引入cylinder头文件声明
Cylinder::Cylinder(double len,double r)//重载构造函数
{
	this->len=len;//用this指针对len和r初始化
	this->r=r;
}
double Cylinder::Area()//计算表面积的函数
{
	double s;//定义变量
	s=6.28*r*r+6.28*r*len;//计算表面积公式
	return(s);
}
 double Cylinder::Volume()//计算体积的函数
 {
	 double v;//定义变量
	 v=3.14*r*r*len;//计算体积公式
	 return(v);
 }

