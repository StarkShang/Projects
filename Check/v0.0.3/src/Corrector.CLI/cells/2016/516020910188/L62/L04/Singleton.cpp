#include"Singleton.h"
#include<iostream>//����ָ��ͷ�ļ�

Singleton*Singleton::instance=NULL;//instance��ʼ��
Singleton::Singleton()
{}//���幹�캯��
Singleton::~Singleton()
{
	delete[]instance;
}//������������
Singleton*Singleton::GetInstance()
{
	if(instance==NULL) instance=new Singleton();
	return instance;}//����getinstance�������instance��ֵ