#include"Cylinder.h" 

double Cylinder::Volume()
 {
 return 3.14*r*r*len;//计算体积
 }
Cylinder::Cylinder(double len, double r)//构造函数
{
	 
	this->len=len;
	this->r=r;
}
double Cylinder::Area ()
{
	return (2*3.14*r*r+2*3.14*r*len);//计算表面积
}
