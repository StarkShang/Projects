#include"Cylinder.h"
Cylinder::Cylinder(double len, double r)
{ this->len =len;
  this->r=r;
}//��ʼ������
double Cylinder::Area()
	{
		double a;
		a=3.14*r*r*2+2*3.14*r*len;
		return a;
	}//��������
double Cylinder::Volume()
	{
		double v;
		v=3.14*len*r*r*r;
		return v;
	}//�������