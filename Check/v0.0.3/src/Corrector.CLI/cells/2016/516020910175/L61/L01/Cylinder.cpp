#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)//���캯�����Ѳ������ȣ��뾶��������
{
	this->len=len;
	this->r=r;
}
double Cylinder::Area()//����������������ı����
{
	return 2*3.14*r*len+2*3.14*r*r;
}
double Cylinder::Volume()//��������������������
{
	return 3.14*r*r*len;
}