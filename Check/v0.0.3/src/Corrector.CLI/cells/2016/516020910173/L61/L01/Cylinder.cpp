#include"Cylinder.h"
double Cylinder::Area()
{
	double s;//�������s
	s=r*r*3.14+2*len*3.14*r;//��������
	return s;//���غ���ֵ
}
double Cylinder::Volume()
{
	double v;//�������v
	v=r*r*3.14*len;//�������
	return v;//���غ���ֵ
}
Cylinder::Cylinder(double len,double r)
{
	this->len=len;
	this->r=r;
}