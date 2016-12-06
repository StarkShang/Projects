/*����һ��Cylinder�࣬������Ա����:��(Len)���뾶(R)���Լ���������������ĳ�Ա������
���һ�������������ع��캯����ʵ�ֶԳ�Ա�������Ͱ뾶�ĳ�ʼ����
���������ж��������Ķ��󣬲��ô������Ĺ��캯����ʼ�������ó�Ա���������������������
 */

#include <cmath>
#include "Cylinder.h"

Cylinder::Cylinder(double len, double r)//��ʼ������
{
	this->r=r;
	this->len=len;
}

double Cylinder::Area()//�����������
{
	double a;
	a=2*3.14*pow(r,2)+len*2*3.14*r;//�������
	return a;//�������ֵ
}

double Cylinder::Volume()//�����������
{
	double v;
	v=3.14*len*pow(r,2);//�������
	return v;//�������ֵ
}
