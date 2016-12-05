#include "String.h"

String::String(char* str) //定义赋值构造函数
{
	content=new char; //为content变new出内存空间
	int i=0;
	while(str[i]!='\0')
	{
		content[i]=str[i]; //对相应成员赋值
		count=i+1; //成员变量count值
		i++;
	}
}

String::String(const String& str)//定义拷贝构造函数
{
	content=new char; //new出内存空间

	content=str.content;//进行拷贝
}

String::~String()//定义析构函数
{
	delete content; //释放content所占空间
}

char*String:: GetCString() //定义函数
{
	content[count]='\0'; //确保content以'\0'结尾
	return content; //函数返回content
	
}