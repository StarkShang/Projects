#include "Cylinder.h"
Cylinder::Cylinder(double Len, double R)//
{//
	this->len = Len;//��ֵ
	this->r = R;//��ֵ
}//
double Cylinder::Area()//���庯��
{//
	double S ;//��������
	S = 2 * 3.14*r*r + len * 2 * 3.14*r;//����
	return S;//���ر����
}//
double Cylinder::Volume()//���庯��
{//
	return(3.14*r*r*len);//�������
}//