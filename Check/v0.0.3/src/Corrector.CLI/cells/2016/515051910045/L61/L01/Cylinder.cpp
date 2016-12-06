#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)//����Cylinder��������ʼ��len��r
{
	this->len=len;
	this->r=r;
}
double Cylinder::Area()   //����Area����������Բ���ı����
{   
	double s;
	s=3.1415925*r*2*(r+len);
	return(s);
}
double Cylinder::Volume () //����Volume����������Բ�������
{
	double V;
	V=3.1415926*r*r*len;
	return V;
}