#include "Cylinder.h"

Cylinder::Cylinder(double LEN, double R) //����������Ĺ��캯��
{
	len=LEN;  //�Զ�����и�ֵ
	r=R;
}

double Cylinder::Area()  //������������ĺ���
{
	return(2*3.14*r*len+2*3.14*r*r);
}

double Cylinder::Volume() //�����������ĺ���
{
	return(3.14*r*r*len);
}