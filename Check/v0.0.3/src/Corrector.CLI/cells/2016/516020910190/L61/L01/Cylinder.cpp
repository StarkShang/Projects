#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)
{
	this->len=len;
	this->r=r;//��ʼ���뾶�ͳ���
}
double pi=3.1415927;
double Cylinder::Area()
{   
	double s;
	s=2*pi*r*r+2*pi*r*len;//��Բ�������
	return s;
}
double Cylinder::Volume()
{
	double V;
	V=pi*r*r*len;//��Բ�����
	return V;
}
