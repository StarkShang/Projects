#include"Tree.h";//����ͷ�ļ��������
Tree::Tree(int age)//���غ�����age��ʼ��
{
	this->age=age;
}
 void Tree::Grow(int years)//�Գ�Ա����age����year
 {
	 age=age+years;//�����µ�age
 }
 int Tree::ShowAge()//��ʾprivate�ڵ�age
 {
	 int a;
	 a=age;
	 return(a);
 }