#include"Singleton.h"
#include<stdio.h>
Singleton*Singleton::instance=NULL;//初始化静态变量
Singleton::Singleton()
{
	}//构造函数
Singleton*Singleton::GetInstance()
{
	if(instance==NULL)
	{
		instance=new Singleton;//第一次使用分配空间
		return instance;
	}
	else
	return instance;//返回instance
}
Singleton::~Singleton()
{
	delete instance;//释放空间
}

