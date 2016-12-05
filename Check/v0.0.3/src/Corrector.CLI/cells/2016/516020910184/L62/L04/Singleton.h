#pragma once
class Singleton
{
private://声明私有类构造函数，析构函数，静态成员instance
	Singleton();
	~Singleton();
	static Singleton *instance;
public://声明公有类静态成员函数 GentInstance
	static Singleton *GetInstance();
};


