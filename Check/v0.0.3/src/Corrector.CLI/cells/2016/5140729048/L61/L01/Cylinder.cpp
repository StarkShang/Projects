#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)
{
this->len=len;
this->r=r;
}//赋值

double Cylinder::Area()
{return 6.28*r*(r+len);}//计算面积

double Cylinder::Volume()
{return 3.14*r*r*len;}//计算体积