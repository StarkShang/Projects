//����һ��Cylinder�࣬������Ա����:��(Len)���뾶(R)���Լ���������������ĳ�Ա������
//���һ�������������ع��캯����ʵ�ֶԳ�Ա�������Ͱ뾶�ĳ�ʼ����
//���������ж��������Ķ��󣬲��ô������Ĺ��캯����ʼ�������ó�Ա���������������������
#include "Cylinder.h"
#include<iostream>
Cylinder::Cylinder(double Len, double R)
{
	this->len=Len;
	this->r=R;
 }
double Cylinder::Area()
{
	return(2*3.14*r*r+len*2*3.14*r);
	
}
double Cylinder::Volume()
{
	return(3.14*r*r*len);
}
	
