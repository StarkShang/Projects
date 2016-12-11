#include "String.h"


int len(char* str)//利用len函数获取字符串的长度并返回
{
	for(int i=0; ;i++)
	{
		if (str[i]=='\0')
			return i;
	}
}

String::String(char* str)
{
	capacity = count = len(str);//capacity和count都用于记录字符串长度
	content = new char[capacity + 1];//多留出一份空间 为\0
	for(int i=0; i<count ;i++)//初始化
	{
		content[i] = str[i];
	}
}
String::String(const String &str)
{
	count = str.count;
	capacity = count;
	content = new char[capacity + 1];
	for(int i=0; i<count ;i++)
	{
		content[i] = str.content[i];
	}
}
String::~String()
{
	delete []content;
}
char* String::GetCString()
{
	content[capacity] = '\0';//此时将\0加上即可
	return content;
}