#include"Singleton.h"
Singleton::Singleton()//ʵ��˽���๹�캯��
{
}
Singleton::~Singleton()//˽������������
{
	delete [] instance;
}
Singleton *Singleton::GetInstance()//ʵ�ֹ����ྲ̬��Ա���� GentInstance��
{
	if(instance == nullptr)//���instance��ַΪ��
		instance = new Singleton;//Ϊinstance���䶯̬�ռ�
	return instance;//����instance�׵�ַ
}
Singleton * Singleton::instance =new Singleton;//��ʼ����̬��Աinstance
