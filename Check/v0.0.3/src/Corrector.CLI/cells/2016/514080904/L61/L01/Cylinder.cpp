#include "Cylinder.h"

const int PI=3.14;//����main�������Լ�.h�ļ��о�����Ϊdouble�ͣ���˴˴�piȡ3.14��ȡ3û��ʲô����
Cylinder::Cylinder(double len, double r)//��ֵ
{
	this->len=len;
	this->r=r;
}
double Cylinder::Area()//��������
{
	return PI*r*r*2+2*PI*r*len;
}
double Cylinder::Volume()//�������
{
	return PI*r*r*len;
}