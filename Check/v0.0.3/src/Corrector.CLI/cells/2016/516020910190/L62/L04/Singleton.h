#pragma once
class Singleton
{
private:
	Singleton();//����˽�й��캯��
	~Singleton();//����˽����������
	static Singleton*instance;//˽�о�̬��Ա
public:
	static Singleton*GetInstance();//��������
};

