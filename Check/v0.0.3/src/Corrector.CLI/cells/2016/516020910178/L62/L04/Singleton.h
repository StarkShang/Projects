#pragma once
class Singleton
{
private://����˽���๹�캯����������������̬��Աinstance
	Singleton();
	~Singleton();
	static Singleton *instance;
public://���������ྲ̬��Ա���� GentInstance
	static Singleton *GetInstance();
};


