#include"Cylinder.h" 

double Cylinder::Volume()
 {
 return 3.14*r*r*len;//�������
 }
Cylinder::Cylinder(double len, double r)//���캯��
{
	 
	this->len=len;
	this->r=r;
}
double Cylinder::Area ()
{
	return (2*3.14*r*r+2*3.14*r*len);//��������
}
