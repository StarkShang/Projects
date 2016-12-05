#include"Cylinder.h"//对类的声明

Cylinder::Cylinder(double len, double r):len(len),r(r){};//实现构造函数对类中高度半径初始化
	double Cylinder::Area()//实现公式计算圆柱表面积并返回
{
	return(3.14*2*r*r+2*3.14*r*len);
}
	double Cylinder::Volume()//公式计算圆柱体积并返回
{
	return(3.14*r*r*len);
}