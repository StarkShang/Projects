#include"Singleton.h"
#include<iostream>//包含指定头文件

Singleton*Singleton::instance=NULL;//instance初始化
Singleton::Singleton()
{}//定义构造函数
Singleton::~Singleton()
{
	delete[]instance;
}//定义析构函数
Singleton*Singleton::GetInstance()
{
	if(instance==NULL) instance=new Singleton();
	return instance;}//定义getinstance函数获得instance的值