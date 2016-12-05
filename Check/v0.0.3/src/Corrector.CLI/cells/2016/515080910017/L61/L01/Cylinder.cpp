#include "Cylinder.h"
	Cylinder::Cylinder(double len, double r)//定义Cylinder函数来初始化len与r
 {
	len=len;
	r=r;
 }
	double Cylinder::Area()
	{
		return(3.1415925*r*2*(r+len));//定义Area函数来计算圆柱的表面积 
	}
	double Cylinder::Volume()
	{
		return(3.1415926*r*r*len);//定义Volume函数来计算圆柱的体积
	}


	