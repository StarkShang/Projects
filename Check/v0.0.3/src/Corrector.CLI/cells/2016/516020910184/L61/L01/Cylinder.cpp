#include"Cylinder.h"//���������

Cylinder::Cylinder(double len, double r):len(len),r(r){};//ʵ�ֹ��캯�������и߶Ȱ뾶��ʼ��
	double Cylinder::Area()//ʵ�ֹ�ʽ����Բ�������������
{
	return(3.14*2*r*r+2*3.14*r*len);
}
	double Cylinder::Volume()//��ʽ����Բ�����������
{
	return(3.14*r*r*len);
}