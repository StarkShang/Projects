#include "Cylinder.h"
#include<iostream>
Cylinder::Cylinder(double Len, double R)
{
	this->len=Len;
	this->r=R;
 }
double Cylinder::Area()//����������
{
	return(2*3.14*r*r+len*2*3.14*r);
	
}
double Cylinder::Volume()//���������
{
	return(3.14*r*r*len);
}
	