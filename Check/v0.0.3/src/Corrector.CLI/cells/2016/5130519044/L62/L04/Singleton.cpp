#include "Singleton.h"
#include <iostream>

Singleton* Singleton::instance = NULL;//��ʼ��instanceָ����û�е���ʱΪNULL
Singleton::Singleton()
{}
Singleton::~Singleton()
{
	delete []instance;//�ͷſռ�
}
Singleton* Singleton::GetInstance()
{
	if(instance == NULL) instance = new Singleton();//��һ�ε���ʱ��ȡ��ַ������ֱ�ӷ���instanceָ��
	return instance;
}