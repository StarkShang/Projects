#include  "Cylinder.h";//����cylinderͷ�ļ�����
Cylinder::Cylinder(double len,double r)//���ع��캯��
{
	this->len=len;//��thisָ���len��r��ʼ��
	this->r=r;
}
double Cylinder::Area()//���������ĺ���
{
	double s;//�������
	s=6.28*r*r+6.28*r*len;//����������ʽ
	return(s);
}
 double Cylinder::Volume()//��������ĺ���
 {
	 double v;//�������
	 v=3.14*r*r*len;//���������ʽ
	 return(v);
 }

