#include "Cylinder.h"
	Cylinder::Cylinder(double len, double r)//����Cylinder��������ʼ��len��r
 {
	len=len;
	r=r;
 }
	double Cylinder::Area()
	{
		return(3.1415925*r*2*(r+len));//����Area����������Բ���ı���� 
	}
	double Cylinder::Volume()
	{
		return(3.1415926*r*r*len);//����Volume����������Բ�������
	}


	