#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)
{
this->len=len;
this->r=r;
}//��ֵ

double Cylinder::Area()
{return 6.28*r*(r+len);}//�������

double Cylinder::Volume()
{return 3.14*r*r*len;}//�������