#include"String.h"
String::String(char* str)//赋值构造函数
{
	int i = 0;//
	for (; *(str + i) != '\0'; i++)//判断长度
	{//

	}//
	count = i+1;//
	capacity = i + 2;//
	content = new char[capacity];//创建数组
	for (int j=0; *(str + j) != '\0'; j++)//循环
	{//
		*(content + j) = *(str + j);//给数组成员赋值
	}//
}
String::String(const String&str)//拷贝构造函数
{
	this->count =count;//拷贝count
	this->capacity =  capacity;//拷贝capacity
	this->content = new char[capacity];//创建数组
	for (int j = 0;j<count; j++)//循环
	{
		*(this->content + j) = *(content + j);//拷贝数组成员
	}

}
String::~String()//析构函数
{
	delete[] content;//删除数组
}
char*String::GetCString()//转换函数
{
	content[count] = '\0';//添加字符
	return content;//返还首项指针
}