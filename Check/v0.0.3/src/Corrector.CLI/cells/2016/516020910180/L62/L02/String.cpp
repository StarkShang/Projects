#include"String.h"
String::String(char* str)
{
	count=0;
	while(str[count]!='\0')//计数器
		count++;
	capacity=count+1;
	content=new char[capacity];//分配新内存
	for(int i=0;i<count;i++)//拷贝字符串
		content[i]=str[i];
}

String::String(const String&str)//复制一个字符串
{
	count=str.count;
	capacity=str.capacity;
	content=new char[capacity];//分配内存
	for(int i=0;i<count;i++)//拷贝字符串
		content[i]=str.content[i];
}

String::~String()
{
	delete [] content;//释放内存
}

char* String::GetCString()
{
	content[capacity]='\0';//返回此字符串
	return content;
}