#include"Cylinder.h"

	Cylinder::Cylinder(double len, double r) //public���캯��������Ϊ������뾶
	{
		this->len = len;//��������ʼ��len����
		this->r = r;//��������ʼ��r�뾶
	}
	double Cylinder:: Area()  //����Բ��������
	{
		double area = 2 * 3.14*r*len + 2 * 3.14*r*r;
		return area;
	}
	double Cylinder::Volume()//����Բ�������
	{
		double volume = len*3.14*r*r;
		return volume;
	}