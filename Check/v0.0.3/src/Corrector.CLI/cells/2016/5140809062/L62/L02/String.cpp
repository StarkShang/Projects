#include "String.h"

String::String(char* str)//构造函数，为响应成员变量赋值，并且为CONTENT变量NEW出新空间
{	
	int i;

	for ( i=0;str[i]!='\0';i++)
	{
	}

	count=i+1;
	capacity=i+2;


	content=new char[capacity];
	for (i=0;i<count;i++)
		content[i]=str[i];

}
String::String(const String& str)//构造函数，由类STR为响应成员变量赋值，并且为CONTENT变量NEW出新空间
{
	content=new char[str.capacity];
	for (int i=0;i<str.count;i++)
		content[i]=str.content[i];

	capacity=str.capacity;
	count=str.count;
}
String::~String()//析构函数
{delete content;
}

char* String::GetCString()//显示函数
{
	return content;
}