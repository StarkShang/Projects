#include"Singleton.h"
#include<stdio.h>
Singleton*Singleton::instance=NULL;//��ʼ����̬����
Singleton::Singleton()
{
	}//���캯��
Singleton*Singleton::GetInstance()
{
	if(instance==NULL)
	{
		instance=new Singleton;//��һ��ʹ�÷���ռ�
		return instance;
	}
	else
	return instance;//����instance
}
Singleton::~Singleton()
{
	delete instance;//�ͷſռ�
}

