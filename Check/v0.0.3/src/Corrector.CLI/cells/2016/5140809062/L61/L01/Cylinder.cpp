#include "Cylinder.h"
Cylinder::Cylinder(double len,double r)//���幹�캯������Բ����ĳ���뾶Ϊ��ֵ
 {
	 this->len=len;
	 this->r=r;
 }
double Cylinder ::Area()//����������ĺ���������Բ�����
{ return 3.1415926*r*r;
}

double Cylinder ::Volume()//����������ĺ���������Բ�����
{return (3.1415926*r*r*len);
}