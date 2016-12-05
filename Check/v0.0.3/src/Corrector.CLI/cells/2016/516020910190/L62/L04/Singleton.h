#pragma once
class Singleton
{
private:
	Singleton();//声明私有构造函数
	~Singleton();//声明私有析构函数
	static Singleton*instance;//私有静态成员
public:
	static Singleton*GetInstance();//公共函数
};

