#include "Cylinder.h"
 Cylinder::Cylinder(double len, double r)  //��Ա����
 { 
	 this->len=len;      //�Գ�Ա������len��ʼ��
     this->r=r;            //�Գ�Ա�����뾶r��ʼ��
 }
 double Cylinder::Area()    //��Ա����
 {
	 double s;
	 s=2*3.14*r*len+3.14*r*r;  //���� Cylinder�����
	 return s;                  //���ر����
 }
 double Cylinder::Volume()     //��Ա����
 {
	 double v;
	 v=3.14*r*r*len;      //���� Cylinder���
	 return v;           //�������
 }