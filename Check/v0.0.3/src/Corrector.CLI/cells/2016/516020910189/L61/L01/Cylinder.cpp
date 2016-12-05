#include"Cylinder.h"

	Cylinder::Cylinder(double len, double r) //public构造函数，参数为长度与半径
	{
		this->len = len;//带参数初始化len长度
		this->r = r;//带参数初始化r半径
	}
	double Cylinder:: Area()  //计算圆柱体表面积
	{
		double area = 2 * 3.14*r*len + 2 * 3.14*r*r;
		return area;
	}
	double Cylinder::Volume()//计算圆柱体体积
	{
		double volume = len*3.14*r*r;
		return volume;
	}