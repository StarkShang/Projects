#include <iostream>
#include"String.h"
String::String(char* str)                                   //根据char*字符串str创建String类的对象
{
	int i = 0;
	for (i = 0; i < 1025; i++)                              //查找字符串长度
	{
		if (str[i] == '\0') { break; }
	}
	count = i;                                             //赋值字符串长度
	capacity = count * 4;                                  //赋值内存空间大小
	content = new char[capacity];                          //开辟内存空间
	for (int j = 0; j < count; j++)                        //给相应的成员赋值
	{
		content[j] = str[j];
	}
}

String::String(const String& str)
{
	this->capacity = str.capacity;                          //获取内存空间大小
	this->count = str.count;                                //获取字符串长度
	content = new char[capacity];                           //开辟内存空间
	for (int j = 0; j < count; j++)                         //给相应的成员赋值
	{
		this->content[j] = str.content[j];
	}
}

String::~String()
{
	delete content;                                        //释放内存空间
}

char* String::GetCString()
{
	content[count] = '\0';                                //将其转成C风格的字符串
	return content;                                       //返回content首地址
}