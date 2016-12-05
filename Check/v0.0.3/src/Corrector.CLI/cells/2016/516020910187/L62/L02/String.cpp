#include "String.h"
#include <iostream>
String::String(char* str)
{
	count = strlen(str);//调用strlen函数计算字符串长度
	capacity = 4*count;
	content = new char[capacity];//开辟空间
	for (int i = 0; i < count; i++)//赋值
	{
		content[i] = str[i];
	}
}
String::String(const String& str)
{
	this->capacity = str.capacity; //运用this指针
	this->count = str.count; 
	content = new char[capacity];
	for (int j = 0; j < count; j++) //赋值
	{
		this->content[j] = str.content[j];
	}
}
String::~String()
{
	delete content;
}
char* String::GetCString()
{
	content[count+1] = '\0';//最后一项'\0'
	return content;
}