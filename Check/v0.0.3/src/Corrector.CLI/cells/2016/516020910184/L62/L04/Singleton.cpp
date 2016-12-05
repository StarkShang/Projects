#include"Singleton.h"
Singleton::Singleton()//实现私有类构造函数
{
}
Singleton::~Singleton()//私有类析构函数
{
	delete [] instance;
}
Singleton *Singleton::GetInstance()//实现公有类静态成员函数 GentInstance，
{
	if(instance == nullptr)//如果instance地址为空
		instance = new Singleton;//为instance分配动态空间
	return instance;//返回instance首地址
}
Singleton * Singleton::instance =new Singleton;//初始化静态成员instance
