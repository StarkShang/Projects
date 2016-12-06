#include <iostream>
#include "Cylinder.h"
Cylinder::Cylinder(double len, double r)                                        //���庯��Cylinder
{
	this->len = len;
	this->r = r;                                                                //��ʼ��len��r
}
double Cylinder::Area()                                                        //������������ĺ���
{
	double pi = 3.1415926;
	return (2 * this->r*this->r*pi + 2 * this->r*pi  * this->len);            //���ر����
}
double Cylinder::Volume()                                                      //�����������ĺ���
{
	double pi = 3.1415926;
	return (this->r*this->r*pi*this->len);                                    //�������
}