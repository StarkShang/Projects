#include "Singleton.h"
#include <iostream>

Singleton* Singleton::instance = NULL;//初始化instance指针在没有调用时为NULL
Singleton::Singleton()
{}
Singleton::~Singleton()
{
	delete []instance;//释放空间
}
Singleton* Singleton::GetInstance()
{
	if(instance == NULL) instance = new Singleton();//第一次调用时获取地址，否则直接返回instance指针
	return instance;
}